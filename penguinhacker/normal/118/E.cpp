#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN = 100000;
int n, m, dep[mxN], dp[mxN];
vector<int> adj[mxN];
vector<pair<int, int>> ans;

void dfs(int u = 0, int p = -1, int d = 0) {
	dep[u] = d;
	for (int v : adj[u]) if (v != p) {
		if (dep[v] == -1) {
			ans.emplace_back(u, v);
			dfs(v, u, d + 1);
			dp[u] += dp[v];
		}
		else {
			if (dep[v] < dep[u]) { // v is ancestor
				ans.emplace_back(u, v);
				++dp[u];
			}
			else --dp[u];
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int a, b; cin >> a >> b, --a, --b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	fill(dep, dep + n, -1);
	dfs();
	if (count(dp + 1, dp + n, 0)) {cout << 0; return 0;}
	assert(ans.size() == m);
	for (pair<int, int> p : ans) cout << p.first + 1 << " " << p.second + 1 << "\n";
	return 0;
}