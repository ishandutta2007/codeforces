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
int f[N],g[N],x[N][25],y[N][25],a[N],n,k;
void dfs0(int now,int father)
{
	for (int i=head[now];i;i=e[i].nxt)
	{
		int to=e[i].to;
		if (to==father) continue;
		dfs0(to,now);
		f[now]^=f[to];
		for (int j=0;j<k;j++) x[now][(j+1)%k]^=x[to][j];
	}
	f[now]^=x[now][0];
	x[now][0]^=a[now];
}
void dfs1(int now,int father,int val)
{
	g[now]=val;
	y[now][0]^=a[now];
	int tmp[25];
	memset(tmp,0,sizeof(tmp));
	for (int j=0;j<k;j++) tmp[(j+1)%k]^=y[now][j];
	for (int i=head[now];i;i=e[i].nxt)
	{
		int to=e[i].to;
		if (to==father) continue;
		for (int j=0;j<k;j++) tmp[(j+2)%k]^=x[to][j];
	}
	val^=f[now];
	for (int i=head[now];i;i=e[i].nxt)
	{
		int to=e[i].to;
		if (to==father) continue;
		for (int j=0;j<k;j++) y[to][j]=tmp[j];
		for (int j=0;j<k;j++) y[to][(j+2)%k]^=x[to][j];
		dfs1(to,now,val^(f[to]^x[to][k-1])^y[to][0]);
	}
}

signed main(signed Recall,char *_902_[])
{
	(void)Recall,(void)_902_;
	n=read(),k=read();
	for (int i=1;i<n;i++)
	{
		int u=read(),v=read();
		add_edge(u,v);
		add_edge(v,u);
	}
	for (int i=1;i<=n;i++) a[i]=read();
	dfs0(1,0);
	dfs1(1,0,0);
	for (int i=1;i<=n;i++) print(!!(f[i]^g[i]),' ');
//	puts("");
//	for (int i=1;i<=n;i++) print(f[i],' ');puts("");
//	for (int i=1;i<=n;i++) print(g[i],' ');puts("");
	
	return 0;
}