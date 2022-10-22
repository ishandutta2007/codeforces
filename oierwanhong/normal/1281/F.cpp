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
#define MAXN 3011
struct Edge
{
	ll v,nxt;
}e[MAXN<<1|1];
ll cnt=0,last[MAXN];
void adde(ll u,ll v)
{
	e[++cnt].v=v;
	e[cnt].nxt=last[u],last[u]=cnt;
}

ll a[MAXN],size[MAXN];
pll f[MAXN][MAXN],tmp[MAXN];
void upd(pll &a,pll t)
{
	if(t>a)a=t;
}
void dp(ll u,ll fa=0)
{
	size[u]=1;
	f[u][1]=pll(0,a[u]);
	for(ll i=last[u];i;i=e[i].nxt)
	{
		ll v=e[i].v;
		if(v==fa)continue;
		dp(v,u);
		for(ll j=1;j<=size[u]+size[v];++j)tmp[j]=pll(-1,0);
		for(ll j=1;j<=size[u];++j)
			for(ll k=1;k<=size[v];++k)
			{
				upd(tmp[j+k],pll(f[u][j].first+f[v][k].first+(f[v][k].second>0),f[u][j].second));
				upd(tmp[j+k-1],pll(f[u][j].first+f[v][k].first,f[u][j].second+f[v][k].second));
			}
		for(ll j=1;j<=size[u]+size[v];++j)f[u][j]=tmp[j];
		size[u]+=size[v];
	}
}
int main()
{
	ll task=read();
	while(task--)
	{
		ll n=read(),m=read();
		for(ll i=1;i<=n;++i)a[i]=-read();
		for(ll i=1;i<=n;++i)a[i]+=read();
		for(ll i=1;i<n;++i)
		{
			ll u=read(),v=read();
			adde(u,v),adde(v,u);
		}
		dp(1);
		printf("%lld\n",f[1][m].first+(f[1][m].second>0));
		
		cnt=0;
		for(ll i=1;i<=n;++i)
		{
			last[i]=0;
			for(ll j=1;j<=m;++j)f[i][j]=pll(0,0);
		}
		//clear();
	}
	return 0;
}