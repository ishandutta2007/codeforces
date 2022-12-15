#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3e3;

vector<int> G[MAXN];
int n;

typedef long long ll;

int par[MAXN][MAXN];
ll sz[MAXN][MAXN];
ll dp[MAXN][MAXN];

int comp(int u, int root)
{
	sz[root][u] = 1;
	for (auto v : G[u])
		if (v != par[root][u])
		{
			par[root][v] = u;
			sz[root][u] += comp(v, root);
		}
	return sz[root][u];
}

ll solve(int u, int v)
{
	if (dp[u][v] != -1) return dp[u][v];

	dp[u][v] = sz[u][v] * sz[v][u]  + max(solve(par[u][v], u), solve(par[v][u], v));
	return dp[u][v];
}

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	cin >> n;
	for (int i(0); i < n-1; ++i)
	{
		int u, v;
		cin >> u >> v;
		--u, --v;
		G[u].push_back(v);
		G[v].push_back(u);
	}

	for (int i(0); i < n; ++i)
	{
		par[i][i] = i;
		comp(i,i);
	}

	for (int i(0); i < n; ++i)
		for (int j(0); j < n; ++j)
			dp[i][j] = -1;
	
	for (int i(0); i < n; ++i)
		dp[i][i] = 0;
	ll ans(0);
	for (int i(0); i < n; ++i)
		for (int j(0); j < n; ++j)
			ans = max(ans, solve(i,j));
	cout << ans << endl;

}