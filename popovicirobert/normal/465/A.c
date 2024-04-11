#include <stdio.h>
#include <stdlib.h>
char v[100];
int main(){
    int n,con;
    char a;
    scanf("%d" ,&n);a=fgetc(stdin);
    a=fgetc(stdin);
    con=1;
    while(a=='1'){
        a=fgetc(stdin);
        con++;
    }
    if(con==n+1)
      con--;
    printf("%d" ,con);
    return 0;
}