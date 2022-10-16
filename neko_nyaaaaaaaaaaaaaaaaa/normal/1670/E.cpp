#include <bits/stdc++.h>
using namespace std;

#define int long long 

void dfs(int now, int prv, int p, int col, vector<vector<int>> &adj, map<pair<int, int>, int> &valed, map<int, int> &valnod, int &petr) {
	for (int u: adj[now]) {
		if (u != prv) {
			if (!col) {
				valed[{u, now}] = valed[{now, u}] = (1 << p) + petr;
				valnod[u] = petr;
			} else {
				valed[{u, now}] = valed[{now, u}] = petr;
				valnod[u] = (1 << p) + petr;
			}
			
			petr++;

			dfs(u, now, p, 1-col, adj, valed, valnod, petr);
		}
	}
}

void solve() {
	int p; cin >> p;
	int n = (1 << p);
	vector<vector<int>> adj(n+1);
	vector<pair<int, int>> edges;
	map<pair<int, int>, int> valed;
	map<int, int> valnod;
	for (int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
		edges.emplace_back(u, v);
	}

	int petr = 1; valnod[1] = (1 << p);
	dfs(1, 0, p, 0, adj, valed, valnod, petr);

	cout << "1\n";
	for (int i = 1; i <= n; i++) {
		cout << valnod[i] << ' ';
	}
	cout << '\n';
	for (auto pr: edges) {
		cout << valed[pr] << ' ';
	}
	cout << '\n';
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int t; cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}