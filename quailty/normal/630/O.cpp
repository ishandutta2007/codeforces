#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef double db;
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
    db len()
    {
        return sqrt(x*x+y*y);
    }
    void right90()
    {
        swap(x,y);
        y=-y;
    }
    void input()
    {
        scanf("%lf%lf",&x,&y);
    }
}p,v,res[7];
int main()
{
    p.input();
    v.input();
    v=v/v.len();
    db a,b,c,d;
    scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
    res[0]=p+v*b;
    v.right90();
    res[1]=p+v*a/2;
    res[2]=p+v*c/2;
    v.right90();
    res[3]=res[2]+v*d;
    v.right90();
    res[4]=res[3]+v*c;
    v.right90();
    res[5]=res[4]+v*d;
    v.right90();
    res[6]=p-v*a/2;
    printf("%.20f %.20f\n",res[0].x,res[0].y);
    for(int i=6;i>=1;i--)
        printf("%.20f %.20f\n",res[i].x,res[i].y);
    return 0;
}