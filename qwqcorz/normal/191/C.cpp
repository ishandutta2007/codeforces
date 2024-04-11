#include<bits/stdc++.h>
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
	int to,nxt,w;
}e[N*2];
int head[N],cnt=0;
void add(int u,int v,int w)
{
	e[++cnt].to=v;
	e[cnt].w=w;
	e[cnt].nxt=head[u];
	head[u]=cnt;
}
int fa[N][23],dep[N],a[N],ans[N];
void dfs1(int now,int f,int d)
{
	dep[now]=d;
	fa[now][0]=f;
	for (int i=head[now];i;i=e[i].nxt)
	if (e[i].to!=f)
	dfs1(e[i].to,now,d+1);
}
void dfs2(int now,int f)
{
	for (int i=head[now];i;i=e[i].nxt)
	if (e[i].to!=f)
	{
		int to=e[i].to;
		dfs2(to,now);
		a[now]+=a[to];
		ans[e[i].w]=a[to];
	}
}
int find(int u,int v)
{
	int now=20;
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

int main()
{
	memset(a,0,sizeof(a));
	int n=read();
	for (int i=1;i<n;i++)
	{
		int u=read(),v=read();
		add(u,v,i);
		add(v,u,i);
	}
	dfs1(1,0,1);
	for (int j=1;j<=20;j++)
	for (int i=1;i<=n;i++) fa[i][j]=fa[fa[i][j-1]][j-1];
	int m=read();
	for (int i=1;i<=m;i++)
	{
		int u=read(),v=read(),f=find(u,v);
		a[u]++;
		a[v]++;
		a[f]-=2;
	}
	dfs2(1,0);
	for (int i=1;i<n;i++) print(ans[i],' ');

	return 0;
}