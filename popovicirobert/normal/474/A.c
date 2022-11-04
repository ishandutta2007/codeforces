#include <stdio.h>
#include <stdlib.h>
char v[]={'q','w','e','r','t','y','u','i','o','p','a','s','d','f','g','h','j','k','l',';','z','x','c','v','b','n','m',',','.','/'};
int main()
{
    int i,j;
    char a;
    a=fgetc(stdin);
    if(a=='R')
        j=-1;
    else
        j=1;
    a=fgetc(stdin);
    a=fgetc(stdin);
    while(a!='\n'){
        i=0;
        while(v[i]!=a)
            i++;
        if(i==0&&j==-1)
            fputc('/',stdout);
        else
            fputc(v[(i+j)%30],stdout);
        a=fgetc(stdin);
    }
    return 0;
}