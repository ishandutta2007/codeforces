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
ll dis[MAXN][MAXN],p[MAXN][MAXN];
ll a[MAXN];
int main()
{
	ll n=read(),c=0;
	
	for(ll i=1;i<=n;++i)
	{
		ll x=read();
		if(x!=0)a[++c]=x;
	}
	n=c;
	if(n>300)
	{
		puts("3");
		return 0;
	}
	for(ll i=1;i<=n;++i)
		for(ll j=1;j<=n;++j)
			if(i!=j&&(a[i]&a[j]))dis[i][j]=p[i][j]=1;
			else dis[i][j]=p[i][j]=INF;
	ll ans=INF;
	for(ll k=1;k<=n;++k)
	{
		for(ll i=1;i<k;++i)
			for(ll j=1;j<i;++j)
			{
				umin(ans,dis[i][j]+p[i][k]+p[k][j]);
			}
		for(ll i=1;i<=n;++i)
			for(ll j=1;j<=n;++j)
				umin(dis[i][j],dis[i][k]+dis[k][j]);
	}
	std::cout<<(ans==INF?-1:ans);
	return 0;
}