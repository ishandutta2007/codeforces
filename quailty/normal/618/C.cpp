#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=100005;
struct Point
{
    ll x,y;
    int id;
    Point(){}
    Point(ll _x,ll _y,int _id):x(_x),y(_y),id(_id){}
    Point operator - (const Point &t)const
    {
        return Point(x-t.x,y-t.y,id);
    }
    bool operator < (const Point &t)const
    {
        return x==t.x ? y<t.y : x<t.x;
    }
    ll operator * (const Point &t)const
    {
        return x*t.y-y*t.x;
    }
    ll operator ^ (const Point &t)const
    {
        return x*t.x+y*t.y;
    }
}p[MAXN];
bool cmp(Point a,Point b)
{
    a=a-p[0];
    b=b-p[0];
    if(a*b==0)return (a^a)<(b^b);
    else return a*b>0;
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%I64d%I64d",&p[i].x,&p[i].y);
        p[i].id=i+1;
    }
    sort(p,p+n);
    sort(p+1,p+n,cmp);
    printf("%d %d ",p[0].id,p[1].id);
    int t=1;
    while(t<n && (p[t]-p[0])*(p[1]-p[0])==0)t++;
    printf("%d\n",p[t].id);
    return 0;
}