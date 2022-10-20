#include<bits/stdc++.h>
using namespace std;
const int N=3e5+5;

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
struct graph
{
	struct node
	{
		int to,nxt,val;
	}e[N*2];
	int head[N],cnte;
	void add_edge(int u,int v,int w)
	{
		e[++cnte].to=v;
		e[cnte].val=w;
		e[cnte].nxt=head[u];
		head[u]=cnte;
	}
}g,t;
bool vis[N];
int low[N],dfn[N],cntdfn=0,st[N],top=0,col[N],cntcol=0;
void tarjan(int now,int father)
{
	vis[st[++top]=now]=1;
	low[now]=dfn[now]=++cntdfn;
	for (int i=g.head[now];i;i=g.e[i].nxt)
	{
		int to=g.e[i].to;
		if (to==father) continue;
		if (!dfn[to]) tarjan(to,now),low[now]=min(low[now],low[to]);
		else if (vis[to]) low[now]=min(low[now],dfn[to]);
	}
	if (low[now]==dfn[now])
	{
		int tmp;cntcol++;
		do col[tmp=st[top--]]=cntcol,vis[tmp]=0;while (tmp!=now);
	}
}
int val[N];
int dfs(int now,int father,int end,int v)
{
	v|=val[now];
	if (now==end) return v;
	for (int i=t.head[now];i;i=t.e[i].nxt)
	{
		int to=t.e[i].to;
		if (to==father) continue;
		int tmp=dfs(to,now,end,v|t.e[i].val);
		if (~tmp) return tmp;
	}
	return -1;
}
map<int,int>mp[N];

signed main(signed Goodbye,char *Wangang[])
{
	(void)Goodbye,(void)Wangang;
	int n=read(),m=read();
	for (int i=1;i<=m;i++)
	{
		int u=read(),v=read(),w=read();
		g.add_edge(u,v,w);
		g.add_edge(v,u,w);
	}
	tarjan(1,0);
	for (int i=1;i<=n;i++)
	for (int j=g.head[i];j;j=g.e[j].nxt)
	{
		int to=g.e[j].to;
		if (col[i]==col[to]) val[col[i]]|=g.e[j].val;
		else mp[col[i]][col[to]]|=g.e[j].val;
	}
	for (int i=1;i<=cntcol;i++)
	for (auto j:mp[i]) t.add_edge(i,j.first,j.second);
	int s=read(),t=read();
	puts(dfs(col[s],0,col[t],0)?"YES":"NO");
	
	return 0;
}