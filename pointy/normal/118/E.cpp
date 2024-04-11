// By: Little09
// Problem: P3388 
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P3388
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
const int N=500005;
int n,m;
vector<int>t[N],g[N],id[N];
bool vis[N],cut[N],used[N];
int rt[N],cnt,w[N],dis[N],s[N];
int X[N],Y[N];
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
void dfs1(int x,int fa)
{
	vis[x]=1;
	dis[x]=dis[fa]+1;
	for (int i=0;i<t[x].size();i++)
	{
		if (t[x][i]==fa) continue;
		if (vis[t[x][i]]==0) 
		{
			dfs1(t[x][i],x);
			used[id[x][i]]=1;
			g[x].push_back(t[x][i]);
			g[t[x][i]].push_back(x);
		}
		else if (dis[x]>dis[t[x][i]])
		{
			s[x]=min(s[x],dis[t[x][i]]);
		}
	}
}
void dfs2(int x,int fa)
{
	for (int i=0;i<g[x].size();i++)
	{
		if (g[x][i]!=fa) 
		{
			dfs2(g[x][i],x);
			s[x]=min(s[x],s[g[x][i]]);
		}
	}
	if (fa!=0&&s[x]>=dis[x]) cut[x]=1;
}
int main()
{
	n=read(),m=read();
	for (int i=1;i<=m;i++)
	{
		int x=read(),y=read();
		t[x].push_back(y),t[y].push_back(x);
		id[x].push_back(i),id[y].push_back(i);
		X[i]=x,Y[i]=y;
	}
	for (int i=1;i<=n;i++) s[i]=N;
	for (int i=1;i<=n;i++)
	{
		if (vis[i]==0)
		{
			dfs1(i,0),dfs2(i,0);
		}
	}
	for (int i=1;i<=n;i++) 
	{
		if (cut[i]==1)
		{
			puts("0");
			return 0;
		}
	}
	for (int i=1;i<=m;i++)
	{
		int x=X[i],y=Y[i];
		if (dis[x]>dis[y]) swap(x,y); 
		if (used[i]==0) swap(x,y);
		printf("%d %d\n",x,y);
	}
	return 0;
}