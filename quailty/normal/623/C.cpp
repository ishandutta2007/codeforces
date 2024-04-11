#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=100005;
const ll INF=(1LL<<62)-1;
struct Point
{
    ll x,y;
    bool operator < (const Point &t)const
    {
        return x==t.x ? y<t.y : x<t.x;
    }
}p[MAXN];
ll mx[2][MAXN],mi[2][MAXN];
bool check(int n,ll m)
{
    if((p[n].x-p[1].x)*(p[n].x-p[1].x)<=m)return 1;
    if((mx[0][n]-mi[0][n])*(mx[0][n]-mi[0][n])<=m)return 1;
    int l=1,r=1;
    while(l<=n)
    {
        while(r<=n && (p[r].x-p[l].x)*(p[r].x-p[l].x)<=m && p[r].x*p[r].x<=p[l].x*p[l].x)r++;
        r--;
        while(p[r].x*p[r].x>p[l].x*p[l].x)r--;
        r++;
        ll u=-INF,d=INF;
        if(l>1)
        {
            u=max(u,mx[0][l-1]);
            d=min(d,mi[0][l-1]);
        }
        if(r<=n)
        {
            u=max(u,mx[1][r]);
            d=min(d,mi[1][r]);
        }
        if(p[l].x*p[l].x+max(u*u,d*d)<=m && p[r-1].x*p[r-1].x+max(u*u,d*d)<=m && (u-d)*(u-d)<=m)return 1;
        l++;
    }
    l=n,r=n;
    while(r>=1)
    {
        while(l>=1 && (p[r].x-p[l].x)*(p[r].x-p[l].x)<=m && p[l].x*p[l].x<=p[r].x*p[r].x)l--;
        l++;
        while(p[l].x*p[l].x>p[r].x*p[r].x)l++;
        l--;
        ll u=-INF,d=INF;
        if(l>=1)
        {
            u=max(u,mx[0][l]);
            d=min(d,mi[0][l]);
        }
        if(r<n)
        {
            u=max(u,mx[1][r+1]);
            d=min(d,mi[1][r+1]);
        }
        if(p[l+1].x*p[l+1].x+max(u*u,d*d)<=m && p[r].x*p[r].x+max(u*u,d*d)<=m && (u-d)*(u-d)<=m)return 1;
        r--;
    }
    return 0;
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%I64d%I64d",&p[i].x,&p[i].y);
    sort(p+1,p+n+1);
    mx[0][0]=mx[1][n+1]=-INF;
    mi[0][0]=mi[1][n+1]=INF;
    for(int i=1;i<=n;i++)
    {
        mx[0][i]=max(mx[0][i-1],p[i].y);
        mi[0][i]=min(mi[0][i-1],p[i].y);
    }
    for(int i=n;i>=1;i--)
    {
        mx[1][i]=max(mx[1][i+1],p[i].y);
        mi[1][i]=min(mi[1][i+1],p[i].y);
    }
    ll l=0,r=INF;
    while(l<r)
    {
        ll m=(l+r)>>1;
        if(check(n,m))r=m;
        else l=m+1;
    }
    printf("%I64d\n",l);
    return 0;
}