// By: Little09
// Problem: CF734E Anton and Tree
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF734E
// Memory Limit: 250 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
const int N=400005;
int a[N],dis[N];
int n;
int t[N],nxt[N],cnt,h[N];
void add(int x,int y)
{
	t[++cnt]=y;
	nxt[cnt]=h[x];
	h[x]=cnt;
}
void dfs(int x,int fa)
{
	for (int i=h[x];i;i=nxt[i])
	{
		if (t[i]==fa) continue;
		dis[t[i]]=dis[x]+(a[t[i]]!=a[x]);
		dfs(t[i],x);
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
int main()
{
	n=read();
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=1;i<n;i++)
	{
		int x=read(),y=read();
		add(x,y),add(y,x);
	}
	dfs(1,0);
	int u=1;
	for (int i=1;i<=n;i++)
	{
		if (dis[u]<dis[i]) u=i;
	}
	dis[u]=0;
	dfs(u,0);
	u=1;
	for (int i=1;i<=n;i++)
	{
		if (dis[u]<dis[i]) u=i;
	}
	printf("%d",(dis[u]+1)/2);
	return 0;
}