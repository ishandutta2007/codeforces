#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e3+5;
const ll M=1e4+5;
const ll inf=1e18;

ll read()
{
	ll s=0;
	char c=getchar(),lc='+';
	while (c<'0'||'9'<c) lc=c,c=getchar();
	while ('0'<=c&&c<='9') s=s*10+c-'0',c=getchar();
	return lc=='-'?-s:s;
}
void write(ll x)
{
	if (x<0) putchar('-'),x=-x;
	if (x<10) putchar(x+'0');
	else write(x/10),putchar(x%10+'0');
}
void print(ll x=-1,char c='\n')
{
	write(x);
	putchar(c);
}
struct edge
{
	ll to,nxt,val;
}e[M*2];
ll head[N],cnte=1;
void add_edge(ll u,ll v,ll w)
{
	e[++cnte].to=v;
	e[cnte].val=w;
	e[cnte].nxt=head[u];
	head[u]=cnte;
}
bool vis[N];
ll dis[N],dist[N],dif;
struct node
{
	ll pos,val;
	bool operator <(const node &a)const
	{
		return val>a.val;
	}
};
priority_queue<node>q;
ll dijkstra(ll n,ll S,ll T,bool flag)
{
	for (ll i=1;i<=n;i++) dis[i]=inf,vis[i]=0;
	q.push((node){S,dis[S]=0});
	while (!q.empty())
	{
		ll now=q.top().pos;q.pop();
		if (vis[now]) continue;
		vis[now]=1;
		for (ll i=head[now];i;i=e[i].nxt)
		{
			ll to=e[i].to,val=max(e[i].val,1LL);
			if (flag&&!e[i].val&&dis[now]+val<dist[to]+dif)
			val=e[i].val=e[i^1].val=max(dist[to]+dif-dis[now],1LL);
			if (dis[to]>dis[now]+val)
			{
				dis[to]=dis[now]+val;
				q.push((node){to,dis[to]});
			}
		}
	}
	return dis[T];
}

signed main(signed Goodbye,char *Wangang[])
{
	(void)Goodbye,(void)Wangang;
	ll n=read(),m=read(),L=read(),S=read()+1,T=read()+1;
	for (ll i=1;i<=m;i++)
	{
		ll u=read()+1,v=read()+1,w=read();
		add_edge(u,v,w);
		add_edge(v,u,w);
	}
	if (dijkstra(n,S,T,0)>L) return puts("NO"),0;
	dif=L-dis[T];
	memcpy(dist,dis,sizeof(dist));
	if (dijkstra(n,S,T,1)!=L) return puts("NO"),0;
	puts("YES");
	for (ll i=1;i<=n;i++)
	for (ll j=head[i];j;j=e[j].nxt)
	if (j&1) print(i-1,' '),print(e[j].to-1,' '),print(max(e[j].val,1LL));
	
	return 0;
}