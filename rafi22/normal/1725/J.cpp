// Olaf Surgut 17.09.2022 10:53:07
#include <bits/stdc++.h>

using namespace std;

#define int int64_t

#define cerr 0 && cerr

const int N = 1e5 + 11;

int n;
vector<pair<int, int>> adj[N];

int d[N], b[N];

void dfs1(int u, int f) {
	vector<int> all;

	for (auto [v, w] : adj[u]) if (v != f) {
		dfs1(v, u);
		d[u] = max(d[u], d[v] + w);
		b[u] = max(b[u], b[v]);

		all.push_back(d[v] + w);
	}

	sort(all.rbegin(), all.rend());

	int new_best = 0;
	for (int i = 0; i < min((int) 2, (int) all.size()); i++) {
		new_best += all[i];
	}

	b[u] = max(b[u], new_best);

	cerr << "d [ " << u << " ] = " << d[u] << '\n';
	cerr << "b [ " << u << " ] = " << b[u] << '\n';
}

int dfs2(int u, int f) {
	int res = 0;
	
	vector<pair<int, int>> all;
	
	for (auto [v, w] : adj[u]) {
		all.emplace_back(d[v] + w, v);
		
		if (v == f)
			continue;

	}

	pair<int, int> maxi{0, 0};
	pair<int, int> vice{0, 0};

	for (auto [v, w] : adj[u]) {
		pair<int, int> curr{b[v], v};

		if (maxi < curr) {
			vice = maxi;
			maxi = curr;
		}
		else
		if (vice < curr) {
			vice = curr;
		}
	}

	pair<int, int> mm{0, 0};
	pair<int, int> vv{0, 0};

	for (auto [v, w] : adj[u]) {
		pair<int, int> cu{d[v] + w, v};

		if (mm < cu) {
			vv = mm;
			mm = cu;
		}
		else
		if (vv < cu) {
			vv = cu;
		}
	}

	sort(all.rbegin(), all.rend());

	int path_cross = 0;
	for (int i = 0; i < min((int) 4, (int) all.size()); i++) {
		path_cross += all[i].first;
	}

	res = max(res, path_cross);

	for (auto [v, w] : adj[u]) if (v != f) {
		int best = 0;
		
		for (int i = 0, j = 2; i < (int) all.size() && j > 0; i++) {
			if (all[i].second != v) {
				best += all[i].first;
				j--;
			}
		}

		if (maxi.second != v)
			best = max(best, maxi.first);
		else
			best = max(best, vice.first);

		res = max(res, b[v] + 2 * w + best);

		int backup_d = d[u];
		int backup_b = b[u];

		b[u] = best;
		d[u] = (mm.second == v ? vv.first : mm.first);

		res = max(res, dfs2(v, u));	
	
		d[u] = backup_d;
		b[u] = backup_b;
	}

	return res;
}

int32_t main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);

	cin >> n;

	int sum = 0;

	for (int i = 0; i < n - 1; i++) {
		int u, v, w; cin >> u >> v >> w; u--, v--;

		adj[u].emplace_back(v, w);
		adj[v].emplace_back(u, w);
	
		sum += 2 * w;
	}

	dfs1(0, -1);

	cout << sum - dfs2(0, -1) << '\n';
}