#include<stdio.h>
int in[110];
int main(){
    int n,k,i;
    scanf("%d%d",&n,&k);
    for(i=1;i<=n;i++)scanf("%d",&in[i]);
    int a=0;
    for(i=1;i<=n;i++)if(in[i]>=in[k]&&in[i]>0)a++;
    printf("%d\n",a);
}