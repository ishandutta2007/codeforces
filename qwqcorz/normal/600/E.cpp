#include<bits/stdc++.h>
#define ll long long
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
	int to,nxt;
}e[N*2];
int head[N],cnte=0;
void add_edge(int u,int v)
{
	e[++cnte].to=v;
	e[cnte].nxt=head[u];
	head[u]=cnte;
}
ll ans[N],answer;
int tot[N],Max,siz[N],son[N],a[N];
void insert(int x)
{
	tot[x]++;
	if (tot[x]>Max)
	{
		Max=tot[x];
		answer=x;
	}
	else if (tot[x]==Max) answer+=x;
}
void clear(int now,int father)
{
	answer=Max=tot[a[now]]=0;
	for (int i=head[now];i;i=e[i].nxt)
	{
		int to=e[i].to;
		if (to==father) continue;
		clear(to,now);
	}
}
void add(int now,int father)
{
	insert(a[now]);
	for (int i=head[now];i;i=e[i].nxt)
	{
		int to=e[i].to;
		if (to==father) continue;
		add(to,now);
	}
}
void dfs0(int now,int father)
{
	siz[now]=1,son[now]=0;
	for (int i=head[now];i;i=e[i].nxt)
	{
		int to=e[i].to;
		if (to==father) continue;
		dfs0(to,now);
		siz[now]+=siz[to];
		if (siz[son[now]]<siz[to]) son[now]=to;
	}
}
void dfs1(int now,int father)
{
	for (int i=head[now];i;i=e[i].nxt)
	{
		int to=e[i].to;
		if (to==father||to==son[now]) continue;
		dfs1(to,now);
		clear(to,now);
	}
	if (son[now])
	{
		dfs1(son[now],now);
		for (int i=head[now];i;i=e[i].nxt)
		{
			int to=e[i].to;
			if (to==father||to==son[now]) continue;
			add(to,now);
		}
	}
	insert(a[now]);
	ans[now]=answer;
}

signed main(signed Goodbye,char *Wangang[])
{
	(void)Goodbye,(void)Wangang;
	int n=read();
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=1;i<n;i++)
	{
		int u=read(),v=read();
		add_edge(u,v);
		add_edge(v,u);
	}
	dfs0(1,0);
	dfs1(1,0);
	for (int i=1;i<=n;i++) print(ans[i],' ');
	
	return 0;
}