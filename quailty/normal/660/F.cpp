#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef long double ldb;
const int MAXN=200005;
const ldb eps=1e-3;
ll a[MAXN],pre[MAXN],pre2[MAXN];
int sgn(ldb x)
{
    if(x>eps)return 1;
    if(x<-eps)return -1;
    return 0;
}
struct Point
{
    ll x,y;
    Point(){}
    Point(ll _x,ll _y):x(_x),y(_y){}
    Point operator - (const Point &t)const
    {
        return Point(x-t.x,y-t.y);
    }
    ldb operator * (const Point &t)const
    {
        return (ldb)x*t.y-(ldb)y*t.x;
    }
    ll operator ^ (const Point &t)const
    {
        return x*t.x+y*t.y;
    }
}stk[MAXN];
int top=0;
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%I64d",&a[i]);
        pre[i]=pre[i-1]+a[i];
        pre2[i]=pre2[i-1]+i*a[i];
    }
    ll res=0;
    for(int i=1;i<=n;i++)
    {
        Point t=Point(i-1,(i-1)*pre[i-1]-pre2[i-1]);
        while(top>1 && sgn((t-stk[top])*(stk[top]-stk[top-1]))<=0)--top;
        stk[++top]=t;
        int l=1,r=top;
        Point p=Point(-pre[i],1);
        while(l<r)
        {
            int m1=(2*l+r)/3;
            int m2=(l+2*r+2)/3;
            if((p^stk[m1])<(p^stk[m2]))l=m1+1;
            else r=m2-1;
        }
        res=max(res,pre2[i]+(p^stk[l]));
    }
    printf("%I64d",res);
    return 0;
}