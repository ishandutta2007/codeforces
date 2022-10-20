#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const int D=55;
const int M=N*D;

bool get()
{
	char c=getchar();
	while (c<'0'||'1'<c) c=getchar();
	return c-'0';
}
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
	int to,nxt;
}e[M];
int head[M],cnte=0,u[M],v[M];
void add_edge(int u,int v,bool flag=0)
{
	e[++cnte].to=v;
	e[cnte].nxt=head[u];
	head[u]=cnte;
	if (flag)
	{
//		print(u,','),print(v);
		::u[cnte]=u;
		::v[cnte]=v;
	}
//	else print(u,' '),print(v);
}
bool is[M],vis[M],used[N];
int val[M],pos[M],id[N][D];
int col[M],dfn[M],low[M],cntdfn=0,st[M],top=0,cntcol=0;
int tmp[M];
void tarjan(int now)
{
	vis[now]=1;
	st[++top]=now;
	low[now]=dfn[now]=++cntdfn;
	for (int i=head[now];i;i=e[i].nxt)
	{
		int to=e[i].to;
		if (!dfn[to]) tarjan(to),low[now]=min(low[now],low[to]);
		else if (vis[to]) low[now]=min(low[now],dfn[to]);
	}
	if (low[now]==dfn[now])
	{
		col[now]=++cntcol;
		int cnt=0,x;
		do
		{
			x=st[top--];
			col[tmp[++cnt]=x]=cntcol;
			vis[x]=0;
		}while (x!=now);
		for (int i=1;i<=cnt;i++) if (is[tmp[i]]) val[cntcol]+=!used[pos[tmp[i]]],used[pos[tmp[i]]]=1;
		for (int i=1;i<=cnt;i++) used[pos[tmp[i]]]=0;
	}
}
int dis[M];
int dfs(int now)
{
	if (~dis[now]) return dis[now];
	dis[now]=val[now];
	for (int i=head[now];i;i=e[i].nxt)
	{
		int to=e[i].to;
		dis[now]=max(dis[now],dfs(to)+val[now]);
	}
	return dis[now];
}

signed main()
{
	memset(dis,-1,sizeof(dis));
	int n=read(),m=read(),d=read(),cnt=0;
	for (int i=1;i<=n;i++)
	for (int j=1;j<=d;j++) pos[id[i][j]=++cnt]=i;
	for (int i=1;i<=m;i++)
	{
		int u=read(),v=read();
		for (int j=1;j<=d;j++) add_edge(id[u][j],id[v][j%d+1],1);
	}
	for (int i=1;i<=n;i++)
	for (int j=1;j<=d;j++) is[id[i][j]]=get();
	tarjan(1);
	cnte=0;
	memset(head,0,sizeof(head));
	for (int i=1;i<=m*d;i++)
	if (col[u[i]]&&col[v[i]]&&col[u[i]]!=col[v[i]])
	add_edge(col[u[i]],col[v[i]]);
	print(dfs(col[1]));
	return 0;
}