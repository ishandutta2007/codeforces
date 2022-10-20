#include<bits/stdc++.h>
using namespace std;
const int N=4e5+5;

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
void print(int x=-1,char c='\n')
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
int f[N],g[N],siz[N],Max[N],fa[N],son[N],n;
void dfs0(int now,int father)
{
	fa[now]=father,siz[now]=1,Max[now]=son[now]=f[now]=0;
	for (int i=head[now];i;i=e[i].nxt)
	{
		int to=e[i].to;
		if (to==father) continue;
		dfs0(to,now);
		f[now]=max(f[now],f[to]);
		siz[now]+=siz[to];
		if (Max[now]<siz[to]) Max[now]=siz[to],son[now]=to;
	}
	if (siz[now]<=n/2) f[now]=siz[now];
	if (n-siz[now]>Max[now]) Max[now]=n-siz[now],son[now]=father;
}
void dfs1(int now,int father,int mx)
{
	g[now]=mx=max(mx,n-siz[now]<=n/2?n-siz[now]:0);
	int Max[3]={0,0,0};
	for (int i=head[now];i;i=e[i].nxt)
	{
		int to=e[i].to;
		if (to==father) continue;
		Max[0]=f[to];
		sort(Max,Max+3);
	}
	for (int i=head[now];i;i=e[i].nxt)
	{
		int to=e[i].to;
		if (to==father) continue;
		int tmp=f[to]==Max[2]?Max[1]:Max[2];
		dfs1(to,now,max(mx,tmp));
	}
}

signed main(signed Goodbye,char *Wangang[])
{
	(void)Goodbye,(void)Wangang;
	n=read();
	for (int i=1;i<n;i++)
	{
		int u=read(),v=read();
		add_edge(u,v);
		add_edge(v,u);
	}
	dfs0(1,0);
	dfs1(1,0,0);
//	for (int i=1;i<=n;i++) print(fa[i],' ');puts("");
//	for (int i=1;i<=n;i++) print(son[i],' ');puts("");
//	for (int i=1;i<=n;i++) print(Max[i],' ');puts("");
//	for (int i=1;i<=n;i++) print(f[i],' ');puts("");
//	for (int i=1;i<=n;i++) print(g[i],' ');puts("");
	for (int i=1;i<=n;i++)
	if (son[i]==fa[i]) print(Max[i]-g[i]<=n/2,' ');
				  else print(Max[i]-f[son[i]]<=n/2,' ');
	
	return 0;
}