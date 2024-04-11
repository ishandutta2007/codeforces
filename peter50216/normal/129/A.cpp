#include<stdio.h>
int in[10100];
int main(){
    int n,c=0,i,s=0;
    scanf("%d",&n);
    for(i=0;i<n;i++){
    scanf("%d",&in[i]);
    s+=in[i];
    }
    for(i=0;i<n;i++)if((s-in[i])%2==0)c++;
    printf("%d\n",c);
}