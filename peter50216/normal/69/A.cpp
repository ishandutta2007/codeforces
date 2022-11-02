#include<stdio.h>
inline int gn(){int a;scanf("%d",&a);return a;}
int main(){
    int n,x=0,y=0,z=0;
    scanf("%d",&n);
    while(n--){x+=gn();y+=gn();z+=gn();}
    puts(x||y||z?"NO":"YES");
}