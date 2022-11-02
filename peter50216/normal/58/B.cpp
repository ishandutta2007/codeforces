#include<stdio.h>
int main(){
    int n,i;
    scanf("%d",&n);
    printf("%d",n);
    while(n>1){
    for(i=2;i*i<=n;i++)if(n%i==0)break;
    if(n%i==0)n/=i;
    else n=1;
    printf(" %d",n);
    }
}