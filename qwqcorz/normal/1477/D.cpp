#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;

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
int siz[N],fa[N],p[N],q[N];
bool vis[N],is[N];
vector<int>to[N],son[N];
void output(int n)
{
//	for (int i=1;i<=n;i++) print(p[i],' ');
//	puts("");
	for (int i=1;i<=n;i++) q[p[i]]=i;
	for (int i=1;i<=n;i++) print(q[i],' ');
	puts("");
}
void clear(int n)
{
	cnte=0;
	for (int i=1;i<=n;i++) to[i].clear(),son[i].clear();
	for (int i=1;i<=n;i++) head[i]=siz[i]=fa[i]=is[i]=0;
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
			add_edge(u,v);
			add_edge(v,u);
			siz[u]++,siz[v]++;
		}
		for (int i=1;i<=n;i++) if (siz[i]==n-1) is[i]=1;
		set<int>S;
		for (int i=1;i<=n;i++) if (!is[i]) S.insert(i);
		for (int i=1;i<=n;i++) if (!is[i])
		{
			for (int j=head[i];j;j=e[j].nxt) vis[e[j].to]=1;
			for (auto j=S.begin(),nxt=j;j!=S.end();j=nxt)
			{
				nxt++;
				if (vis[*j]||i==*j) continue;
				if (!is[*j])
					to[i].push_back(*j),
					to[*j].push_back(i);
				S.erase(i);
				S.erase(j);
			}
			for (int j=head[i];j;j=e[j].nxt) vis[e[j].to]=0;
		}
//		for (int i=1;i<=n;i++)
//		for (int j:to[i]) print(i,','),print(j);
		for (int i=1;i<=n;i++) siz[i]=0;
		for (int i=1;i<=n;i++) if (!is[i]&&!fa[i])
		{
			int x=0;
			for (int j:to[i]) if (fa[j]) x=j;
			if (x)
			{
				if (fa[x]==x) siz[fa[i]=x]++;
				else if (siz[fa[x]]>2) siz[fa[x]]--,siz[fa[x]=i,fa[i]=i]=2;
				else siz[fa[fa[x]]=x,fa[i]=x,fa[x]=x]=3;
			}
			else
			{
				siz[fa[i]=i]=1;
				for (int j:to[i]) siz[fa[j]=i]++;
			}
//			print(i);
//			for (int i=1;i<=n;i++) print(fa[i],' ');puts("");
		}
//		for (int i=1;i<=n;i++) print(fa[i]);
		for (int i=1;i<=n;i++) if (!is[i]&&fa[i]!=i) son[fa[i]].push_back(i);
		int cnt=0;
		for (int i=1;i<=n;i++) if (is[i]) p[++cnt]=i;
		for (int i=1;i<=n;i++) if (!son[i].empty())
		{
			p[++cnt]=i;
			for (int j:son[i]) p[++cnt]=j;
		}
		output(n);
		cnt=0;
		for (int i=1;i<=n;i++) if (is[i]) p[++cnt]=i;
		for (int i=1;i<=n;i++) if (!son[i].empty())
		{
			for (int j:son[i]) p[++cnt]=j;
			p[++cnt]=i;
		}
		output(n);
		clear(n);
	}
	
	return 0;
}
/*
1
10 38
5 9
7 2
1 7
4 2
5 10
9 7
6 3
4 7
6 8
6 9
5 6
4 8
3 9
3 4
2 10
8 7
1 10
8 10
9 1
2 1
4 6
3 8
7 10
5 3
1 3
5 1
8 5
10 4
10 9
9 2
7 3
7 6
4 5
10 6
4 9
4 1
1 6
6 2
*/