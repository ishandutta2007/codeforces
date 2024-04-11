// By: Little09
// Problem: CF570D Tree Requests
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF570D
// Memory Limit: 250 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;

const int N=500005;
int n,m; 
int son[N],siz[N];
vector<int>G[N];
int dfn[N],rk[N],tot,dis[N];
char a[N];
bool f[N][27],ans[N];
int g[N];
struct point
{
	int id,x;
};
vector<point>q[N];
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
inline char readchar()
{
	char C=getchar();
    while (C<33||C>126) C=getchar();
    return C;
}
void dfs1(int x)
{
	siz[x]=1,son[x]=-1;
	dfn[x]=++tot,rk[tot]=x;
	for (int i:G[x])
	{
		dis[i]=dis[x]+1;
		dfs1(i);
		siz[x]+=siz[i];
		if (son[x]==-1||siz[son[x]]<siz[i]) son[x]=i;
	}
}
void dfs2(int x,bool t)
{
	//cout << x << " " << t << endl;
	for (int i:G[x])
	{
		if (i==son[x]) continue;
		dfs2(i,0);
	}
	if (son[x]!=-1) dfs2(son[x],1);
	for (int i:G[x])
	{
		if (i==son[x]) continue;
		for (int j=dfn[i];j<dfn[i]+siz[i];j++)
		{
			int u=rk[j];
			f[dis[u]][a[u]-'a']^=1;
			if (f[dis[u]][a[u]-'a']==1) g[dis[u]]++;
			else g[dis[u]]--;
		}
	}
	f[dis[x]][a[x]-'a']^=1;
	if (f[dis[x]][a[x]-'a']==1) g[dis[x]]++;
	else g[dis[x]]--;
	for (point i:q[x]) ans[i.id]=(g[i.x]<=1);
	if (t==0)
	{
		for (int j=dfn[x];j<dfn[x]+siz[x];j++)
		{
			int u=rk[j];
			f[dis[u]][a[u]-'a']=0;
			g[dis[u]]=0;
		}
	}
}
int main()
{
	n=read(),m=read();
	for (int i=2;i<=n;i++)
	{
		int x=read();
		G[x].push_back(i);
	}
	dis[1]=1;
	for (int i=1;i<=n;i++) a[i]=readchar();
	dfs1(1);
	//cout << endl;
	for (int i=1;i<=m;i++)
	{
		int x=read(),y=read();
		point u;
		u.id=i,u.x=y;
		q[x].push_back(u);
	}
	dfs2(1,0);
	for (int i=1;i<=m;i++)
	{
		if (ans[i]) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}