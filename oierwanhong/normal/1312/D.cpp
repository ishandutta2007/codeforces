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
#define MAXN 200011
ll fac[MAXN],inv[MAXN];
const ll mod=998244353;
ll C(ll n,ll m)
{
	if(m>n)return 0;
	return fac[n]*inv[m]%mod*inv[n-m]%mod;
}
ll Qpow(ll a,ll p)
{
	ll res=1;
	while(p)
	{
		if(p&1)res=res*a%mod;
		a=a*a%mod;
		p>>=1; 
	}
	return res;
}
int main()
{
	fac[0]=inv[0]=1;
	for(ll i=1;i<MAXN;++i)
	{
		fac[i]=fac[i-1]*i%mod;
		inv[i]=Qpow(fac[i],mod-2);
	}
	ll n=read(),m=read(),sum1=0,sum2=0;
	for(ll x=1;x<=m;++x)sum1=(sum1+C(x-1,n-2)*(n-2)%mod*inv[2]%mod)%mod;
	for(ll pos=1;pos<=n;++pos)
		sum2=(sum2+C(n-2,pos-1))%mod;
	printf("%lld\n",sum1*sum2%mod);
	return 0; 
}