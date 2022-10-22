#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int MOD = 998244353;
int n, k;
vector<ll> dp[5000];
vector<int> adj[5000];

void dfs(int u = 0, int p = -1) {
	dp[u].assign(1, 1);
	for (int v : adj[u]) {
		if (v == p)
			continue;
		dfs(v, u);
		vector<ll> ndp(max(dp[u].size(), dp[v].size() + 1));
		ll sum = accumulate(dp[v].begin(), dp[v].end(), 0ll) % MOD;
		for (int i = 0; i < dp[u].size(); ++i)
			ndp[i] = sum * dp[u][i] % MOD;
		for (int i = 0; i < dp[u].size(); ++i)
			for (int j = 0; j < dp[v].size(); ++j) {
				if (i + j + 1 > k)
					continue;
				//assert(max(i, j + 1) < ndp.size());
				ndp[max(i, j + 1)] = (ndp[max(i, j + 1)] + dp[u][i] * dp[v][j]) % MOD;
			}
		swap(dp[u], ndp);
	}
	//cerr << u << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	for (int i = 1; i < n; ++i) {
		int a, b; cin >> a >> b, --a, --b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs();
	cout << accumulate(dp[0].begin(), dp[0].end(), 0ll) % MOD;
	return 0;
}