#include<stdio.h>
int main(){
    int n,x,y;
    scanf("%d%d%d",&n,&x,&y);
    puts((x==n/2||x==n/2+1)&&(y==n/2||y==n/2+1)?"NO":"YES");
}