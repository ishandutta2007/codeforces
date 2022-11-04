#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
struct Point
{
    int x,y;
    Point(){}
    Point(int _x,int _y):x(_x),y(_y){}
    Point operator + (const Point &t)const
    {
        return Point(x+t.x,y+t.y);
    }
    Point operator - (const Point &t)const
    {
        return Point(x-t.x,y-t.y);
    }
}p[3];
int main()
{
    for(int i=0;i<3;i++)
        scanf("%d%d",&p[i].x,&p[i].y);
    printf("3\n");
    for(int i=0;i<3;i++)
    {
        Point t=p[i]+p[(i+1)%3]-p[(i+2)%3];
        printf("%d %d\n",t.x,t.y);
    }
    return 0;
}