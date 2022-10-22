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
#define MAXN 5011
ll f[2][MAXN];
int main()
{
	ll n=read(),h=read(),l=read(),r=read();
	memset(f,0xcf,sizeof f);
	f[0][0]=0;
	for(ll i=1;i<=n;++i)
	{
		ll a=read();
		ll cur=i&1,pre=!cur;
		memset(f[cur],0xcf,sizeof f[cur]);
		for(ll j=0;j<h;++j)
		{
			f[cur][j]=max(f[pre][(j-a+h)%h],f[pre][(j-a+1+h)%h]);
			if(l<=j&&j<=r)++f[cur][j];
		}
	}
	ll ans=0;
	for(ll j=0;j<h;++j)umax(ans,f[n&1][j]);
	printf("%lld",ans);
	return 0;
}