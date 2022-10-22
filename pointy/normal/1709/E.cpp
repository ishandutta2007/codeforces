// Author: Little09
// Problem: E. XOR Tree
// Contest: Educational Codeforces Round 132 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1709/problem/E
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mem(x) memset(x,0,sizeof(x))
#define printYes puts("Yes")
#define printYES puts("YES")
#define printNo puts("No")
#define printNO puts("NO")
#define endl "\n"
#define lowbit(x) (x&(-x))

const ll inf=1000000000000000000; 
//const ll mod=998244353;
//const ll mod=1000000007;

const int N=200005;
int n,m; 
int a[N],fa[N],dis[N];
vector<int>t[N];
set<int>s[N];
bool ans[N];
int find(int x)
{
	if (x==fa[x]) return x;
	return fa[x]=find(fa[x]);
}
int merge(int x,int y,int z)
{
	int x1=find(x),y1=find(y);
	if (s[x1].size()>s[y1].size()) swap(x,y),swap(x1,y1);
	for (int i:s[x1])
	{
		if (s[y1].find(i^z)!=s[y1].end())
		{
			s[x1].clear();
			s[y1].clear();
			return 0;
		}
	}
	for (int i:s[x1])
	{
		s[y1].insert(i);
	}
	s[x1].clear();
	fa[x1]=y1;
	return 1;
}
void dfs(int x,int f)
{
	dis[x]=(dis[f]^a[x]);
	for (int i:t[x])
	{
		if (i==f) continue;
		dfs(i,x);
	}
	int rt=find(x);
	s[rt].insert(dis[x]);
	for (int i:t[x])
	{
		if (i==f) continue;
		if (ans[i]==1) continue;
		if (merge(x,i,a[x])==0)
		{
			int rt=find(x);
			s[rt].clear();
			ans[x]=1;
			return;
		}
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
		t[x].push_back(y),t[y].push_back(x);
	}
	for (int i=1;i<=n;i++) fa[i]=i;
	dfs(1,0);
	int res=0;
	for (int i=1;i<=n;i++) res+=ans[i];
	cout << res;
	return 0;
}