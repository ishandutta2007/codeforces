// Author: Little09
// Problem: C. DFS Trees
// Contest: Codeforces Round #808 (Div. 1)
// URL: https://codeforces.com/contest/1707/problem/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;

const int N=500005;
int n,m; 
int fafa[N];
vector<int>t[N];
int u[N][2],cnt,s[N],a[N];
int find(int x)
{
	if (x==fafa[x]) return x;
	return fafa[x]=find(fafa[x]);
}
void add(int x,int y)
{
	t[x].push_back(y);
	t[y].push_back(x);
}
int fa[N][21],deth[N];
void dfs(int x,int f)
{
	fa[x][0]=f,deth[x]=deth[f]+1;
	for (int i=1;i<=20;i++) fa[x][i]=fa[fa[x][i-1]][i-1];
	for (int i:t[x])
	{
		if (i==f) continue;
		dfs(i,x);
	}
}
int LCA(int x,int y)
{
	if (deth[x]<deth[y]) swap(x,y);
	for (int i=20;i>=0;i--) if (deth[fa[x][i]]>=deth[y]) x=fa[x][i];
	if (x==y) return x;
	for (int i=20;i>=0;i--) if (fa[x][i]!=fa[y][i]) x=fa[x][i],y=fa[y][i];
	return fa[x][0];
}
void dfs2(int x,int f)
{
	for (int i:t[x])
	{
		if (i==f) continue;
		s[i]+=s[x];
		dfs2(i,x);
	}
}
inline int read()
{
    int F=1,ANS=0;
	char C=getchar();
    while (C<'0'||C>'9')
	{
		if (C=='-') F=-1;
		C=getchar();
	}
    while (C>='0'&&C<='9')
	{
		ANS=ANS*10+C-'0';
		C=getchar();
	}
    return F*ANS;
}
int jum(int x,int y)
{
	for (int i=20;i>=0;i--) if (deth[fa[x][i]]>deth[y]) x=fa[x][i];
	return x;
}

int main()
{
	n=read(),m=read();
	for (int i=1;i<=n;i++) fafa[i]=i;
	for (int i=1;i<=m;i++)
	{
		int x=read(),y=read();
		int x1=find(x),y1=find(y);
		if (x1==y1)
		{
			u[++cnt][0]=x,u[cnt][1]=y;
		}
		else fafa[x1]=y1,add(x,y);
	}
	int rt=1;
	dfs(rt,0);
	for (int i=1;i<=cnt;i++)
	{
		int lca=LCA(u[i][0],u[i][1]);
		if (lca==u[i][0])
		{
			s[u[i][1]]++;
			int v=jum(u[i][1],u[i][0]);
			s[v]--,s[rt]++;
		}
		else if (lca==u[i][1])
		{
			s[u[i][0]]++;
			int v=jum(u[i][0],u[i][1]);
			s[v]--,s[rt]++;
		}
		else
		{
			s[u[i][0]]++;
			s[u[i][1]]++;
		}
	}
	dfs2(rt,0);
	for (int i=1;i<=n;i++)
	{
		if (s[i]==m-n+1) printf("1");
		else printf("0");
	}
	return 0;
}