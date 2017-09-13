//Semestre 2018 - 1
//************************************************************//
//************************************************************//
//************** Alumno (s): González Colín Fernando    ****//
//*************	 Ejercicio de clase, práctica 5         ****//
//*************											******//
//************************************************************//
/*
Teclas para mover la mano/brazo

R,r	-> Hombro
F,f	-> Codo
T,t -> Muñeca
G,g -> Pulgar1
Y,y	-> Pulgar2
H,h	-> Indice1
U,u	-> Indice2
J,j	-> Indice3
I,i	-> Medio1
K.k	-> Medio2
O,o	-> Medio3
L,l	-> Anular1
P,p	-> Anular2
Z,z	-> Anular3
X,x	-> Meñique1
C,c	-> Meñique2
V,v	-> Meñique3

Mayusculas movimiento positivo
Minusculas movimiento negativo

*/
#include "Main.h"

float transZ = -5.0f;
float transX = 0.0f;
float transY = 0.0f;
float angleX = 0.0f;
float angleY = 0.0f;
float angH = 0.0f;
float angC = 0.0f;
float angM = 0.0f;
float angP = 0.0f;
float angP2 = 0.0f;
float angI = 0.0f;
float angI2 = 0.0f;
float angI3 = 0.0f;
float angMe = 0.0f;
float angMe2 = 0.0f;
float angMe3 = 0.0f;
float angA = 0.0f;
float angA2 = 0.0f;
float angA3 = 0.0f;
float angCh = 0.0f;
float angCh2 = 0.0f;
float angCh3 = 0.0f;
int screenW = 0.0;
int screenH = 0.0;


GLfloat Position[]= { 0.0f, 3.0f, 0.0f, 1.0f };			// Light Position
GLfloat Position2[]= { 0.0f, 0.0f, -5.0f, 1.0f };			// Light Position

void InitGL ( void )     // Inicializamos parametros
{

	glShadeModel(GL_SMOOTH);							// Habilitamos Smooth Shading
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo
	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing

	//Configuracion luz
	glLightfv(GL_LIGHT0, GL_POSITION, Position);
	glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, Position2);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);


	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glEnable ( GL_COLOR_MATERIAL );
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void prisma(void)
{
	GLfloat vertice [8][3] = {
				{0.5 ,-0.5, 0.5},    //Coordenadas Vértice 0 V0
				{-0.5 ,-0.5, 0.5},    //Coordenadas Vértice 1 V1
				{-0.5 ,-0.5, -0.5},    //Coordenadas Vértice 2 V2
				{0.5 ,-0.5, -0.5},    //Coordenadas Vértice 3 V3
				{0.5 ,0.5, 0.5},    //Coordenadas Vértice 4 V4
				{0.5 ,0.5, -0.5},    //Coordenadas Vértice 5 V5
				{-0.5 ,0.5, -0.5},    //Coordenadas Vértice 6 V6
				{-0.5 ,0.5, 0.5},    //Coordenadas Vértice 7 V7
				};

		glBegin(GL_POLYGON);	//Front
			glNormal3f( 0.0f, 0.0f, 1.0f);
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[4]);
			glVertex3fv(vertice[7]);
			glVertex3fv(vertice[1]);
		glEnd();

		glBegin(GL_POLYGON);	//Right
			glNormal3f( 1.0f, 0.0f, 0.0f);
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[3]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[4]);
		glEnd();

		glBegin(GL_POLYGON);	//Back
			glNormal3f( 0.0f, 0.0f, -1.0f);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[3]);
			glVertex3fv(vertice[2]);
		glEnd();

		glBegin(GL_POLYGON);  //Left
			glNormal3f( -1.0f, 0.0f, 0.0f);
			glVertex3fv(vertice[1]);
			glVertex3fv(vertice[7]);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[2]);
		glEnd();

		glBegin(GL_POLYGON);  //Bottom
			glNormal3f( 0.0f, -1.0f, 0.0f);
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[1]);
			glVertex3fv(vertice[2]);
			glVertex3fv(vertice[3]);
		glEnd();

		glBegin(GL_POLYGON);  //Top
			glNormal3f( 0.0f, 1.0f, 0.0f);
			glVertex3fv(vertice[4]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[7]);
		glEnd();
}

