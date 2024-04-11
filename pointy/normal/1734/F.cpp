// Author: Little09
// Problem: F. Zeros and Ones
// Contest: Codeforces Round #822 (Div. 2)
// URL: https://codeforces.com/contest/1734/problem/F
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m;
ll dp[62][2][2][2];//1
ll dfs(int u,int x,int y,int z)
{
	if (u==-1)
	{
		if (x==1) return 1;
		return 0;
	}
	if (dp[u][x][y][z]!=-1) return dp[u][x][y][z];
	ll res=0;
	for (int i=0;i<=1;i++)
	{
		bool j=n&(1ll<<u),k=m&(1ll<<u);
		if (z&&k==0&&i) continue;
		bool Z=(z&(i==k)),X=x,Y=0;
		if (i&j) X=x^y,Y=0;
		else if (i|j) X=x^j,Y=y^1;
		res+=dfs(u-1,X,Y,Z);
	}
	return dp[u][x][y][z]=res;
}

void work()
{
	cin >> n >> m;
	m--;
	memset(dp,-1,sizeof(dp));
	// x  [0,m]  popcount(x)+popcount(x+n) 
	ll ans=dfs(60,0,0,1);
	cout << ans << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	cin >> T;
	while (T--) work();
	return 0;
}