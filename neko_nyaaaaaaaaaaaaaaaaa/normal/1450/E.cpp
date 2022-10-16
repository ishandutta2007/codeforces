#include <bits/stdc++.h>
using namespace std;

// bellman ford

const int MAXN = 300;

int n, m;
vector<pair<int, int>> adj1[MAXN]; // directed
vector<int> adj2[MAXN]; // undirected

vector<pair<int, int>> e1, e2;

int clb[MAXN];

void dfs_bip(int now, int col) {
	clb[now] = col;
	for (int u: adj2[now]) {
		if (clb[u] == -1) {
			dfs_bip(u, 1-col);
		} else {
			if (clb[u] == clb[now]) {
				cout << "NO\n";
				exit(0);
			}
		}
	}
	for (auto [u, w]: adj1[now]) {
		if (clb[u] == -1) {
			dfs_bip(u, 1-col);
		} else {
			if (clb[u] == clb[now]) {
				cout << "NO\n";
				exit(0);
			}
		}
	}
}

void check_bip() {
	memset(clb, -1, sizeof(clb));
	dfs_bip(1, 0);
}

vector<pair<int, int>> adj[MAXN];

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v, b; cin >> u >> v >> b;
		if (b == 1) {
			adj1[u].emplace_back(v, 1);
			adj1[v].emplace_back(u, -1);
			e1.emplace_back(u, v);
		} else {
			adj2[u].push_back(v);
			adj2[v].push_back(u);
			e2.emplace_back(u, v);
		}
	}
	check_bip();

	vector<tuple<int, int, int>> edge;
	for (auto [u, v]: e1) {
		// v-u == 1
		adj[u].emplace_back(v, 1);
		adj[v].emplace_back(u, -1);
		edge.emplace_back(u, v, 1);
		edge.emplace_back(v, u, -1);
	}
	for (auto [u, v]: e2) {
		// v-u <= 1
		// u-v <= 1
		adj[u].emplace_back(v, 1);
		adj[v].emplace_back(u, 1);
		edge.emplace_back(u, v, 1);
		edge.emplace_back(v, u, 1);
	}

	int cap = -1;
	vector<int> ans;
	for (int src = 1; src <= n; src++) {
		const int INF = 1000000;
		vector<int> d(n+1, INF);
		d[src] = 0;
		int x;
		for (int i = 0; i < n; i++) {
			x = -1;
			for (auto [a, b, w]: edge) {
				if (d[a] < INF) {
					if (d[b] > d[a] + w) {
						d[b] = max(-INF, d[a] + w);
						x = b;
					}
				}
			}
		}
		if (x != -1) continue;

		int mx = *max_element(d.begin()+1, d.end());
		int mn = *min_element(d.begin()+1, d.end());

		if ((mx - mn) > cap) {
			cap = mx - mn;
			ans = d;
		}
	}
	
	if (ans.empty()) {
		cout << "NO\n";
	} else {
		cout << "YES\n";
		cout << cap << '\n';

		int mn = *min_element(ans.begin(), ans.end());
		for (int i = 1; i <= n; i++) {
			cout << ans[i] - mn << ' ';
		}
	}

	return 0;
}