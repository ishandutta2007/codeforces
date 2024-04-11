//Wan Hong 2.2
//notebook
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
typedef long long ll;
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
#define MAXN 400011
ll nn;
struct BIT
{
	ll t[MAXN];
	#define lowb (i&-i)
	void modify(ll i,ll k)
	{
		while(i<=nn)
		{
			t[i]+=k;
			i+=lowb;
		}
	}
	ll Qsum(ll i)
	{
		ll res=0;
		while(i)
		{
			res+=t[i];
			i-=lowb;
		}
		return res;
	}
}t;
ll fx[MAXN],a[MAXN],b[MAXN];
ll place(ll val)
{
	return std::lower_bound(fx+1,fx+nn+1,val)-fx;
}
int main()
{
	nn=0;
	ll n=read();
	for(ll i=1;i<=n;++i)a[i]=read();
	for(ll i=1;i<=n;++i)
	{
		b[i]=read();
		fx[++nn]=a[i]-b[i],fx[++nn]=b[i]-a[i];
	}
	std::sort(fx+1,fx+nn+1);
	nn=std::unique(fx+1,fx+nn+1)-fx-1;
	ll ans=0;
	for(ll i=1;i<=n;++i)
	{
		ans+=i-1-t.Qsum(place(b[i]-a[i]));
		t.modify(place(a[i]-b[i]),1);
	}
	printf("%lld",ans);
	return 0;
}