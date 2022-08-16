#include <bits/stdc++.h>
using namespace std;

struct sparse_union_find {
	map<int, int> p;

	int find(int x) {
		if (p.find(x) == p.end())
			p[x] = x;
		return p[x] == x ? x : p[x] = find(p[x]);
	}

	bool merge(int u, int v) {
		int l1 = find(u), l2 = find(v);
		return l1 == l2 ? false : p[l2] = l1, true;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	struct edge {
		int a, b, c;
	};

	vector<edge> e(m);
	vector<vector<int>> g(n);

	vector<sparse_union_find> uf(m);

	for (int i = 0; i < m; i++) {
		cin >> e[i].a >> e[i].b >> e[i].c;
		--e[i].a, --e[i].b, --e[i].c;
		if (uf[e[i].c].merge(e[i].a, e[i].b)) {
			g[e[i].a].push_back(i);
			g[e[i].b].push_back(i);
		}
	}

	vector<vector<int>> comps;
	comps.reserve(m);
	vector<int> id(n);

	int cur_id = 0;
	for (int i = 0; i < m; i++) {
		for (auto &[x, p] : uf[i].p) {
			if (x == p) {
				id[x] = cur_id++;
				comps.emplace_back();
			}
		}
		for (auto &[x, p] : uf[i].p) {
			comps[id[uf[i].find(x)]].push_back(x);
		}
	}

	int q;
	cin >> q;

	vector<map<int, pair<int, vector<int>>>> mp(n);
	for (int i = 0, u, v; i < q; i++) {
		cin >> u >> v, --u, --v;
		if (u > v) swap(u, v);
		mp[u][v].second.push_back(i);
	}

	const int sq = sqrt(n);
	for (auto &comp : comps) {
		if (comp.size() <= sq) {
			for (int u : comp) {
				for (int v : comp) {
					if (u < v) {
						auto it = mp[u].find(v);
						if (it != mp[u].end()) {
							it->second.first += 1;
						}
					}
				}
			}
		} else {
			vector<bool> in_comp(n);
			for (auto u : comp) in_comp[u] = true;

			for (int u = 0; u < n; u++) {
				for (auto &[v, p] : mp[u]) {
					if (in_comp[u] && in_comp[v]) {
						p.first += 1;
					}
				}
			}
		}
	}

	vector<int> ans(q);
	for (int u = 0; u < n; u++) {
		for (auto &[v, p] : mp[u]) {
			for (int i : p.second) {
				ans[i] = p.first;
			}
		}
	}

	for (int i = 0; i < q; i++) cout << ans[i] << '\n';
	return 0;
}