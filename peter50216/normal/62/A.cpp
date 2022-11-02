#include<stdio.h>
int f(int a,int b){
    return b>=a-1&&b<=a*2+2;
}
int main(){
    int a,b,c,d;
    scanf("%d%d%d%d",&a,&b,&c,&d);
    puts(f(a,d)||f(b,c)?"YES":"NO");
}