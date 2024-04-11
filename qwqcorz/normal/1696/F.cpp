#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=105;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

char s[N];
bool is[N][N][N],vis[N];
void dfs(int now,int father,int n,vector<pair<int,int>>&ret,bool flag=0)
{
	if (vis[now]) return;
	vis[now]=1;
	if (!flag) ret.push_back({father,now});
	for (int i=1;i<=n;i++) if (i!=father&&is[i][father][now]) dfs(i,now,n,ret);
}
vector<pair<int,int>>solve(int n,int rt,int son)
{
	vector<pair<int,int>>ret;
	for (int i=1;i<=n;i++) vis[i]=0;
	dfs(son,rt,n,ret);
	dfs(rt,son,n,ret,1);
	return ret;
}
vector<int>e[N];
int dis[N][N];
bool dfs1(int now,int father,int st,int dist)
{
	if (vis[now]) return 0;
	vis[now]=1;
	dis[st][now]=dist;
	for (int to:e[now]) if (to!=father)
	if (!dfs1(to,now,st,dist+1)) return 0;
	return 1;
}
bool check(int n,vector<pair<int,int>>E)
{
	for (int i=1;i<=n;i++) e[i].clear();
	for (auto [u,v]:E)
		e[v].push_back(u),
		e[u].push_back(v);
	for (int i=1;i<=n;i++)
	{
		for (int i=1;i<=n;i++) vis[i]=0;
		if (!dfs1(i,0,i,0)) return 0;
		for (int i=1;i<=n;i++) if (!vis[i]) return 0;
	}
	for (int i=1;i<=n;i++)
	for (int j=i+1;j<=n;j++)
	for (int k=1;k<=n;k++)
	if ((dis[i][k]==dis[j][k])!=is[i][j][k]) return 0;
	return 1;
}
void work()
{
	int n=read();
	for (int i=1;i<=n;i++)
	for (int j=1;j<=n;j++)
	for (int k=1;k<=n;k++) is[i][j][k]=0;
	for (int i=1;i<=n;i++)
	for (int j=i+1;j<=n;j++)
	{
		scanf("%s",s+1);
		for (int k=1;k<=n;k++) is[i][j][k]=is[j][i][k]=s[k]=='1';
	}
	for (int i=2;i<=n;i++)
	{
		vector<pair<int,int>>e=solve(n,1,i);
		if (check(n,e))
		{
			puts("Yes");
			for (auto [x,y]:e) print(x,' '),print(y);
			return;
		}
	}
	puts("No");
}

signed main()
{
	int T=read();
	while (T--) work();
	
	return 0;
}
/*
1
5
00000 01001 00000 01100
00000 10000 00000
00000 11010
00000

*/