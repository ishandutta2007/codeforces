#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define arr array

const int mxN = 2e5;
const int MOD = 1e9+7;

int n, p[mxN];
ll dp[mxN], dp2[mxN], ans[mxN];
vector<int> adj[mxN];

void dfs1(int u = 0) {
	dp[u] = 1;
	for (int v : adj[u]) {
		dfs1(v);
		dp[u] = dp[u] * (dp[v] + 1) % MOD;
	}
}

void dfs2(int u = 0) {
	ans[u] = dp2[u] * dp[u] % MOD;
	int k = adj[u].size();
	vector<ll> pre(k, 1), suf(k, 1);
	for (int i = 1; i < k; ++i)
		pre[i] = pre[i - 1] * (dp[adj[u][i - 1]] + 1) % MOD;
	for (int i = k - 2; i >= 0; --i)
		suf[i] = suf[i + 1] * (dp[adj[u][i + 1]] + 1) % MOD;
	for (int i = 0; i < k; ++i) {
		int v = adj[u][i];
		dp2[v] = (pre[i] * suf[i] % MOD * dp2[u] + 1) % MOD;
		dfs2(v);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i < n; ++i) {
		cin >> p[i], --p[i];
		adj[p[i]].push_back(i);
	}
	dfs1();
	dp2[0] = 1;
	dfs2();
	for (int i = 0; i < n; ++i)
		cout << ans[i] << " ";
	return 0;
}