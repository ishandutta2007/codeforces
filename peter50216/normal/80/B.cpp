#include<stdio.h>
int main(){
    int a,b;
    scanf("%d:%d",&a,&b);
    a%=12;
    printf("%.1lf %.1lf\n",30*a+0.5*b,6.0*b);
}