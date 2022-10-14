#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int N;
	cin >> N;
	vector<int> G[N];
	for (int i = 0; i + 1 < N; i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		G[u].emplace_back(v);
		G[v].emplace_back(u);
	}
	
	vector<vector<int>> sz(N, vector<int>(N, 0)); // sz[ROOT][node]
	vector<vector<int>> par(N, vector<int>(N, 0)); // sz[ROOT][node]
	
	function<void(int, int, int)> dfsSz = [&](int n, int p, int root) {
		sz[root][n] = 1;
		par[root][n] =  p;
		for (auto &i : G[n]) if (i != p) {
			dfsSz(i, n, root);
			sz[root][n] += sz[root][i];
		}
	};
	
	for (int i = 0; i < N; i++) {
		dfsSz(i, -1, i);
	}
	
	long long ans = 0;
	vector<vector<long long>> memo(N, vector<long long>(N, -1));
	function<long long(int, int)> dp = [&](int u, int v) {
		if (u == v) {
			return 0ll;
		}
		if (memo[u][v] != -1) {
			return memo[u][v];
		}
		long long res = 0;
		res += (long long) sz[v][u] * sz[u][v];
		res += max(dp(par[v][u], v), dp(par[u][v], u));
		return memo[u][v] = res;
	};
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			ans = max(ans, dp(i, j));
		}
	}
	
	cout << ans << "\n";

	return 0;
}