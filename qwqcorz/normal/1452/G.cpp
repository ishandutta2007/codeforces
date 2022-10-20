#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;

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
}e[N*2];
int head[N],cnte=0;
void add_edge(int u,int v)
{
	e[++cnte].to=v;
	e[cnte].nxt=head[u];
	head[u]=cnte;
}
int dis[N],ans[N],q[N],p[N],g[N];
void dfs(int now,int d,int z)
{
	if (g[now]>=d-z) return;
	g[now]=d-z;
	ans[now]=max(ans[now],d);
	for (int i=head[now];i;i=e[i].nxt) dfs(e[i].to,d,z+1);
}

signed main(signed bangumi,char *ss969[])
{
	(void)bangumi,(void)ss969;
	int n=read();
	for (int i=1;i<n;i++)
	{
		int u=read(),v=read();
		add_edge(u,v);
		add_edge(v,u);
	}
	memset(dis,-1,sizeof(dis));
	int m=read(),h=1,t=m;
	for (int i=1;i<=m;i++) dis[q[i]=read()]=0;
	while (h<=t)
	{
		int now=q[h++];
		for (int i=head[now];i;i=e[i].nxt)
		{
			int to=e[i].to;
			if (!~dis[to]) dis[q[++t]=to]=dis[now]+1;
		}
	}
	for (int i=1;i<=n;i++) p[i]=i;
	sort(p+1,p+1+n,[&](int x,int y){return dis[x]>dis[y];});
	for (int i=1;i<=n;i++)
	{
		int now=p[i];
		dfs(now,dis[now],0);
	}
	for (int i=1;i<=n;i++) print(ans[i],' ');
	
	return 0;
}