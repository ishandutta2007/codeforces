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
void print(int x,char c='\n')
{
	write(x);
	putchar(c);
}
unordered_map<int,int>e[N];
set<int>to[N];
int fa[N];
int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
bool query(int u,int v)
{
	int x=find(u),y=find(v);
	if (x==y) return 1;
	if (to[x].find(v)!=to[x].end()) return 1;
	return 0;
}
void merge(int u,int v)
{
	u=find(u),v=find(v);
	if (u==v) return;
	if (to[u].size()>to[v].size()) swap(u,v);
	for (int i:to[u]) to[v].insert(i);
	fa[u]=v;
}
void add_edge(int u,int v,int w)
{
	to[find(u)].insert(v);
	if (e[u].count(w)) merge(e[u][w],v);
				  else e[u][w]=v;
}

signed main()
{
	int n=read(),m=read(),c=read(),Q=read();
	for (int i=1;i<=n;i++) fa[i]=i;
	for (int i=1;i<=m;i++)
	{
		int u=read(),v=read(),w=read();
		add_edge(u,v,w);
		add_edge(v,u,w);
	}
	while (Q--)
	{
		char c; cin>>c;
		int u=read(),v=read();
		if (c=='+')
		{
			int w=read();
			add_edge(u,v,w);
			add_edge(v,u,w);
		}
		else puts(query(u,v)?"Yes":"No");
	}
	
	return 0;
}