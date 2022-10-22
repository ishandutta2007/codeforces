// LUOGU_RID: 90652489
// Author: Little09
// Problem: CF1498F Christmas Game
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1498F
// Memory Limit: 250 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,k;
int h[N],nxt[N],t[N],cnt,a[N];
const int M=41;
int dp[N][M],s[N][M];
inline void add(int x,int y)
{
	t[++cnt]=y;
	nxt[cnt]=h[x];
	h[x]=cnt;
}
int deth[N];
void dfs1(int x,int f)
{
	deth[x]=deth[f]+1;
	dp[x][0]=a[x];
	for (int i=h[x];i;i=nxt[i])
	{
		if (t[i]==f) continue;
		dfs1(t[i],x);
		for (int j=0;j<2*k;j++) dp[x][(j+1)%(2*k)]^=dp[t[i]][j];
	}
}
void dfs2(int x,int f)
{
	if (f==0)
	{
		for (int j=0;j<2*k;j++) s[x][j]=dp[x][j];
	}
	else
	{
		for (int j=0;j<2*k;j++) s[x][(j+1)%(2*k)]=s[f][j]^dp[x][(j+2*k-1)%(2*k)];
		for (int j=0;j<2*k;j++) s[x][j]^=dp[x][j];
	}
	for (int i=h[x];i;i=nxt[i])
	{
		if (t[i]==f) continue;
		dfs2(t[i],x);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> k;
	for (int i=1;i<n;i++)
	{
		int x,y;
		cin >> x >> y;
		add(x,y),add(y,x);
	}
	for (int i=1;i<=n;i++) cin >> a[i];
	dfs1(1,0);
	dfs2(1,0);
	for (int i=1;i<=n;i++)
	{
		int res=0;
		for (int j=k;j<2*k;j++) res^=s[i][j];
		if (res==0) cout << "0 ";
		else cout << "1 ";
	}
	return 0;
}