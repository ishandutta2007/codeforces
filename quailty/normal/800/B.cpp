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
    Point operator - (const Point &t)const
    {
        return Point(x-t.x,y-t.y);
    }
    db operator * (const Point &t)const
    {
        return x*t.y-y*t.x;
    }
    db len()const
    {
        return sqrt(x*x+y*y);
    }
}p[1005];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%lf%lf",&p[i].x,&p[i].y);
    reverse(p,p+n);
    db res=1e100;
    for(int i=0;i<n;i++)
        res=min(res,((p[(i+1)%n]-p[i])*(p[(i+2)%n]-p[(i+1)%n]))/(p[(i+2)%n]-p[i]).len());
    printf("%.12f\n",res/2);
    return 0;
}