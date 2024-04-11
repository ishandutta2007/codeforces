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
void clear(int n)
{
	for (int i=1;i<=n;i++) head[i]=0;
	cnte=0;
}
int siz0[N],siz1[N],is[N],fa[N];
void dfs(int now,int father)
{
	fa[now]=father;
	siz0[now]=siz1[now]=0,is[now]=1;
	for (int i=head[now];i;i=e[i].nxt)
	{
		int to=e[i].to;
		if (to==father) continue;
		is[now]=0;
		dfs(to,now);
		if (is[to]) siz0[now]++;
			   else siz1[now]++;
	}
}

signed main(signed Goodbye,char *Wangang[])
{
	(void)Goodbye,(void)Wangang;
	int T=read();
	while (T--)
	{
		int n=read(),ans=0;
		for (int i=1;i<n;i++)
		{
			int u=read(),v=read();
			add_edge(u,v);
			add_edge(v,u);
		}
		dfs(1,0);
		queue<int>q;
		for (int i=2;i<=n;i++) if (!siz1[i]&&siz0[i]) q.push(i);
		while (!q.empty())
		{
			int now=q.front(); q.pop();
			ans+=siz0[now]-1;
			int father=fa[now];
			siz1[father]--;
			if (!siz1[father]&&father>1)
			{
				if (siz0[father]) q.push(father);
				else
				{
					siz1[fa[father]]--;
					siz0[fa[father]]++;
					if (!siz1[fa[father]]&&fa[father]>1) q.push(fa[father]);
				}
			}
		}
		print(ans+=max(siz0[1],1));
		clear(n);
	}
	
	return 0;
}