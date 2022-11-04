#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll INF=(1LL<<60)-1;
struct Point
{
    ll x,y;
    Point(){}
    Point(ll _x,ll _y):x(_x),y(_y){}
    Point operator - (const Point &t)const
    {
        return Point(x-t.x,y-t.y);
    }
    ll len()
    {
        return x*x+y*y;
    }
}p[2005],q[2];
bool cmp(Point a,Point b)
{
    if((a-q[0]).len()==(b-q[0]).len())return (a-q[1]).len()>(b-q[1]).len();
    else return (a-q[0]).len()>(b-q[0]).len();
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<2;i++)
        scanf("%I64d%I64d",&q[i].x,&q[i].y);
    for(int i=0;i<n;i++)
        scanf("%I64d%I64d",&p[i].x,&p[i].y);
    sort(p,p+n,cmp);
    ll res=INF,mx=0;
    for(int i=0;i<n;i++)
    {
        res=min(res,mx+(p[i]-q[0]).len());
        mx=max(mx,(p[i]-q[1]).len());
    }
    res=min(res,mx);
    printf("%I64d\n",res);
    return 0;
}