//Wan Hong 3.1
//notebook
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
#include<map>
typedef long long ll;
typedef unsigned un;
typedef std::pair<ll,ll> pll;
typedef std::string str;
#define INF (1ll<<28)
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
#define MAXN 600011
ll n,m;
struct BIT
{
    ll t[MAXN];
    #define lowb (i&-i)
    void modify(ll i,ll k)
    {
        while(i<=n+m)t[i]+=k,i+=lowb;
    }
    ll Qsum(ll i)
    {
        ll res=0;
        while(i)res+=t[i],i-=lowb;
        return res;
    }
}t;
ll a[MAXN],minv[MAXN],maxv[MAXN];
int main()
{
    n=read(),m=read();
    for(ll i=1;i<=n;++i)
    {
        a[i]=n-i+1;
        t.modify(n-i+1,1);
        minv[i]=maxv[i]=i;
    }
    for(ll i=1;i<=m;++i)
    {
        ll x=read();
        minv[x]=1;
        umax(maxv[x],n-t.Qsum(a[x]-1));
        t.modify(a[x],-1);
        a[x]=n+i,t.modify(n+i,1);
    }
    for(ll i=1;i<=n;++i)
        umax(maxv[i],n-t.Qsum(a[i]-1));
    for(ll i=1;i<=n;++i)printf("%lld %lld\n",minv[i],maxv[i]);
    return 0;
}