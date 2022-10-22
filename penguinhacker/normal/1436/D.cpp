#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, leaf[200000];
ll a[200000], ans = 0;
vector<int> adj[200000];

void dfs(int u = 0) {
	//cerr << u << " ";
	if (adj[u].empty()) {
		leaf[u] = 1;
		ans = max(ans, a[u]);
		return;
	}
	for (int v : adj[u]) {
		dfs(v);
		leaf[u] += leaf[v];
		a[u] += a[v];
	}
	ans = max(ans, (a[u] + leaf[u] - 1) / leaf[u]);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i < n; ++i) {
		int x; cin >> x, --x;
		adj[x].push_back(i);
	}
	for (int i = 0; i < n; ++i) cin >> a[i];
	dfs();
	cout << ans;
	return 0;
}