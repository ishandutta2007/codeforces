//Wan Hong 3.1
//Online IDE
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
typedef long long ll;
typedef std::pair<ll,ll> pll;
#define INF (1ll<<58)
ll read()
{
    ll f=1,x=0;
    char c=getchar();
    while(c<'0'||c>'9')
    {
        if(c=='-')f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
    return f*x;
}
ll max(ll a,ll b)
{
    return a>b?a:b;
}
ll min(ll a,ll b)
{
    return a<b?a:b;
}
bool umax(ll& a,ll b)
{
    if(b>a)return a=b,1;
    return 0;
}
bool umin(ll& a,ll b)
{
    if(b<a)return a=b,1;
    return 0;
}
ll abs(ll x)
{
    return x>0?x:-x;
}

/**********/
ll count(ll x,ll n)
{
    ll res=0;
    if(x&1)++res,x<<=1;
    ll cur=2;
    while(x+cur-1<=n)
    {
        res+=cur;
        x<<=1;
        cur<<=1;
    }
    return res+max(0,n-x+1);
}
ll work(ll n,ll k,ll s)
{
    ll l=0,r=(n+1)/2;
    while(l<r)
    {
        ll mid=(l+r+1)>>1;
        if(count(mid*2-s,n)>=k)l=mid;
        else r=mid-1;
    }
    return l*2-s;
}
int main()
{
    ll n=read(),k=read();
    printf("%lld",max(work(n,k,0),work(n,k,1)));
    return 0;
}