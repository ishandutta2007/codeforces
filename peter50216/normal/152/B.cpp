#include<stdio.h>
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    int x,y;
    scanf("%d%d",&x,&y);
    int k;
    long long aa=0;
    scanf("%d",&k);
    while(k--){
        int dx,dy;
        scanf("%d%d",&dx,&dy);
        int r=2000000000;
        if(dx!=0){
            int rr;
            if(dx<0)rr=(x-1)/(-dx);
            else rr=(n-x)/dx;
            if(rr<r)r=rr;
        }
        if(dy!=0){
            int rr;
            if(dy<0)rr=(y-1)/(-dy);
            else rr=(m-y)/dy;
            if(rr<r)r=rr;
        }
        aa+=r;
        x+=r*dx;y+=r*dy;
    }
    printf("%I64d\n",aa);
}