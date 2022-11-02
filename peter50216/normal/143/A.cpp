#include<stdio.h>
int main(){
    int r1,r2,c1,c2,d1,d2;
    scanf("%d%d%d%d%d%d",&r1,&r2,&c1,&c2,&d1,&d2);
    int q,w,e,r;
    for(q=1;q<=9;q++){
        w=r1-q;e=c1-q;r=d1-q;
        if(w+e!=d2||w+r!=c2||e+r!=r2)continue;
        if(q==w||q==e||q==r||w==e||w==r||e==r)continue;
        if(w>=10||w<=0||e>=10||e<=0||r>=10||r<=0)continue;
        printf("%d %d\n%d %d\n",q,w,e,r);
        break;
    }
    if(q==10)puts("-1");
}