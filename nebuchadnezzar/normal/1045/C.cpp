// Created by Nikolay Budin

#ifdef DEBUG
#  define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
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

using namespace __gnu_pbds;
template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename K, typename V> using ordered_map = tree<K, V, less<K>, rb_tree_tag, tree_order_statistics_node_update>;

int const INF = (int)1e9 + 1e3;
ll const INFL = (ll)1e18 + 1e6;
#ifdef LOCAL
	mt19937 tw(9450189);
#else
	mt19937 tw(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif
uniform_int_distribution<ll> ll_distr;
ll rnd(ll a, ll b) { return ll_distr(tw) % (b - a + 1) + a; }


void solve() {
	int n, m, q;
	cin >> n >> m >> q;
	vector<set<int>> graph(n);
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		graph[a].insert(b);
		graph[b].insert(a);
	}

	vector<vector<int>> tree(n);

	vector<int> comp;
	for (int i = 0; i < n; ++i) {
		while (szof(graph[i])) {
			int a = i;
			int b = *graph[i].begin();
			graph[a].erase(b);
			graph[b].erase(a);
			comp.clear();
			comp.push_back(a);
			comp.push_back(b);
			if (szof(graph[a]) > szof(graph[b])) {
				swap(a, b);
			}
			for (int to : graph[a]) {
				if (graph[b].count(to)) {
					comp.push_back(to);
				}
			}

			for (int j = 0; j < szof(comp); ++j) {
				for (int k = j + 1; k < szof(comp); ++k) {
					graph[comp[j]].erase(comp[k]);
					graph[comp[k]].erase(comp[j]);
				}
			}

			int cur = szof(tree);
			tree.push_back({});
			for (int v : comp) {
				tree[v].push_back(cur);
				tree[cur].push_back(v);
			}
		}
	}

	int bp = 1;
	while (1 << bp < szof(tree)) {
		++bp;
	}

	vector<int> depth(szof(tree));
	vector<vector<int>> binup(bp, vector<int>(szof(tree)));

	function<void(int, int, int)> dfs = [&](int v, int p, int d) {
		depth[v] = d;
		binup[0][v] = p;
		for (int i = 1; i < bp; ++i) {
			binup[i][v] = binup[i - 1][binup[i - 1][v]];
		}
		for (int to : tree[v]) {
			if (to != p) {
				dfs(to, v, d + 1);
			}
		}
	};

	dfs(0, 0, 0);

	auto get_lca = [&](int a, int b) {
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

	auto get_dist = [&](int a, int b) {
		int lca = get_lca(a, b);
		return depth[a] + depth[b] - depth[lca] * 2;
	};

	for (int i = 0; i < q; ++i) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		int d = get_dist(a, b);
		cout << d / 2 << "\n";
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