#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef double db;
const int MAXN=100005;
struct Point
{
    ll x,y;
    Point(){}
    Point(ll _x,ll _y):x(_x),y(_y){}
    Point operator - (const Point &t)const
    {
        return Point(x-t.x,y-t.y);
    }
    ll operator * (const Point &t)const
    {
        return x*t.y-y*t.x;
    }
}p[MAXN];
ll gcd(ll a,ll b)
{
    return b ? gcd(b,a%b) : a;
}
ll pointOnLine(Point p,Point q)
{
    ll tx=abs(p.x-q.x),ty=abs(p.y-q.y);
    if(tx==0)return ty;
    if(ty==0)return tx;
    return gcd(tx,ty);
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%I64d%I64d",&p[i].x,&p[i].y);
    ll tmp=0;
    for(int i=0;i<n;i++)
    {
        tmp+=p[i]*p[(i+1)%n];
        tmp-=pointOnLine(p[i],p[(i+1)%n]);
    }
    tmp=(tmp+2)/2;
    db res=0,cut=pow(2.0,-n),buf=1-(1LL*n*n+n+2)/2*cut;
    for(int i=0;i<n;i++)
    {
        ll cnt=0;
        db q=0.5;
        for(int j=(i+1)%n,k=2;k<=min(n-1,40);j=(j+1)%n,k++)
        {
            res+=cnt*((q*=0.5)-cut)/buf;
            ll now=(p[j]-p[i])*(p[(j+1)%n]-p[i]);
            now-=pointOnLine(p[i],p[j]);
            now-=pointOnLine(p[j],p[(j+1)%n]);
            now-=pointOnLine(p[(j+1)%n],p[i]);
            cnt+=(now+2)/2;
            cnt+=pointOnLine(p[i],p[(j+1)%n])-1;
        }
    }
    res=tmp-res;
    printf("%.10f",res);
    return 0;
}