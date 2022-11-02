#include<stdio.h>
int a,b;
void add(){
    b++;
    if(b==60){
    b=0;
    a++;
    }
    if(a==24)a=0;
}
int sym(){
    return a/10==b%10&&a%10==b/10;
}
int main(){
    scanf("%d:%d",&a,&b);
    add();
    while(!sym())add();
    printf("%02d:%02d\n",a,b);
}