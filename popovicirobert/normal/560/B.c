#include <stdio.h>
#include <stdlib.h>
int getmax(int a,int b){
    if(a>b) return a;
    return b;
}
int main()
{
    int x1,x2,x3,y1,y2,y3,flag;
    scanf("%d%d%d%d%d%d" ,&x1,&y1,&x2,&y2,&x3,&y3);
    flag=0;
    if(x2+x3<=x1)
         if(getmax(y2,y3)<=y1)
            flag=1;
    if(x2+x3<=y1)
         if(getmax(y2,y3)<=x1)
            flag=1;
    if(x2+y3<=x1)
         if(getmax(y2,x3)<=y1)
            flag=1;
    if(x2+y3<=y1)
         if(getmax(y2,x3)<=x1)
            flag=1;
    if(y2+x3<=x1)
         if(getmax(x2,y3)<=y1)
            flag=1;
    if(y2+x3<=y1)
         if(getmax(x2,y3)<=x1)
            flag=1;
    if(y2+y3<=y1)
        if(getmax(x2,x3)<=x1)
            flag=1;
    if(y2+y3<=x1)
         if(getmax(x2,x3)<=y1)
            flag=1;
    if(flag)
        printf("YES");
    else
        printf("NO");
    return 0;
}