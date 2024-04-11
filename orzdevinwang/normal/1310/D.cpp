#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
using namespace std;
const int N = 81, M = 11;
int n, m, ret, e[N][N];
int dp[M][N];
bool vis[N];
mt19937_64 orz(time(0) ^ clock());
int ns = 1e9 + 7;
int Main () {
	L(i, 1, n) vis[i] = orz() & 1;
	memset(dp, 0x3f, sizeof(dp));
	dp[0][1] = 0;
	L(t, 1, m) 
		L(i, 1, n) 
			L(j, 1, n) if(vis[i] ^ vis[j]) 
				dp[t][j] = min(dp[t][j], dp[t - 1][i] + e[i][j]);
	return dp[m][1];
}
int main () {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	L(i, 1, n) L(j, 1, n) cin >> e[i][j];
	int t = 3 * (1 << M);
	while (t--) ns = min(ns, Main ());
	cout << ns << '\n';
	return 0;
}