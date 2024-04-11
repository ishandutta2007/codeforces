#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef double db;
const db PI=acos(-1.0);
struct Point
{
    db x,y;
    Point() {}
    Point(db _x,db _y):x(_x),y(_y) {}
    Point operator + (const Point &t)const
    {
        return Point(x+t.x,y+t.y);
    }
    Point operator - (const Point &t)const
    {
        return Point(x-t.x,y-t.y);
    }
    db operator ^(const Point &b)const
    {
        return x*b.y - y*b.x;
    }
    db operator *(const Point &b)const
    {
        return x*b.x + y*b.y;
    }
} t[100005];
double dist(Point a,Point b)
{
    return sqrt((a-b)*(a-b));
}
struct Line
{
    Point s,e;
    Line() {}
    Line(Point _s,Point _e)
    {
        s = _s;
        e = _e;
    }
};
Point NearestPointToLineSeg(Point P,Line L)
{
    Point result;
    db t = ((P-L.s)*(L.e-L.s))/((L.e-L.s)*(L.e-L.s));
    if(t >= 0 && t <= 1)
    {
        result.x = L.s.x + (L.e.x - L.s.x)*t;
        result.y = L.s.y + (L.e.y - L.s.y)*t;
    }
    else
    {
        if(dist(P,L.s) < dist(P,L.e))
            result = L.s;
        else result = L.e;
    }
    return result;
}
int main()
{
    int n;
    scanf("%d",&n);
    Point P;
    scanf("%lf%lf",&P.x,&P.y);
    for(int i=0; i<n; i++)
        scanf("%lf%lf",&t[i].x,&t[i].y);
    db mx=0,mi=1e20;
    for(int i=0; i<n; i++)
        mx=max(mx,dist(P,t[i]));
    for(int i=0; i<n; i++)
        mi=min(mi,dist(P,NearestPointToLineSeg(P,Line(t[i],t[(i+1)%n]))));
    printf("%.15f\n",(mx*mx-mi*mi)*PI);
    return 0;
}