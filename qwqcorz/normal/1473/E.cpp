#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=2e5+5;
const ll inf=1LL<<60;

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
	int to,val,nxt;
}e[N*32];
int head[N*4],cnte=0;
void add_edge(int u,int v,int w)
{
	e[++cnte].to=v;
	e[cnte].val=w;
	e[cnte].nxt=head[u];
	head[u]=cnte;
}
struct node
{
	ll pos,val;
	bool operator <(const node &a)const
	{
		return val>a.val;
	}
}qwq;
priority_queue<node>q;
ll dis[N*4];
bool vis[N*4];
void dijkstra(ll n)
{
	for (ll i=1;i<=n;i++) vis[i]=0;
	for (ll i=1;i<=n;i++) dis[i]=inf;
	while (!q.empty()) q.pop();
	q.push((node){1,0});
	dis[1]=0;
	while (!q.empty())
	{
		qwq=q.top();
		q.pop();
		ll now=qwq.pos;
		if (vis[now]) continue;
		vis[now]=1;
		for (ll i=head[now];i;i=e[i].nxt)
		{
			ll to=e[i].to,val=e[i].val;
			if (dis[to]>dis[now]+val)
			{
				dis[to]=dis[now]+val;
				q.push((node){to,dis[to]});
			}
		}
	}
}
ll cnt=0,id[N][2][2];

signed main(signed Recall,char *_902_[])
{
	(void)Recall,(void)_902_;
	ll n=read(),m=read();
	for (ll i=1;i<=n;i++)
	for (ll j=0;j<4;j++)
	id[i][j&1][j>>1]=++cnt;
	for (ll i=1;i<=m;i++)
	{
		ll u=read(),v=read(),w=read();
		for (ll j=0;j<=1;j++)
		for (ll k=0;k<=1;k++)
		for (ll x=0;x+j<=1;x++)
		for (ll y=0;y+k<=1;y++)
		add_edge(id[u][j][k],id[v][j|x][k|y],w*(1+x-y)),
		add_edge(id[v][j][k],id[u][j|x][k|y],w*(1+x-y));
	}
	dijkstra(cnt);
	for (ll i=2;i<=n;i++) print(dis[id[i][1][1]],' ');puts("");
	
	return 0;
}