#include<stdio.h>
int main(){
    int n,m,l,r;
    scanf("%d%d",&n,&m);
    l=1;r=n;
    char t[100];
    while(m--){
    int d=0;
    scanf("%*s%*s%s%*s%d",t,&d);
    if(t[0]=='l'&&r>d-1)r=d-1;
    else if(t[0]=='r'&&l<d+1)l=d+1;
    }
    printf("%d\n",r-l+1<=0?-1:r-l+1);
}