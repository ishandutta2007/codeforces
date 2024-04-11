// By: Little09
// Problem: CF1017G The Tree
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1017G
// Memory Limit: 250 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
#define mem(x) memset(x,0,sizeof(x))
const int N=1e5+5,B=600;
int n,m;
int fa[N],q[N][2],f[N];
vector<int>t[N];
bool vis[N],col[N],clr[N];
struct edge
{
	int x,v,s;
};
vector<edge>G[N];
void build(int x,int y,int z,int s)
{
	if (vis[x]==1)
	{
		if (x!=1) 
		{
			edge u=(edge){x,z,s};
			G[y].push_back(u);
		}
		y=x,z=0,s=0;
	}
	else 
	{
		s++;
		if (col[x]==0) z++;
	}
	for (int i:t[x]) build(i,y,z,s);
}
void dfs(int x)
{
	if (col[x]==0)
	{
		col[x]=1;
		return;
	}
	f[x]++;
	for (int i=0;i<G[x].size();i++)
	{
		int u=G[x][i].x,v=G[x][i].v;
		if (v<f[x]) dfs(u);
	}
}
void work(int x)
{
	col[x]=0,clr[x]=1,f[x]=0;
	for (int i=0;i<G[x].size();i++)
	{
		int u=G[x][i].x,s=G[x][i].s;
		G[x][i].v=s;
		work(u);
	}
}
void rebuild(int x,int y,int z)
{
	if (vis[x])
	{
		y=f[x];
		if (clr[x]) z=1;
	}
	else
	{
		if (z) col[x]=0;
		if (col[x]==0&&y!=0) y--,col[x]=1;
	}
	for (int i:t[x]) rebuild(i,y,z);
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

int main()
{
	n=read(),m=read();
	for (int i=2;i<=n;i++) fa[i]=read(),t[fa[i]].push_back(i);
	for (int i=1;i<=m;i++) q[i][0]=read(),q[i][1]=read();
	int l,r=0;
	while (1)
	{
		l=r+1,r=l+B-1;
		if (r>m) r=m;
		if (l>m) return 0;
		mem(vis),mem(f),mem(clr);
		for (int i=l;i<=r;i++) vis[q[i][1]]=1;
		vis[1]=1;
		build(1,1,0,0);
		for (int i=l;i<=r;i++)
		{
			if (q[i][0]==1) dfs(q[i][1]);
			else if (q[i][0]==2) work(q[i][1]);
			else 
			{
				if (col[q[i][1]]==1) printf("black\n");
				else printf("white\n");
			}
		}
		rebuild(1,0,0);
		for (int i=1;i<=n;i++) G[i].clear();
	}
}