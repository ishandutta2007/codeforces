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
#define MAXN 500011
struct Edge
{
	ll v,nxt;
}e[MAXN];
ll cnt=0,last[MAXN];
void adde(ll u,ll v)
{
	e[++cnt].v=v;
	e[cnt].nxt=last[u],last[u]=cnt;
}

ll dis[MAXN],f[MAXN],ord[MAXN];
std::queue<ll>q;
void bfs(ll s)
{
	dis[s]=1;f[s]=1;
	q.push(s);
	while(!q.empty())
	{
		ll u=q.front();q.pop();
		for(ll i=last[u];i;i=e[i].nxt)
		{
			ll v=e[i].v;
			if(!dis[v])
			{
				dis[v]=dis[u]+1;q.push(v);
			}
			if(dis[v]==dis[u]+1)++f[v];
		}
	}
}
ll a[MAXN];
int main()
{
	ll n=read(),m=read();
	for(ll i=1;i<=m;++i)
	{
		ll u=read(),v=read();
		adde(v,u);
	}
	ll p=read(),minv=0,maxv=0;
	for(ll i=1;i<=p;++i)a[i]=read();
	bfs(a[p]);
	//for(ll i=1;i<=n;++i)printf("%lld ",f[i]);
	//putchar('\n');
	for(ll i=2;i<=p;++i)
	{
		if(dis[a[i]]+1!=dis[a[i-1]])++minv,++maxv;
		else
		{
			if(f[a[i-1]]>1)++maxv;
		}
	}
	printf("%lld %lld",minv,maxv);
	return 0;
}