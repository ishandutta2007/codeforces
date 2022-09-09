// Created by Nikolay Budin

#ifdef DEBUG
#  define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
#define ff first
#define ss second
#define szof(x) ((int)x.size())
#ifndef LOCAL
#  define cerr __get_ce
#endif

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef unsigned long long ull;
int const INF = (int)1e9 + 1e3;
ll const INFL = (ll)1e18 + 1e6;
#ifdef LOCAL
	mt19937 tw(9450189);
#else
	mt19937 tw(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif
uniform_int_distribution<ll> ll_distr;
ll rnd(ll a, ll b) { return ll_distr(tw) % (b - a + 1) + a; }

const int maxans = 1000000000;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<pii> edges_order;
	vector<pii> edges;
	vector<int> weight;
	for (int i = 0; i < m; ++i) {
		int a, b, e;
		cin >> a >> b >> e;
		--a; --b;
		weight.push_back(e);
		edges.push_back({a, b});
		edges_order.push_back({e, i});
	}
	sort(edges_order.begin(), edges_order.end());
	vector<int> dsu(n);
	iota(dsu.begin(), dsu.end(), 0);

	auto get_root = [&](int v) {
		int mem = v;
		while (v != dsu[v]) {
			v = dsu[v];
		}
		while (mem != dsu[mem]) {
			int tmp = dsu[mem];
			dsu[mem] = v;
			mem = tmp;
		}
		return v;
	};

	vector<bool> on_tree(m);
	vector<vector<pii>> graph(n);

	for (auto [w, ind] : edges_order) {
		auto [u, v] = edges[ind];
		int a = get_root(u);
		int b = get_root(v);
		if (a != b) {
			dsu[b] = a;
			graph[u].push_back({v, ind});
			graph[v].push_back({u, ind});
			on_tree[ind] = true;
		}
	}

	int bp = 1;
	while (1 << bp < n) {
		++bp;
	}
	vector<int> depth(n);
	vector<vector<int>> binup(bp, vector<int>(n));
	vector<int> sz(n);
	vector<int> edge_to_par(n);
	function<void(int, int, int)> dfs = [&](int v, int p, int d) {
		depth[v] = d;
		binup[0][v] = p;
		for (int i = 1; i < bp; ++i) {
			binup[i][v] = binup[i - 1][binup[i - 1][v]];
		}
		sz[v] = 1;
		for (pii to : graph[v]) {
			if (to.ff != p) {
				dfs(to.ff, v, d + 1);
				edge_to_par[to.ff] = to.ss;
				sz[v] += sz[to.ff];
			}
		}
	};

	dfs(0, 0, 0);

	function<int(int, int)> get_lca = [&](int a, int b) {
		if (depth[a] > depth[b]) {
			swap(a, b);
		}
		for (int i = bp - 1; i >= 0; --i) {
			if (depth[a] <= depth[b] - (1 << i)) {
				b = binup[i][b];
			}
		}
		if (a == b) {
			return a;
		}
		for (int i = bp - 1; i >= 0; --i) {
			if (binup[i][a] != binup[i][b]) {
				a = binup[i][a];
				b = binup[i][b];
			}
		}
		return binup[0][a];
	};

	vector<int> path;
	vector<int> where(n);
	vector<int> path_root(n);
	vector<int> order;

	function<void(int, int)> split_paths = [&](int v, int p) {
		path.push_back(v);
		int best = -1;
		for (pii to : graph[v]) {
			if (to.ff != p && (best == -1 || sz[best] < sz[to.ff])) {
				best = to.ff;
			}
		}
		if (best == -1) {
			for (int u : path) {
				where[u] = szof(order);
				path_root[u] = path.front();
				order.push_back(u);
			}
			path.clear();
			return;
		}
		split_paths(best, v);
		for (pii to : graph[v]) {
			if (to.ff != p && to.ff != best) {
				split_paths(to.ff, v);
			}
		}
	};

	split_paths(0, 0);

	vector<vector<int>> sparse_table1(1, vector<int>(n)), sparse_table2(1, vector<int>(n, INF));
	for (int i = 0; i < n; ++i) {
		int v = order[i];
		if (v != 0) {
			sparse_table1[0][i] = weight[edge_to_par[v]];
		}
	}
	for (int i = 1; i < bp; ++i) {
		sparse_table1.push_back(vector<int>(n - (1 << i) + 1));
		for (int j = 0; j + (1 << i) <= n; ++j) {
			sparse_table1[i][j] = max(sparse_table1[i - 1][j], sparse_table1[i - 1][j + (1 << (i - 1))]);
		}
		sparse_table2.push_back(vector<int>(n - (1 << i) + 1, INF));
	}

	vector<int> maxp(n + 1);
	for (int i = 1; i < szof(maxp); ++i) {
		maxp[i] = maxp[i - 1];
		if (1 << (maxp[i] + 1) <= i) {
			++maxp[i];
		}
	}

	auto do_sparse = [&](int l, int r, int w) {
		if (r - l == 0) {
			return 0;
		}
		int p = maxp[r - l];
		// cerr << "set " << w << " on" << endl;
		// for (int i = l; i < r; ++i) {
		// 	cerr << order[i] + 1 << " ";
		// }
		// cerr << endl;
		sparse_table2[p][l] = min(sparse_table2[p][l], w);
		sparse_table2[p][r - (1 << p)] = min(sparse_table2[p][r - (1 << p)], w);
		return max(sparse_table1[p][l], sparse_table1[p][r - (1 << p)]);
	};

	auto do_on_vertical_path = [&](int a, int b, int w) {
		int ret = 0;
		while (true) {
			int rt = path_root[a];
			// cerr << a + 1 << " " << rt + 1 << endl;
			if (depth[rt] > depth[b] + 1) {
				ret = max(ret, do_sparse(where[rt], where[a] + 1, w));
				a = binup[0][rt];
			} else {
				ret = max(ret, do_sparse(where[a] - (depth[a] - depth[b] - 1), where[a] + 1, w));
				break;
			}
		}
		return ret;
	};

	auto do_on_path = [&](int a, int b, int w) {
		int lca = get_lca(a, b);
		return max(do_on_vertical_path(a, lca, w), do_on_vertical_path(b, lca, w));
	};

	vector<int> ans(m);

	for (int i = 0; i < m; ++i) {
		if (!on_tree[i]) {
			ans[i] = do_on_path(edges[i].ff, edges[i].ss, weight[i]);
		}
	}

	// for (int i = 0; i < bp; ++i) {
	// 	for (int num : sparse_table2[i]) {
	// 		cerr << num << " ";
	// 	}
	// 	cerr << endl;
	// }

	for (int i = bp - 1; i > 0; --i) {
		for (int j = 0; j + (1 << i) <= n; ++j) {
			sparse_table2[i - 1][j] = min(sparse_table2[i - 1][j], sparse_table2[i][j]);
			sparse_table2[i - 1][j + (1 << (i - 1))] = min(sparse_table2[i - 1][j + (1 << (i - 1))], sparse_table2[i][j]);
		}
	}

	for (int i = 0; i < m; ++i) {
		if (on_tree[i]) {
			int v = edges[i].ff;
			if (depth[edges[i].ss] > depth[v]) {
				v = edges[i].ss;
			}
			ans[i] = sparse_table2[0][where[v]];
		}
	}

	for (int num : ans) {
		cout << min(num, maxans) << "\n";
	}
}


int main() {
#ifdef LOCAL
	auto start_time = clock();
	cerr << setprecision(3) << fixed;
#endif
	cout << setprecision(15) << fixed;
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int test_count = 1;
	// cin >> test_count;
	for (int test = 1; test <= test_count; ++test) {
		solve();
	}
	
#ifdef LOCAL
	auto end_time = clock();
	cerr << "Execution time: " << (end_time - start_time) * (int)1e3 / CLOCKS_PER_SEC << " ms\n";
#endif
}