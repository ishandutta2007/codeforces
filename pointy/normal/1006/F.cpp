// Author: Little09
// Problem: F - XOR on Grid Path
// Contest: AtCoder - KYOCERA Programming Contest 2022AtCoder Beginner Contest 271
// URL: https://atcoder.jp/contests/abc271/tasks/abc271_f
// Memory Limit: 1024 MB
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
#define endl "\n"
#define lowbit(x) (x&(-x))

const ll inf=1000000000000000000; 
//const ll inf=1000000000;
//const ll mod=998244353;
//const ll mod=1000000007;

const int N=25;
int n,m;
ll k; 
ll a[N][N];
map<ll,ll>q[N][N];
ll ans;

void dfs1(int x,int y,ll z)
{
	if (x<1||y<1||x>n||y>m) return;
	if (x+y==n+1)
	{
		q[x][y][z]++;
		return;
	}
	dfs1(x+1,y,z^a[x][y]);
	dfs1(x,y+1,z^a[x][y]);
}
void dfs2(int x,int y,ll z)
{
	if (x<1||y<1||x>n||y>m) return;
	if (x+y==n+1)
	{
		z^=a[x][y]^k;
		ans+=q[x][y][z];
		return;
	}
	dfs2(x-1,y,z^a[x][y]);
	dfs2(x,y-1,z^a[x][y]);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m >> k;
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
		{
			cin >> a[i][j];
		}
	}
	dfs1(1,1,0);
	dfs2(n,m,0);
	cout << ans;
	return 0;
}