//Wan Hong 3.1
//notebook
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#include<queue>
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
    void build(ll n)
    {
    	for(ll i=1;i<=n;++i)t[i]=-INF;
	}
    #define lowb (i&-i)
    void modify(ll i,ll k)
    {
        while(i<=n)umax(t[i],k),i+=lowb;
    }
    ll Qmax(ll i)
    {
        ll res=-INF;
        while(i)umax(res,t[i]),i-=lowb;
        return res;
    }
}t;
struct one
{
    ll x,h,dex;
    bool operator <(const one& t)
    const
    {
        return x<t.x;
    }
}a[MAXN];
ll fx[MAXN],ans[MAXN];
ll place(ll val)
{
    return std::upper_bound(fx+1,fx+n+1,val)-fx;
}

int main()
{
    n=read();
    t.build(n);
    for(ll i=1;i<=n;++i)a[i].x=fx[i]=read(),a[i].h=read(),a[i].dex=i;
    std::sort(fx+1,fx+n+1),std::sort(a+1,a+n+1);
    for(ll i=n;i;--i)
    {
    	ll x=max(t.Qmax(place(a[i].x+a[i].h-1)-1),a[i].x+a[i].h-1);
    	ans[a[i].dex]=place(x)-i;
    	t.modify(i,x);
    }
    for(ll i=1;i<=n;++i)printf("%lld ",ans[i]);
    return 0;
}