#include<stdio.h>
int u[1100];
int main(){
    int n,c=0;
    scanf("%d",&n);
    while(n--){
    int x;
    scanf("%d",&x);
    if(u[x]==0)u[x]=1;
    else{
        c++;
        u[x]=0;
    }
    }
    printf("%d\n",c/2);
}