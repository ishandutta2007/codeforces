#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
const int inf=1LL<<60;

int read()
{
	int s=0;
	char c=getchar(),lc='+';
	while (c<'0'||'9'<c) lc=c,c=getchar();
	while ('0'<=c&&c<='9') s=s*10+c-'0',c=getchar();
	return lc=='-'?-s:s;
}
void write(int x)
{
	if (x<0) putchar('-'),x=-x;
	if (x<10) putchar(x+'0');
	else write(x/10),putchar(x%10+'0');
}
void print(int x,char c='\n')
{
	write(x);
	putchar(c);
}
struct edge
{
	int to,val,nxt;
}e[N*2];
int head[N],cnt=0;
void add_edge(int u,int v,int w)
{
	e[++cnt].to=v;
	e[cnt].val=w;
	e[cnt].nxt=head[u];
	head[u]=cnt;
}
bool vis[N];
int n,m,Q,dis[N],Dis[N];
struct node
{
	int pos,val;
	bool operator <(const node &a)const
	{
		return val>a.val;
	}
}qwq;
priority_queue<node>q;
void dijkstra()
{
	for (int i=1;i<=n;i++) vis[i]=0;
	for (int i=1;i<=n;i++) dis[i]=inf;
	dis[1]=0;
	q.push((node){1,0});
	while (!q.empty())
	{
		qwq=q.top();
		q.pop();
		int now=qwq.pos;
		if (vis[now]) continue;
		vis[now]=1;
		for (int i=head[now];i;i=e[i].nxt)
		{
			int to=e[i].to,val=e[i].val;
			if (dis[to]>dis[now]+val)
			{
				dis[to]=dis[now]+val;
				q.push((node){to,dis[to]});
			}
		}
	}
}
queue<signed>que[N];
void Dijkstra(int up)
{
	for (int i=1;i<=n;i++) vis[i]=0;
	for (int i=1;i<=n;i++) dis[i]=inf;
	dis[1]=0;
	que[0].push(1);
	for (int i=0;i<=up;i++)
	while (!que[i].empty())
	{
		int now=que[i].front(); que[i].pop();
		if (vis[now]) continue;
		vis[now]=1;
		for (int i=head[now];i;i=e[i].nxt)
		{
			int to=e[i].to,val=e[i].val;
			if (dis[to]>dis[now]+val)
			{
				dis[to]=dis[now]+val;
				if (dis[to]-Dis[to]<=up) que[dis[to]-Dis[to]].push(to);
			}
		}
	}
}

signed main(signed bangumi,char *ss969[])
{
	(void)bangumi,(void)ss969;
	n=read(),m=read(),Q=read();
	for (int i=1;i<=m;i++)
	{
		int u=read(),v=read(),w=read();
		add_edge(u,v,w);
	}
	dijkstra();
	memcpy(Dis,dis,sizeof(dis));
	for (int i=1;i<=Q;i++)
	{
		int opt=read(),x=read();
		if (opt==1)
		{
			if (dis[x]<inf) print(dis[x]);
					   else print(-1);
		}
		else
		{
			for (int i=1;i<=x;i++) e[read()].val++;
			Dijkstra(x);
			for (int i=1;i<=n;i++) Dis[i]=dis[i];
		}
	}

	return 0;
}