//Wan Hong 3.1
//notebook
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
typedef long long ll;
typedef unsigned un;
typedef std::pair<ll,ll> pll;
typedef std::string str;
#define INF (1ll<<58)
ll read()
{
	ll x=0,f=1;
	char c;
	do
	{
		c=getchar();
		if(c=='-')f=-1;
	}while(c<'0'||c>'9');
	do
	{
		x=x*10+c-'0';
		c=getchar();
	}while(c>='0'&&c<='9');
	return f*x;
}
ll min(ll a,ll b)
{
	return a<b?a:b;
}
ll max(ll a,ll b)
{
	return a>b?a:b;
}
bool umin(ll &a,ll b)
{
	if(b<a)return a=b,1;
	return 0;
}
bool umax(ll &a,ll b)
{
	if(b>a)return a=b,1;
	return 0;
}
/**********/
#define MAXN 200011
ll n;
struct BIT
{
    ll t[MAXN];
    #define lowb (i&-i)
    void modify(ll i,ll k)
    {
        while(i<=n)t[i]+=k,i+=lowb;
    }
    ll Qsum(ll i)
    {
        ll res=0;
        while(i)res+=t[i],i-=lowb;
        return res;
    }
}tc,ts;
ll fx[MAXN];
ll place(ll val)
{
    return std::lower_bound(fx+1,fx+n+1,val)-fx;
}
pll a[MAXN];
int main()
{
    n=read();
    for(ll i=1;i<=n;++i)a[i].first=read();
    for(ll i=1;i<=n;++i)a[i].second=read(),fx[i]=a[i].second;
    std::sort(a+1,a+n+1);std::sort(fx+1,fx+n+1);
    ll ans=0;
    for(ll i=1;i<=n;++i)
    {
        ll v=place(a[i].second);
        ans+=tc.Qsum(v)*a[i].first-ts.Qsum(v);
        tc.modify(v,1),ts.modify(v,a[i].first);
    }
    printf("%lld",ans);
    return 0;
}