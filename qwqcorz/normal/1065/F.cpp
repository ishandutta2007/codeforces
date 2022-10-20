#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;

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
}e[N];
int head[N],cnt=0;
void add(int u,int v)
{
	e[++cnt].to=v;
	e[cnt].nxt=head[u];
	head[u]=cnt;
}
int n,k,f[N],g[N],d[N],low[N];
void dfs(int now,int deep)
{
	low[now]=n;
	d[now]=deep;
	g[now]=f[now]=0;
	if (!head[now])
	{
		g[now]=1;
		low[now]=deep;
	}
	for (int i=head[now];i;i=e[i].nxt)
	{
		int to=e[i].to;
		dfs(to,deep+1);
		low[now]=min(low[now],low[to]);
		if (low[to]-d[now]<=k)
		{
			g[now]+=g[to];
			f[now]=max(f[now],f[to]-g[to]);
		}
		else f[now]=max(f[now],f[to]);
	}
	f[now]+=g[now];
}

signed main()
{
	n=read();
	k=read();
	for (int i=2;i<=n;i++)
	{
		int fa=read();
		add(fa,i);
	}
	dfs(1,0);
	print(f[1]);
//	for (int i=1;i<=n;i++)
//	{
//		print(g[i],' ');
//		print(f[i]);
//	}

	return 0;
}