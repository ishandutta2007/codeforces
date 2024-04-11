#include<stdio.h>
int a[1000];

int main(){
    int n,k,t,i,s=0;
    scanf("%d%d%d",&n,&k,&t);
    i=0;
    while(1){
    if((s+1)*100>t*(n*k))break;
    a[i]++;
    s++;
    if(a[i]==k)i++;
    }
    for(i=0;i<n;i++)printf("%d%c",a[i],(i==n-1)?'\n':' ');
}