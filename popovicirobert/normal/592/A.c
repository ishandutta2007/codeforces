#include <stdio.h>
#include <stdlib.h>
#define MAXN 10
int sus[2][MAXN+1],jos[2][MAXN+1];
int main(){
    int i,j,min,flag;
    char a;
    for(i=1;i<=MAXN;i++){
        sus[0][i]=sus[1][i]=MAXN+1;
        jos[0][i]=jos[1][i]=0;
    }
    a=fgetc(stdin);
    i=1;
    while(a=='.'||a=='B'||a=='W'){
        j=1;
        while(a=='.'||a=='B'||a=='W'){
           if(a=='B'){
               if(sus[1][j]>i)
                  sus[1][j]=i;
               if(jos[1][j]<i)
                  jos[1][j]=i;
           }
           if(a=='W'){
               if(sus[0][j]>i)
                  sus[0][j]=i;
               if(jos[0][j]<i)
                  jos[0][j]=i;
           }
           j++;
           a=fgetc(stdin);
        }
        i++;
        a=fgetc(stdin);
    }
    min=MAXN+1;
    flag=-1;
    for(i=1;i<=MAXN;i++){
        if(sus[0][i]<sus[1][i]&&min>=sus[0][i]-1){
           min=sus[0][i]-1;
           flag=0;
        }
        if(jos[1][i]>jos[0][i]&&min>8-jos[1][i]){
           min=8-jos[1][i];
           flag=1;
        }
    }
    if(flag==0)
        printf("A");
    else
        printf("B");
    return 0;
}