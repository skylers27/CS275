/* grzst.c
 * Skyler Szot
 * Project 1, rank words by difficulty to pronounce
 */

#include <stdio.h>
#include <stdlib.h>

#define G 0.618f //inverse of golden ratio
#define N 1000 //max words
#define W 25 //max word length

void sort(char *A[],int n); //sort array of size n

int compare(char x[],char y[]); //return T if x>y, else F

int main(){
    char *A[N];
    int i, j;

    for(i = 0; i < N ; i++){ //dynamic memory allocation
        A[i]=malloc(W + 1);
        scanf("%s", A[i]);
        if(*A[i] == '\0'){break;} //break at EOF
    }

    sort(A,i); //i = number of elements, sort A
    for(j = 0; j < i; j++){ //print sorted array
        printf("%s\n",A[j]);
    }
}


int compare(char x[], char y[]){
    float cons = 0;
    float total = 0;
    float ratiox, ratioy;
    char *ix; //char pointer
    char *iy;
    ix = x; //first char
    while(*ix != '\0'){ //loop until end of string
        if ((*ix == 'a')||(*ix == 'e')||(*ix == 'i')||(*ix == 'o')||(*ix == 'u')){
            total += 1; //if a vowel, only increment total
            ix++; //increment pointer
        }
        else{ //otherwise a consonant
            cons+=1; //increment consonants
            total+=1;
            ix++;
        }
    }
    ratiox = ((cons/total)-G); //calculate x ratio
    if (ratiox < 0){ratiox = ratiox * -1.0;} //absolute value

    iy = y; //first char
    total = 0; //reuse
    cons = 0; //reuse
    while(*iy != '\0'){ //loop until end of string
        if ((*iy == 'a')||(*iy == 'e')||(*iy == 'i')||(*iy == 'o')||(*iy == 'u')){
            total += 1;
            iy++;
        }
        else{
            cons+=1;
            total+=1;
            iy++;
        }
    }
    ratioy = ((cons/total)-0.618); //calculate y ratio
    if (ratioy < 0){ratioy = ratioy * -1.0;}
    return(ratioy<ratiox); //compare x and y ratios
}
    

void sort(char *A[], int n){
    int i, j;
    char *key;
    for(j = 1; j<n; j++){
        key = *(A+j); //value to compare
        // Now shift A[j] to where it belongs in
        // the sorted sequence A[1]..A[j-1]
        i = j-1;
        while ((i >= 0) && (compare(A[i],key))){ //while in the wrong place
            A[i+1] = A[i]; //swap
            i = i - 1;
            A[i+1] = key; 
        }
    }
}
