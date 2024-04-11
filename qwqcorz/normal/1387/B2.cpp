#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;

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
void print(int x,char c='\n')
{
	write(x);
	putchar(c);
}
struct edge
{
	int to,nxt;
}e[N*2];
int head[N],cnte=0;
void add(int u,int v)
{
	e[++cnte].to=v;
	e[cnte].nxt=head[u];
	head[u]=cnte;
}
bool vis[N];
int n,u[N],v[N],fa[N],son[N],siz[N],Max[N],h,cnt=0;
void push(int x,int y)
{
	cnt++;
	u[cnt]=x;
	v[cnt]=y;
}
void dfs(int now)
{
	siz[now]=1;
	Max[now]=son[now]=0;
	for (int i=head[now];i;i=e[i].nxt)
	{
		int to=e[i].to;
		if (to==fa[now]) continue;
		fa[to]=now;
		dfs(to);
		siz[now]+=siz[to];
		Max[now]=max(Max[now],siz[to]);
		if (!vis[to])
		{
			vis[now]=vis[to]=1;
			push(now,to);
		}
		son[now]=to;
	}
	if (son[now]&&!vis[now]&&!fa[now])
	{
		vis[now]=1;
		push(now,son[now]);
	}
	Max[now]=max(Max[now],n-siz[now]);
	if (Max[now]<=n/2) h=now;
}
namespace nmsl_1
{
	vector<int>alb[N];
	int fa[N],to[N];
	int find(int x)
	{
		return x==fa[x]?x:fa[x]=find(fa[x]);
	}
	void merge(int x,int y)
	{
		fa[find(x)]=find(y);
	}
	void solve()
	{
		for (int i=1;i<=n;i++) fa[i]=i;
		for (int i=1;i<=cnt;i++) merge(u[i],v[i]);
		for (int i=1;i<=n;i++) alb[find(i)].push_back(i);
		for (int i=1;i<=n;i++)
		if (alb[i].size())
		{
			for (int j=0;j<alb[i].size()-1;j++) to[alb[i][j]]=alb[i][j+1];
			to[alb[i][alb[i].size()-1]]=alb[i][0];
		}
		for (int i=1;i<=n;i++) print(to[i],' ');
		putchar('\n');
	}
}
namespace nmsl_2
{
	int dfn[N],cnt=0,alb[N];
	void dfs(int now,int fa)
	{
		dfn[++cnt]=now;
		for (int i=head[now];i;i=e[i].nxt)
		{
			int to=e[i].to;
			if (to==fa) continue;
			dfs(to,now);
		}
	}
	int solve()
	{
		dfs(h,0);
		int ans=0;
		for (int i=1;i<=n;i++) ans+=min(siz[i],n-siz[i])*2;
		for (int i=1;i<=n;i++) alb[dfn[i]]=dfn[(i+n/2-1)%n+1];
		return ans;
	}
	void Print()
	{
		for (int i=1;i<=n;i++) print(alb[i],' ');
	}
}

signed main()
{
	memset(vis,0,sizeof(vis));
	n=read();
	for (int i=1;i<n;i++)
	{
		int u=read(),v=read();
		add(u,v);
		add(v,u);
	}
	dfs(1);
	print(nmsl_2::solve());
	nmsl_2::Print();

	return 0;
}