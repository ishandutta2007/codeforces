//Wan Hong 2.2
//notebook
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
typedef long long ll;
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

/**********/
#define MAXN 2011
#define MAXE 100000
#define MOD 998244353
ll n,k,a[MAXN],f[MAXN][MAXN];
ll calc(ll l)
{
	f[0][0]=1;
	ll p=0;
	for(ll i=1;i<=n;++i)
	{
		while(a[i]-a[p+1]>=l)++p;
		f[i][0]=f[i-1][0];
		for(ll j=1;j<=k;++j)f[i][j]=(f[i-1][j]+f[p][j-1])%MOD;
	}
	return f[n][k];
}
int main()
{
	n=read(),k=read();
	for(ll i=1;i<=n;++i)a[i]=read();
	std::sort(a+1,a+n+1);
	ll ans=0;
	for(ll i=1;i<=MAXE/(k-1);++i)
		ans=(ans+calc(i))%MOD;
	std::cout<<ans;
	return 0;
}