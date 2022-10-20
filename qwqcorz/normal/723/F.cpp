#include<bits/stdc++.h>
#define mk make_pair
#define fi first
#define se second
using namespace std;
const int N=2e5+5;
const int M=4e5+5;

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
}e[M*2];
int head[N],cnte=0;
void add_edge(int u,int v)
{
	e[++cnte].to=v;
	e[cnte].nxt=head[u];
	head[u]=cnte;
}
bool vis[N];
int col[N],cnt=0,S[N],T[N],fa[N];
vector<pair<int,int>>ans;
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
void merge(int x,int y)
{
	fa[find(x)]=find(y);
	ans.push_back(mk(x,y));
}
void dfs(int now,int cnt)
{
	vis[now]=1;
	col[now]=cnt;
	for (int i=head[now];i;i=e[i].nxt)
	{
		int to=e[i].to;
		if (vis[to]) continue;
		dfs(to,cnt);
	}
}

signed main(signed Goodbye,char *Wangang[])
{
	(void)Goodbye,(void)Wangang;
	int n=read(),m=read();
	for (int i=1;i<=m;i++)
	{
		int u=read(),v=read();
		add_edge(u,v);
		add_edge(v,u);
	}
	int s=read(),t=read(),ds=read(),dt=read();
	vis[s]=vis[t]=1;
	for (int i=1;i<=n;i++) if (!vis[i]) dfs(i,++cnt);
	for (int i=1;i<=n;i++) fa[i]=i;
	for (int i=head[s];i;i=e[i].nxt) S[col[e[i].to]]=e[i].to;
	for (int i=head[t];i;i=e[i].nxt) T[col[e[i].to]]=e[i].to;
	for (int i=1;i<=cnt;i++) if (!T[i]) merge(s,S[i]),ds--;
	for (int i=1;i<=cnt;i++) if (!S[i]) merge(t,T[i]),dt--;
	for (int i=1,flag=1;i<=cnt;i++) if (S[i]&&T[i])
	{
		if (flag)
		{
			merge(s,S[i]),merge(t,T[i]);
			ds--,dt--,flag=0;
			continue;
		}
		if (ds>0) merge(s,S[i]),ds--;
			 else merge(t,T[i]),dt--;
	}
	for (int i=1;i<=n;i++) if (i!=s&&i!=t)
	for (int j=head[i];j;j=e[j].nxt) if (e[j].to!=s&&e[j].to!=t)
	if (find(i)!=find(e[j].to)) merge(i,e[j].to);
	if (find(s)!=find(t)) merge(s,t),ds--,dt--;
	if (ds<0||dt<0) return puts("No"),0;
	puts("Yes");
	for (auto i:ans) print(i.fi,' '),print(i.se);
	
	return 0;
}