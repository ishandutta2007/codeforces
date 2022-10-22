// By: Little09
// Problem: CF1324F Maximum White Subtree
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1324F
// Memory Limit: 250 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
const int N=200005;
int n;
vector<int>t[N]; 
int a[N];

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
int f[N],g[N];
void dfs1(int u,int fa)
{
	f[u]=a[u];
	for (int i=0;i<t[u].size();i++)
	{
		if (t[u][i]==fa) continue;
		dfs1(t[u][i],u);
		f[u]+=max(0,f[t[u][i]]);
	}
}
void dfs2(int u,int fa)
{
	g[u]=f[u]+max(0,g[fa]-max(0,f[u]));
	for (int i=0;i<t[u].size();i++)
	{
		if (t[u][i]==fa) continue;
		dfs2(t[u][i],u);
	}
}
int main()
{
	n=read();
	for (int i=1;i<=n;i++) a[i]=read()*2-1;
	for (int i=1;i<n;i++)
	{
		int x=read(),y=read();
		t[x].push_back(y),t[y].push_back(x);
	}
	dfs1(1,0);
	dfs2(1,0);
	for (int i=1;i<=n;i++) printf("%d ",g[i]);
	return 0;
}