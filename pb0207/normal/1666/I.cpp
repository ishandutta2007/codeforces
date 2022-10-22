#include<bits/stdc++.h>
using namespace std;

int T;

int n,m;

int a,b,c,d;

int Ask(int x,int y)
{
    printf("SCAN %d %d\n",x,y);
    fflush(stdout);
    int r;
    // r=abs(a-x)+abs(b-y)+abs(c-x)+abs(d-y);
    scanf("%d",&r);
    return r;
}

int DIG(int x,int y)
{
    printf("DIG %d %d\n",x,y);
    fflush(stdout);
    int r;
    // r=(a==x&&b==y)||(c==x&&d==y);
    scanf("%d",&r);
    return r;
}

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        // a=rand()%n+1,b=rand()%m+1;
        // c=rand()%n+1,d=rand()%m+1;
        // printf("%d %d %d %d\n",a,b,c,d);
        int A1=Ask(1,1);
        int A2=Ask(1,m);
        int s1=A1+4;
        int s2=A2+2-2*m;
        int sx=(s1+s2)/2;
        int sy=(s1-s2)/2;
        int A3=Ask(sx/2,1);
        int A4=Ask(1,sy/2);
        int dx=A3+2-sy;
        int dy=A4+2-sx;
        int ax=(sx+dx)/2,bx=(sx-dx)/2;
        int ay=(sy+dy)/2,by=(sy-dy)/2;
        if(DIG(ax,ay))
            DIG(bx,by);
        else
            DIG(bx,ay),DIG(ax,by);
    }
}