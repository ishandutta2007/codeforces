#include<bits/stdc++.h>
using namespace std;

typedef long double db;
const db eps=1e-12;

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
    bool operator < (const Point &t)const
    {
        return fabs(x-t.x)<eps ? y<t.y : x<t.x;
    }
    bool operator == (const Point &t)const
    {
        return fabs(x-t.x)<eps && fabs(y-t.y)<eps;
    }
    db len()const
    {
        return sqrt(x*x+y*y);
    }
    Point rot90()const
    {
        return Point(-y,x);
    }
}p[3],res;

int main()
{
    db R;
    cin>>R>>p[0].x>>p[0].y>>p[1].x>>p[1].y;
    if(p[0]==p[1])res=Point(p[0].x+R/2,p[0].y);
    else
    {
        db d=(p[1]-p[0]).len();
        if(d<=R)
        {
            p[2]=p[0]-(p[1]-p[0])/d*R;
            res=(p[1]+p[2])/2;
        }
        else res=p[0];
    }
    db dis=min(R,(res-p[1]).len());
    printf("%.12f %.12f %.12f\n",(double)res.x,(double)res.y,(double)dis);
    return 0;
}