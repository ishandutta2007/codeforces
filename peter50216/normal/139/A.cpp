#include<stdio.h>
int in[10];
int main(){
    int n,i;
    scanf("%d",&n);
    for(i=0;i<7;i++)scanf("%d",&in[i]);
    for(i=0;;i=(i+1)%7){
        n-=in[i];
        if(n<=0)break;
    }
    printf("%d\n",i+1);
}