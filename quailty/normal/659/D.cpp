#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=1005;
struct Point
{
    int x,y;
    Point(){}
    Point(int _x,int _y):x(_x),y(_y){}
    Point operator - (const Point &t)const
    {
        return Point(x-t.x,y-t.y);
    }
    int operator * (const Point &t)const
    {
        return x*t.y-y*t.x;
    }
}p[MAXN];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<=n;i++)
        scanf("%d%d",&p[i].x,&p[i].y);
    int res=0;
    for(int i=1;i<n;i++)
        res+=(p[i+1]-p[i])*(p[i]-p[i-1])<0;
    return 0*printf("%d\n",res);
}