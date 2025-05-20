//Mejorar el ejemplo del “juego_de_ordenar_las_letras” de la clase sobre String y Arreglos agregándole un sistema de puntaje. 
//Hacer que el puntaje varíe según la cantidad de letras de la palabra que hay que adivinar. 
//También hacer que se vayan restando puntos cada vez que se utilice la ayuda para tener una pista.
/*************************************************************************\

 Juego de Ordenar las Letras

 El sistema muestra la palabra desordenada y el jugador tiene que

 deducirla. Con la palabra "ayuda" el sistema da una pista.

\*************************************************************************/



#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int puntaje = laPalabra.length();
cout << "La palabra desordenada es: " << palabraDesordenada << " (Puntaje inicial: " << puntaje << ")" << endl;
// Constantes enumeradas:
// La primer columna tiene la palabra para adivinar.
// La segunda columna tiene la pista.
// El tercer valor guarda la cantidad de columnas (2).
// Recordar que esto sería equivalente a usar tres constantes:
// const int PALABRA = 0;
// const int AYUDA = 1;
// const int CANTIDAD_COLUMNAS = 2;

enum columnas
{

  PALABRA,

  AYUDA,

  CANTIDAD_COLUMNAS

};

const int CANTIDAD_PALABRAS = 5;
// Matriz de 5 filas por 2 columnas PALABRAS[5][2]
string PALABRAS[CANTIDAD_PALABRAS][CANTIDAD_COLUMNAS] =

{

  {"pared", "¿Sentís como si te estuvieses dando la cabeza contra algo?"},

  {"anteojos", "Pueden ayudarte a ver la solución."},

  {"aburrido", "Un juego no debería serlo."},

  {"perseverar", "Importante para triunfar."},

  {"ordenar", "Es de lo que se trata el juego."}

};

int main()
{

  srand(time(0));

  int eleccion = (rand() % CANTIDAD_PALABRAS);
  // Obtiene de la matriz la palabra que hay que adivinar.
  // La posición es fila 'eleccion' y columna 0 [ PALABRA ].
  string laPalabra = PALABRAS[eleccion][PALABRA];
  // La ayuda para adivinar la palabra está en la posición fila
  // 'eleccion' y columna 1 [ AYUDA ].
  string laAyuda = PALABRAS[eleccion][AYUDA];
  // Guardamos la palabra que luego vamos a desordenar.
  string palabraDesordenada = laPalabra;
  int cantidadCaracteresPalabra = palabraDesordenada.size();
  // Desordenamos la palabra intercambiando de a dos caracteres
  for (int i = 0; i < cantidadCaracteresPalabra; i++)
  {
    // Elegimos dos posiciones de caracteres al azar.
    int index1 = (rand() % cantidadCaracteresPalabra);
    int index2 = (rand() % cantidadCaracteresPalabra);
    // Guardamos el primer caracter en una variable temporal.
    char auxiliar = palabraDesordenada[index1];
    // Guardamos el segundo caracter en el lugar del primero.
    palabraDesordenada[index1] = palabraDesordenada[index2];
    // Guardamos el primer caracter en el lugar del segundo.
    palabraDesordenada[index2] = auxiliar;
  }
  cout << "\t\t\tBienvenido al juego del orden!\n\n"
  cout << "Descubre la palabra formada por las letras desordenadas.\n";
  cout << "Escribe 'ayuda' para obtener una pista.\n";
  cout << "Escribe 'salir' para salir del juego.\n\n";
  cout << "La palabra desordenada es: " << palabraDesordenada << endl;
  string solucion;
  // Creamos una variable booleana para testear cuando hay que salir del
  // ciclo.
  bool salir = false;
  // Podemos escribir: la palabra, ayuda o salir.
  int puntaje = laPalabra.length();
  //puntaje
  while (!salir)
  {
    cout << "\nTu solución: ";
    cin >> solucion;
    if (solucion == laPalabra)
    {
      cout << "\nEso es! Lo resolviste!\n"<< "puntos obtenidos"<< puntaje <<endl;
      salir = true;
    }
    else if (solucion == "ayuda")
    {
      if (puntaje > 0) {
            puntaje--; // Restamos un punto por pedir ayuda
            cout << laAyuda << " (Puntaje actual: " << puntaje << ")" << endl;
        } else {
            cout << "Ya no tienes puntos para pedir ayuda." << endl;
        } 
      cout << laAyuda << "punto restantes:"<< puntaje <<endl;
    }

    else if (solucion == "salir")

    {

      salir = true;

    }

    else

    {

      cout << "Lo lamento pero no es la solución.\n";

    }

  }

  cout << "\nGracias por jugar.\n";

  cout << endl;

  return 0;

}