void display ( void )   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Limiamos pantalla y Depth Buffer
	//glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glTranslatef(transX, transY, transZ);
	glRotatef(angleY, 0.0, 1.0, 0.0);
	glRotatef(angleX, 1.0, 0.0, 0.0);
		//Poner Código Aquí.
		
	glPushMatrix(); //hombro >pivote
	glColor3f(1.0,0.0,0.0);
	glTranslatef(0.0, 3.0f, 0.0);
	glScalef(0.5,0.5,0.5);
	glRotatef(angH, 0.0, 0.0, 1.0);
	prisma();

		glPushMatrix(); //antebrazo
		glColor3f(0.0,1.0,0.0);
		glTranslatef(0.0, -1.5, 0.0);
		glScalef(1.0,2.0,1.0);
		prisma();
		glPopMatrix();

		glPushMatrix(); //codo >pivote
		glColor3f(0.0,0.0,1.0);
		glTranslatef(0.0, -3.0, 0.0);
		glScalef(1.0,1.0,1.0);
		glRotatef(angC, 0.0, 0.0, 1.0);
		prisma();

			glPushMatrix(); //brazo
			glColor3f(1.0,1.0,0.0);
			glTranslatef(1.5, 0.0f, 0.0);
			glScalef(2.0,1.0,1.0);
			prisma();
			glPopMatrix();

			glPushMatrix(); //muñeca >pivote
			glColor3f(1.0,0.0,1.0);
			glTranslatef(3.0, 0.0f, 0.0);
			glScalef(1.0,1.0,1.0);
			glRotatef(angM, 0.0, 1.0, 0.0);
			prisma();				
				glPushMatrix(); //pulgar >pivote
				glColor3f(1.0,0.0,0.0);
				glTranslatef(0.25, 0.375, 0.25);
				glRotatef(angP, 1.0, 0.0, 0.0);
				glTranslatef(0.0, 0.375, 0.0);
				glScalef(0.2,0.5,0.2);
				glRotatef(angP, 1.0, 0.0, 0.0);
				prisma();
					glPushMatrix(); //pulgar2
					glColor3f(0.0,1.0,0.0);
					glTranslatef(0.0, 0.5, 0.0);
					glRotatef(angP2, 1.0, 0.0, 0.0);
					glTranslatef(0.0, 0.5, 0.0);
					glScalef(1.0,1.0,1.0);						
					prisma();
					glPopMatrix();
				glPopMatrix();
				glPushMatrix(); //indice >pivote
				glColor3f(0.0,0.0,1.0);
				glTranslatef(0.375, 0.35, 0.25);
				glRotatef(angI, 0.0, 1.0, 0.0);
				glTranslatef(0.375, 0.0, 0.0);
				glScalef(0.5,0.2,0.2);				
				prisma();					
					glPushMatrix(); //indice 2>pivote
					glColor3f(0.8,0.0,0.0);
					glTranslatef(0.5, 0.0, 0.0);
					glRotatef(angI2, 0.0, 1.0, 0.0);
					glTranslatef(0.5, 0.0, 0.0);
					glScalef(1.0,1.0,1.0);					
					prisma();
						glPushMatrix(); //indice 3
						glColor3f(0.0,0.8,0.0);
						glTranslatef(0.5, 0.0, 0.0);
						glRotatef(angI3, 0.0, 1.0, 0.0);
						glTranslatef(0.5, 0.0, 0.0);
						glScalef(1.0,1.0,1.0);						
						prisma();
						glPopMatrix();
					glPopMatrix();					
				glPopMatrix();

				glPushMatrix(); //medio >pivote
				glColor3f(0.0,0.0,0.8);
				glTranslatef(0.375, 0.12, 0.25);
				glRotatef(angMe, 0.0, 1.0, 0.0);
				glTranslatef(0.375, 0.0, 0.0);
				glScalef(0.5,0.2,0.2);				
				prisma();					
					glPushMatrix(); //medio2 2>pivote
					glColor3f(0.6,0.0,0.0);
					glTranslatef(0.5, 0.0, 0.0);					
					glRotatef(angMe2, 0.0, 1.0, 0.0);
					glTranslatef(0.5, 0.0, 0.0);
					glScalef(1.0, 1.0, 1.0);
					prisma();
						glPushMatrix(); //medio 3
						glColor3f(0.0,0.6,0.0);
						glTranslatef(0.5, 0.0, 0.0);
						glRotatef(angMe3, 0.0, 1.0, 0.0);
						glTranslatef(0.5, 0.0, 0.0);
						glScalef(1.0,1.0,1.0);						
						prisma();
						glPopMatrix();
					glPopMatrix();					
				glPopMatrix();

				glPushMatrix(); //anular >pivote
				glColor3f(0.0,0.0,0.6);
				glTranslatef(0.375, -0.12, 0.25);
				glRotatef(angA, 0.0, 1.0, 0.0);
				glTranslatef(0.375, 0.0, 0.0);
				glScalef(0.5,0.2,0.2);				
				prisma();					
					glPushMatrix(); //anular2 2>pivote
					glColor3f(0.4,0.0,0.0);
					glTranslatef(0.5, 0.0, 0.0);
					glRotatef(angA2, 0.0, 1.0, 0.0);
					glTranslatef(0.5, 0.0, 0.0);
					glScalef(1.0,1.0,1.0);					
					prisma();
						glPushMatrix(); //anular 3
						glColor3f(0.0,0.4,0.0);
						glTranslatef(0.5, 0.0, 0.0);
						glRotatef(angA3, 0.0, 1.0, 0.0);
						glTranslatef(0.5, 0.0, 0.0);
						glScalef(1.0,1.0,1.0);						
						prisma();
						glPopMatrix();
					glPopMatrix();					
				glPopMatrix();

				glPushMatrix(); //meñique >pivote
				glColor3f(1.0,0.0,0.0);
				glTranslatef(0.375, -0.35, 0.25);
				glRotatef(angCh, 0.0, 1.0, 0.0);
				glTranslatef(0.375, 0.0, 0.0);
				glScalef(0.5,0.2,0.2);				
				prisma();					
					glPushMatrix(); //meñique 2>pivote
					glColor3f(0.0,1.0,1.0);
					glTranslatef(0.5, 0.0, 0.0);
					glRotatef(angCh2, 0.0, 1.0, 0.0);
					glTranslatef(0.5, 0.0, 0.0);
					glScalef(1.0,1.0,1.0);					
					prisma();
						glPushMatrix(); //meñique 3
						glColor3f(1.0,0.0,1.0);
						glTranslatef(0.5, 0.0, 0.0);
						glRotatef(angCh3, 0.0, 1.0, 0.0);
						glTranslatef(0.5, 0.0, 0.0);
						glScalef(1.0,1.0,1.0);						
						prisma();
						glPopMatrix();
					glPopMatrix();					
				glPopMatrix();
			glPopMatrix();
		glPopMatrix();	
	glPopMatrix();


	glutSwapBuffers ( );
  // Swap The Buffers
}

