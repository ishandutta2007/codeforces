// Author: Little09
// Problem: E. Xenon's Attack on the Gangs
// Contest: Codeforces Round #614 (Div. 2)
// URL: https://codeforces.com/contest/1293/problem/E
// Memory Limit: 512 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mem(x) memset(x,0,sizeof(x))
#define printYes cout << "Yes" << endl
#define printYES cout << "YES" << endl
#define printNo cout << "No" << endl
#define printNO cout << "NO" << endl
#define lowbit(x) (x&(-x))

const ll inf=1000000000000000000; 
//const ll inf=1000000000;
//const ll mod=998244353;
//const ll mod=1000000007;

const int N=3005;
int n,m; 
int a[N],b[N];
vector<int>t[N];

int fa[N][21],deth[N];
ll siz[N];
int w[N][N],dis[N][N];
ll dp[N][N];
void dfs(int x,int f)
{
	fa[x][0]=f,deth[x]=deth[f]+1,siz[x]=1;
	for (int i=1;i<=20;i++) fa[x][i]=fa[fa[x][i-1]][i-1];
	for (int i:t[x])
	{
		if (i==f) continue;
		dfs(i,x);
		siz[x]+=siz[i];
	}
}
int p[N],tot;
void dfs2(int x,int f)
{
	for (int i=1;i<=tot;i++) w[p[i]][x]=1;
	p[++tot]=x;
	for (int i:t[x])
	{
		if (i==f) continue;
		dfs2(i,x);
	}
	tot--;
}
void dfs3(int x,int f,int di,int u)
{
	dis[u][x]=di;
	for (int i:t[x])
	{
		if (i==f) continue;
		dfs3(i,x,di+1,u);
	}
}
ll work(int x,int y)
{
	if (dp[x][y]!=-1) return dp[x][y];
	if (w[y][x]==1) swap(y,x);
	if (w[x][y]==0)
	{
		ll res=siz[x]*siz[y];
		ll tot=0;
		for (int i:t[x])
		{
			if (i==fa[x][0]) continue;
			tot=max(tot,work(i,y));
		}
		for (int j:t[y])
		{
			if (j==fa[y][0]) continue;
			tot=max(tot,work(x,j));
		}
		return dp[x][y]=tot+res;
	}
	else
	{
		int so=-1;
		for (int i:t[x])
		{
			if (dis[i][y]<dis[x][y]) so=i;
		}
		ll res=(siz[1]-siz[so])*siz[y];
		ll tot=0;
		for (int i:t[x])
		{
			if (i==so) continue;
			tot=max(tot,work(i,y));
		}
		for (int j:t[y])
		{
			if (j==fa[y][0]) continue;
			tot=max(tot,work(x,j));
		}
		//if (x==1&&y==2) cout << tot << endl;
		return dp[x][y]=tot+res;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	for (int i=1;i<n;i++)
	{
		int x,y;
		cin >> x >> y;
		t[x].push_back(y),t[y].push_back(x);
		a[i]=x,b[i]=y;
	}
	dfs(1,0);
	dfs2(1,0);
	for (int i=1;i<=n;i++) dfs3(i,0,0,i);
	ll ans=0;
	memset(dp,-1,sizeof(dp));
	for (int i=1;i<n;i++) ans=max(ans,work(a[i],b[i]));
	cout << ans << endl;
	return 0;
}