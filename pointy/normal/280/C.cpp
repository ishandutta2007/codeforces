// By: Little09
// Problem: CF280C Game on Tree
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF280C
// Memory Limit: 250 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
int n;
const int N=2e5+5;
int dis[N];

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
int t[N],nxt[N],h[N],cnt;
inline void add(int x,int y)
{
	t[++cnt]=y;
	nxt[cnt]=h[x];
	h[x]=cnt;
}
void dfs(int x,int fa)
{
	dis[x]=dis[fa]+1;
	for (int i=h[x];i;i=nxt[i])
	{
		if (t[i]!=fa) dfs(t[i],x);
	}
}
int main()
{
	n=read();
	for (int i=1;i<n;i++)
	{
		int x=read(),y=read();
		add(x,y),add(y,x);
	}
	dfs(1,0);
	double ans=0;
	for (int i=1;i<=n;i++)
	{
		double x=dis[i];
		x=1.0/x;
		ans+=x;
	}
	printf("%.10lf\n",ans);
	return 0;
}