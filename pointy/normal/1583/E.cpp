// By: Little09
// Problem: E. Moment of Bloom
// Contest: Codeforces - Codeforces Round #749 (Div. 1 + Div. 2, based on Technocup 2022 Elimination Round 1)
// URL: https://codeforces.ml/contest/1586/problem/E
// Memory Limit: 512 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
#define printYes puts("Yes")
#define printYES puts("YES")
#define printNo puts("No")
#define printNO puts("NO")
const int N=6e5+5;
int n,m,q;
vector<int>t[N],g[N];
int d[N];
int a[N],b[N];
void add(int x,int y)
{
	t[x].push_back(y);
	t[y].push_back(x);
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
bool used[N];
void dfs1(int x)
{
	for (int i=0;i<t[x].size();i++)
	{
		if (used[t[x][i]]) continue;
		g[x].push_back(t[x][i]);
		g[t[x][i]].push_back(x);
		used[t[x][i]]=1;
		dfs1(t[x][i]);
	}
}
bool flag;
int p[N],cnt;
void print()
{
	printf("%d\n",cnt);
	for (int i=1;i<=cnt;i++) printf("%d ",p[i]);
	printf("\n");
}
void dfs2(int x,int y,int fa)
{
	p[++cnt]=x;
	if (x==y)
	{
		print();
		return;
	}
	for (int i=0;i<g[x].size();i++)
	{
		if (g[x][i]==fa) continue;
		dfs2(g[x][i],y,x);
	}
	cnt--;
}
int main()
{
	n=read(),m=read();
	for (int i=1;i<=m;i++)
	{
		int x=read(),y=read();
		add(x,y);
	}
	q=read();
	for (int i=1;i<=q;i++)
	{
		int x=read(),y=read();
		d[x]++,d[y]++;
		a[i]=x,b[i]=y;
	}
	int ans=0;
	for (int i=1;i<=n;i++)
	{
		if (d[i]%2==1) ans++;
	}
	if (ans==0) printYES;
	else 
	{
		printNO;
		printf("%d\n",ans/2);
		return 0;
	}
	used[1]=1;
	dfs1(1);
	for (int i=1;i<=q;i++)
	{
		cnt=0,flag=0;
		dfs2(a[i],b[i],0);
	}
	return 0;
}