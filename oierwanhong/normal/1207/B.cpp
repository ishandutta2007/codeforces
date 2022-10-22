//Wan Hong 2.2
//home
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
typedef long long ll;
typedef std::string str;
#define INF (1ll<<58)
ll read()
{
	ll f=1,x=0;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
	return f*x;
}
ll max(ll a,ll b)
{
	return a>b?a:b;
}
ll min(ll a,ll b)
{
    return a<b?a:b;
}
bool umax(ll& a,ll b)
{
	if(b>a)return a=b,1;
	return 0;
}
bool umin(ll& a,ll b)
{
	if(b<a)return a=b,1;
	return 0;
}

/**********/
typedef std::pair<ll,ll> pll;
#define MAXN 111
ll a[MAXN][MAXN];
bool vis[MAXN][MAXN];
pll ans[MAXN*MAXN];
int main()
{
	ll n=read(),m=read(),cnt=0;
	for(ll i=1;i<=n;++i)
		for(ll j=1;j<=m;++j)a[i][j]=read();
	bool flag=1;
	for(ll i=1;i<n;++i)
		for(ll j=1;j<m;++j)
			if(a[i][j]&&a[i+1][j]&&a[i][j+1]&&a[i+1][j+1])
			{
				++cnt;
				ans[cnt]=pll(i,j);
				vis[i][j]=vis[i+1][j]=vis[i][j+1]=vis[i+1][j+1]=1;
			}
	for(ll i=1;i<=n;++i)
		for(ll j=1;j<=m;++j)
			if(a[i][j]&&!vis[i][j])flag=0;
	if(!flag)puts("-1");
	else
	{
		printf("%lld\n",cnt);
		for(ll i=1;i<=cnt;++i)printf("%lld %lld\n",ans[i].first,ans[i].second);
	}
	return 0;
}