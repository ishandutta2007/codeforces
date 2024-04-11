#include <stdio.h>
#include <stdlib.h>

int main(){
    int n,nr1,nr0;
    char a;
    scanf("%d" ,&n);
    a=fgetc(stdin);
    a=fgetc(stdin);
    nr0=nr1=0;
    while(a=='0'||a=='1'){
        if(a=='0')
             nr0++;
        else
             nr1++;
        a=fgetc(stdin);
    }
    printf("%d" ,abs(nr0-nr1));
    return 0;
}