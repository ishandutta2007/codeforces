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
bool vis[N],ch[N];
int low[N],dfn[N],cntdfn=0,col[N],cntcol=0,st[N],top=0;
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
		int c=++cntcol,x;
		do
		{
			x=st[top--];
			col[x]=c;
			vis[x]=0;
		}while (x!=now);
	} 
}
void dfs(int now)
{
	ch[now]=1;
	for (int i=head[now];i;i=e[i].nxt)
	{
		int to=e[i].to;
		if (!ch[to]) dfs(to);
	}
}
bool _2sat(int n)
{
	for (int i=1;i<=n;i++) if (!dfn[i]) tarjan(i);
	if (cntcol==1) return 0;
	for (int i=1;i<=n;i++) if (col[i]==1) return dfs(i),1;
	assert(0);
}
void clear(int n)
{
	for (int i=1;i<=n;i++)
	head[i]=low[i]=dfn[i]=col[i]=vis[i]=ch[i]=0;
	cnte=cntdfn=cntcol=top=0;
}

signed main(signed Goodbye,char *Wangang[])
{
	(void)Goodbye,(void)Wangang;
	int T=read();
	while (T--)
	{
		int n=read(),m=read();
		for (int i=1;i<=m;i++)
		{
			int u=read(),v=read();
			if (u==v) continue;
			add_edge(u,v);
		}
		if (_2sat(n))
		{
			puts("Yes");
			int cnt=0;
			for (int i=1;i<=n;i++) cnt+=ch[i];
			print(cnt,' '),print(n-cnt);
			for (int i=1;i<=n;i++) if (ch[i]) print(i,' ');;puts("");
			for (int i=1;i<=n;i++) if (!ch[i]) print(i,' ');;puts("");
		}
		else puts("No");
		clear(n);
	}
	
	return 0;
}