void reshape ( int width , int height )   // Creamos funcion Reshape
{
  if (height==0)										// Prevenir division entre cero
	{
		height=1;
	}

	glViewport(0,0,width,height);	

	glMatrixMode(GL_PROJECTION);						// Seleccionamos Projection Matrix
	glLoadIdentity();

	// Tipo de Vista
	//glOrtho(-5,5,-5,5,0.2,20);	
	glFrustum (-0.1, 0.1,-0.1, 0.1, 0.1, 50.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
	//glLoadIdentity();									
}

void keyboard ( unsigned char key, int x, int y )  // Create Keyboard Function
{
	switch ( key ) {
		case 'R':
			angH +=2.0f;
			break;
		case 'r':
			angH -=2.0f;
			break;
		case 'F':
			angC +=2.0f;
			break;
		case 'f':
			angC -=2.0f;
			break;
		case 'T':
			angM +=2.0f;
			break;
		case 't':
			angM -=2.0f;
			break;

		case 'G':
			angP +=2.0f;
			break;
		case 'g':
			angP -=2.0f;
			break;
		case 'Y':
			angP2 +=2.0f;
			break;
		case 'y':
			angP2 -=2.0f;
			break;
		case 'H':
			angI +=2.0f;
			break;
		case 'h':
			angI -=2.0f;
			break;
		case 'U':
			angI2 +=2.0f;
			break;
		case 'u':
			angI2 -=2.0f;
			break;
		case 'J':
			angI3 +=2.0f;
			break;
		case 'j':
			angI3 -=2.0f;
			break;
		case 'I':
			angMe +=2.0f;
			break;
		case 'i':
			angMe -=2.0f;
			break;
		case 'K':
			angMe2 +=2.0f;
			break;
		case 'k':
			angMe2 -=2.0f;
			break;
		case 'O':
			angMe3 +=2.0f;
			break;
		case 'o':
			angMe3 -=2.0f;
			break;
		case 'L':
			angA +=2.0f;
			break;
		case 'l':
			angA -=2.0f;
			break;

		case 'P':
			angA2 +=2.0f;
			break;
		case 'p':
			angA2 -=2.0f;
			break;
		case 'Z':
			angA3 +=2.0f;
			break;
		case 'z':
			angA3 -=2.0f;
			break;

		case 'X':
			angCh +=2.0f;
			break;
		case 'x':
			angCh -=2.0f;
			break;
		case 'C':
			angCh2 +=2.0f;
			break;
		case 'c':
			angCh2 -=2.0f;
			break;
		case 'V':
			angCh3 +=2.0f;
			break;
		case 'v':
			angCh3 -=2.0f;
			break;
		case 'w':
		case 'W':
			transZ +=0.2f;
			break;
		case 's':
		case 'S':
			transZ -=0.2f;
			break;
		case 'a':
		case 'A':
			transX -=0.2f;
			break;
		case 'd':
		case 'D':
			transX +=0.2f;
			break;
		case 'q':
		case 'Q':
			transY -= 0.2f;
			break;
		case 'e':
		case 'E':
			transY += 0.2f;
			break;
		case 27:        // Cuando Esc es presionado...
			exit ( 0 );   // Salimos del programa
		break;        
		default:        // Cualquier otra
		break;
  }
	glutPostRedisplay();
}

void arrow_keys ( int a_keys, int x, int y )  // Funcion para manejo de teclas especiales (arrow keys)
{
  switch ( a_keys ) {
    case GLUT_KEY_UP:		// Presionamos tecla ARRIBA...
		angleX +=2.0f;
		break;
    case GLUT_KEY_DOWN:		// Presionamos tecla ABAJO...
		angleX -=2.0f;
		break;
	case GLUT_KEY_LEFT:
		angleY +=2.0f;
		break;
	case GLUT_KEY_RIGHT:
		angleY -=2.0f;
		break;
    default:
      break;
  }
  glutPostRedisplay();
}


int main ( int argc, char** argv )   // Main Function
{
  glutInit            (&argc, argv); // Inicializamos OpenGL
  glutInitDisplayMode (GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
  screenW = glutGet(GLUT_SCREEN_WIDTH);
  screenH = glutGet(GLUT_SCREEN_HEIGHT);
  glutInitWindowSize  (500, 500);	// Tamaño de la Ventana
  glutInitWindowPosition (0, 0);	//Posicion de la Ventana
  glutCreateWindow    ("Practica 5"); // Nombre de la Ventana
  printf("Resolution H: %i \n", screenW);
  printf("Resolution V: %i \n", screenH);
  InitGL ();						// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut función de dibujo
  glutReshapeFunc     ( reshape );	//Indicamos a Glut función en caso de cambio de tamano
  glutKeyboardFunc    ( keyboard );	//Indicamos a Glut función de manejo de teclado
  glutSpecialFunc     ( arrow_keys );	//Otras
  glutMainLoop        ( );          // 

  return 0;
}


