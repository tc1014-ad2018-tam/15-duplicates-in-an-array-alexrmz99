/*  Este programa tiene el propósito de recibir cantidad n de números que el usuario proporcione
 *  y verificar si hay duplicados, y en caso de que sí haya, informarle al usuario.
 *  Nombre: Alejandro Ernesto Ramírez Michel
 *  Fecha: 14 de octubre del 2018
 */

#include <stdio.h>
#include <stdlib.h>

//funcion para comparar dos numeros
int Compare (const void * a, const void * b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    //variable para la cantidad de números que insertará
    int n;
    printf("How many numbers are you going to input? ");
    scanf("%i", &n);

    //variable de los números con la cantidad máxima dada por el usuario
    int nums[n];

    //aquí le pido al usuario que proporcione los números del array
    printf("Now give me the numbers you'd like: \n");
    for (int i=0; i<n; i++) {
        scanf("%i", &nums[i]);
    }
    printf("\n");

    printf("You gave me this numbers: ");
    for (int i=0; i<n; i++) {
        printf("\t%i", nums[i]);
    }
    printf("\n");

    //variables para repetidos
    int duplicados = 0;
    int conta = 0;
    int repetido;

    //función sorting para acomodar los números
    qsort(nums, n, sizeof(int), Compare);

    //ciclo para duplicados
    for (int i = 0; i < n; i += conta+1) {
        do {
            if (nums[i] == nums[i+conta+1]) {
                conta++;        // si el ciclo encuentra repetidos, se suma en variable conta
                repetido = 1;   //si encuentra repetidos, variable repetido es 1
            } else {
                repetido = 0;   //si no hay repetidos, variable repetido = 0
            }
        } while (repetido == 1);    //repetir el ciclo do while mientras siga habiendo numeros repetidos

        if (conta > 0) {        //si hubo repetidos, (conta!=0), se suma variable duplicados
            duplicados++;
        }
    }

    printf("From which them, there is %i duplicated number(s).", duplicados);




    return 0;
}