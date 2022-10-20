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
int mn[N];
void dfs(int now,int father)
{
	mn[now]=min(mn[father],now);
	for (int i=head[now];i;i=e[i].nxt)
	{
		int to=e[i].to;
		if (to==father) continue;
		dfs(to,now);
	}
}

signed main(signed bangumi,char *ss969[])
{
	(void)bangumi,(void)ss969;
	int n=read(),q=read();
	for (int i=1;i<n;i++)
	{
		int u=read(),v=read();
		add_edge(u,v);
		add_edge(v,u);
	}
	read();
	int rt=read()%n+1,ans=rt;
	mn[0]=N;
	dfs(rt,0);
	for (int i=2,lastans=0;i<=q;i++)
	{
		int opt=read(),x=(read()+lastans)%n+1;
		if (opt==1) ans=min(ans,mn[x]);
			   else print(lastans=min(ans,mn[x]));
	}
	
	return 0;
}