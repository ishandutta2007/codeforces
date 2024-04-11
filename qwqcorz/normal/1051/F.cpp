#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e5+5;
const ll inf=1ll<<60;

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
	if (x<0)
	{
		putchar('-');
		x=-x;
	}
	if (x<10) putchar(x+'0');
	else
	{
		write(x/10);
		putchar(x%10+'0');
	}
}
void print(ll x,char c='\n')
{
	write(x);
	putchar(c);
}
struct edge
{
	ll to,val,nxt;
}e[N*2];
ll head[N],cnt=0;
void add(ll u,ll v,ll w)
{
	e[++cnt].to=v;
	e[cnt].val=w;
	e[cnt].nxt=head[u];
	head[u]=cnt;
}
ll fa[N][23],dep[N],diss[N];
ll f[N],dis[N][25][2],ed[25],cntt=0;
ll ff(ll x){return f[x]==x?x:f[x]=ff(f[x]);}
struct node
{
	ll val,pos;
	bool operator <(const node &a)const
	{
		return val>a.val;
	}
}qwq;
bool vis[N];
priority_queue<node>h;
void dijkstra(ll s,ll n,ll xx,ll yy)
{
	memset(vis,0,sizeof(vis));
	for (ll i=1;i<=n;i++) dis[i][xx][yy]=inf;
	while (!h.empty()) h.pop();
	dis[s][xx][yy]=0;
	h.push((node){0,s});
	while (!h.empty())
	{
		qwq=h.top();
		h.pop();
		ll now=qwq.pos;
		if (vis[now]) continue;
		vis[now]=1;
		for (ll i=head[now];i;i=e[i].nxt)
		{
			ll to=e[i].to,val=e[i].val;
			if (dis[to][xx][yy]>dis[now][xx][yy]+val)
			{
				dis[to][xx][yy]=dis[now][xx][yy]+val;
				h.push((node){dis[to][xx][yy],to});
			}
		}
	}
}
void dfs(ll now,ll f,ll d,ll di)
{
	dep[now]=d;
	diss[now]=di;
	fa[now][0]=f;
	for (ll i=head[now];i;i=e[i].nxt)
	if (e[i].to!=f)
	dfs(e[i].to,now,d+1,di+e[i].val);
}
ll find(ll u,ll v)
{
	ll now=20;
	do
	{
		if (dep[u]<dep[v]) swap(u,v);
		if (dep[u]-dep[v]>=(1<<now)) u=fa[u][now];
		now--;
	}
	while (dep[u]!=dep[v]);
	if (u==v) return u;
	for (now=20;now>=0;now--)
	if (fa[u][now]!=fa[v][now])
	{
		u=fa[u][now];
		v=fa[v][now];
	}
	return fa[u][0];
}
ll u[N],v[N],w[N],cnttt=0;

int main()
{
	ll n=read(),m=read();
	for (ll i=1;i<=n;i++) f[i]=i;
	for (ll i=1;i<=n;i++)
	for (ll j=0;j<=23;j++) dis[i][j][0]=dis[i][j][1]=inf;
	for (ll i=1;i<=m;i++)
	{
		u[i]=read();
		v[i]=read();
		w[i]=read();
		ll x=ff(u[i]),y=ff(v[i]);
		if (x!=y)
		{
			add(u[i],v[i],w[i]);
			add(v[i],u[i],w[i]);
			f[x]=y;
			w[i]=0;
		}
	}
	dfs(1,0,1,0);
	for (int j=1;j<=20;j++)
	for (int i=1;i<=n;i++) fa[i][j]=fa[fa[i][j-1]][j-1];
	for (ll i=1;i<=m;i++)
	if (w[i])
	{
		add(u[i],v[i],w[i]);
		add(v[i],u[i],w[i]);
	}
	for (ll i=1;i<=m;i++)
	if (w[i])
	{
		ed[++cntt]=i;
		dijkstra(u[i],n,cntt,0);
		dijkstra(v[i],n,cntt,1);
	}
	ll q=read();
	while (q--)
	{
		ll x=read(),y=read(),fath=find(x,y);
		ll ans=diss[x]+diss[y]-diss[fath]*2;
		for (ll i=1;i<=cntt;i++)
		{
			ans=min(ans,dis[x][i][0]+dis[y][i][1]+w[ed[i]]);
			ans=min(ans,dis[x][i][1]+dis[y][i][0]+w[ed[i]]);
		}
		print(ans);
	}

	return 0;
}