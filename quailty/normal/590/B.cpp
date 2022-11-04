#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef double db;
const db eps=1e-8;
struct Point
{
    db x,y;
    Point(){}
    Point(db _x,db _y):x(_x),y(_y){}
    Point operator + (const Point &t)const
    {
        return Point(x+t.x,y+t.y);
    }
    Point operator - (const Point &t)const
    {
        return Point(x-t.x,y-t.y);
    }
    Point operator * (const db &t)const
    {
        return Point(x*t,y*t);
    }
    Point operator / (const db &t)const
    {
        return Point(x/t,y/t);
    }
    db dis()
    {
        return sqrt(x*x+y*y);
    }
}p[10];
int main()
{
    for(int i=1;i<=2;i++)
        scanf("%lf%lf",&p[i].x,&p[i].y);
    db v,t;
    scanf("%lf%lf",&v,&t);
    for(int i=3;i<=4;i++)
        scanf("%lf%lf",&p[i].x,&p[i].y);
    for(int i=3;i<=4;i++)
    {
        p[i].x*=-1.0;
        p[i].y*=-1.0;
    }
    db l=0.0,r=2*t;
    for(int ct=1;ct<=100;ct++)
    {
        db m=(l+r)/2.0;
        if((p[3]*m+p[2]-p[1]).dis()<m*v+eps)r=m;
        else l=m;
    }
    if(l<t+eps)
    {
        printf("%.15f\n",l);
    }
    else
    {
        l=t,r=2*t;
        p[2]=p[2]+p[3]*t;
        while((p[4]*(r-t)+p[2]-p[1]).dis()>r*v-eps)r*=2.0;
        for(int ct=1;ct<=100;ct++)
        {
            db m=(l+r)/2.0;
            if((p[4]*(m-t)+p[2]-p[1]).dis()<m*v+eps)r=m;
            else l=m;
        }
        printf("%.15f\n",l);
    }
    return 0;
}