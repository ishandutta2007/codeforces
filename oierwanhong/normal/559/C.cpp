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
#define MAXE 200011
#define MAXN 2011
ll fac[MAXE],inv[MAXE];
const ll mod=ll(1e9+7);
ll Qpow(ll a,ll p)
{
	ll res=1;
	while(p)
	{
		if(p&1)res=(res*a)%mod;
		a=(a*a)%mod;
		p>>=1;
	}
	return res;
}
ll C(ll n,ll m)
{
	return fac[n]*inv[m]%mod*inv[n-m]%mod;
}

pll a[MAXN];
ll f[MAXN];
int main()
{
	ll h=read(),w=read();
	fac[0]=1,inv[0]=1;
	for(ll i=1;i<MAXE;++i)
	{
		fac[i]=fac[i-1]*i%mod;
		inv[i]=Qpow(fac[i],mod-2);
	}
	ll n=read();
	for(ll i=1;i<=n;++i)a[i].first=read(),a[i].second=read();
	a[n+1]=pll(h,w);
	std::sort(a+1,a+n+2);
	for(ll i=1;i<=n+1;++i)
	{
		ll x=a[i].first,y=a[i].second;
		f[i]=C(x-1+y-1,x-1);
		for(ll j=1;j<i;++j)
		{
			ll vx=a[j].first,vy=a[j].second;
			if(vx<=x&&vy<=y)f[i]=(f[i]-f[j]*C(x-vx+y-vy,x-vx)%mod)%mod;
		}
	}
	printf("%lld",(f[n+1]+mod)%mod);
	return 0;
}