#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200001;

int n;
vector<int> adj[MAXN];
int dp[MAXN];

void input() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		adj[i].clear(); dp[i] = 0;
	}
	for (int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
}

bool ok;

void dfs(int now, int prev, int k) { 
	for (int u: adj[now]) {
		if (u != prev) dfs(u, now, k);
	}

	multiset<int> ms;
	for (int u: adj[now]) {
		if (u != prev) ms.insert(dp[u]);
	}
	if (ms.empty()) return;
	if (ms.size() == 1) {
		dp[now] = *ms.begin() + 1;
		if (dp[now] > k) ok = 0;
		return;
	}

	int ans = 10000000;
	for (int u: adj[now]) {
		if (u != prev) {
			ms.erase(ms.find(dp[u]));
			int tmp = dp[u] + 1;
			// max of others + 2
			auto it = ms.end(); it--;
			tmp = max(tmp, *it + 2);
			
			if (tmp <= k) {
				ans = min(ans, dp[u]);
			}
			ms.insert(dp[u]);
		}
	}
	if (ans == 10000000) ok = 0;
	dp[now] = ans+1;
}

bool check(int k) {
	ok = 1;
	for (int i = 1; i <= n; i++) {
		dp[i] = 0;
	}
	dfs(1, 0, k);
	return ok;
}

void solve() {
	// backtracking only occurs at the last children of that subtree
	int lo = 1, hi = n;
	while (lo < hi) {
		int mid = (lo + hi)/2;
		if (check(mid)) {
			hi = mid;
		} else {
			lo = mid+1;
		}
	} 
	cout << lo << '\n';
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int t; cin >> t;
	while (t--) {
		input();
		solve();
	}
	
	return 0;
}