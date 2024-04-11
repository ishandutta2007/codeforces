//Wan Hong 2.2
//home
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
typedef long long ll;
typedef std::pair<ll,ll> pll;
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
#define MAXN 1011
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

ll leaf[5],leaf_cnt=0;
bool vis[MAXN];
void dfs(ll u,ll fa)
{
	ll x=0;
	for(ll i=last[u];i;i=e[i].nxt)
	{
		ll v=e[i].v;
		if(vis[v]||v==fa)continue;
		++x;
		dfs(v,u);
	}
	if(!x)
	{
		if(leaf_cnt<2)leaf[++leaf_cnt]=u;
	}
}
int main()
{
	ll n=read(),rt=1;
	for(ll i=1;i<n;++i)
	{
		ll u=read(),v=read();
		adde(u,v),adde(v,u);
	}
	for(ll i=1;i<=n/2;++i)
	{
		dfs(rt,0);
		ll x,y;
		if(leaf_cnt==2)x=leaf[1],y=leaf[2];
		else if(leaf_cnt==1)x=rt,y=leaf[1];
		else
		{
			std::cout<<"! "<<rt<<std::endl;
			return 0;
		}
		std::cout<<"? "<<x<<" "<<y<<std::endl;
		ll lca=read();
		if(lca==x||lca==y)
		{
			std::cout<<"! "<<lca<<std::endl;
			return 0;
		}
		vis[x]=vis[y]=1;leaf_cnt=0;
		rt=lca;
	}
	std::cout<<"! "<<rt<<std::endl;
	return 0;
}