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
#define MAXN 511
ll a[MAXN][MAXN];
int main()
{
	ll n=read(),m=read();
	if(n==1&&m==1)
	{
		puts("0");
		return 0;
	}
	if(m==1)
	{
		for(ll i=1;i<=n;++i)printf("%lld\n",i+1);
		return 0;
	}
	for(ll i=1;i<=n;++i)
		for(ll j=1;j<=m;++j)a[i][j]=i;
	for(ll j=1;j<=m;++j)
		for(ll i=1;i<=n;++i)a[i][j]*=(j+n);
	for(ll i=1;i<=n;++i)
	{
		for(ll j=1;j<=m;++j)
			printf("%lld ",a[i][j]);
		putchar('\n');
	}
	return 0;
}