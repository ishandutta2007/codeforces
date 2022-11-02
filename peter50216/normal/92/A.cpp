#include<stdio.h>
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    int i=1;
    while(1){
    if(m<i)break;
    m-=i;
    if(i<n)i++;
    else i=1;
    }
    printf("%d\n",m);
}