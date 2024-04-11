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
	int n, k, r;
	cin >> n >> k >> r;
	vector<vector<int>> graph(n);
	for (int i = 0; i < n - 1; ++i) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		int c = szof(graph);
		graph.push_back({});
		graph[a].push_back(c);
		graph[c].push_back(a);
		graph[b].push_back(c);
		graph[c].push_back(b);
	}

	n = szof(graph);
	int bp = 1;
	while (1 << bp < n) {
		++bp;
	}

	vector<vector<int>> binup(n, vector<int>(bp));
	vector<int> depth(n);

	function<void(int, int, int)> dfs = [&](int v, int p, int d) {
		depth[v] = d;
		binup[v][0] = p;
		for (int i = 1; i < bp; ++i) {
			binup[v][i] = binup[binup[v][i - 1]][i - 1];
		}
		for (int to : graph[v]) {
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
				b = binup[b][i];
			}
		}
		if (a == b) {
			return a;
		}
		for (int i = bp - 1; i >= 0; --i) {
			if (binup[a][i] != binup[b][i]) {
				a = binup[a][i];
				b = binup[b][i];
			}
		}
		return binup[a][0];
	};

	auto get_dist = [&](int a, int b) {
		int lca = get_lca(a, b);
		return depth[a] + depth[b] - 2 * depth[lca];
	};

	auto jump_up = [&](int a, int d) {
		for (int i = bp - 1; i >= 0; --i) {
			if (d >= (1 << i)) {
				d -= 1 << i;
				a = binup[a][i];
			}
		}
		return a;
	};

	auto move_in_dir = [&](int a, int b, int d) {
		int lca = get_lca(a, b);
		if (depth[a] - depth[lca] >= d) {
			return jump_up(a, d);
		} else {
			return jump_up(b, depth[a] + depth[b] - 2 * depth[lca] - d);
		}
	};

	vector<pii> edges;
	queue<int> qu;
	vector<int> dist(n, INF);
	for (int i = 0; i < r; ++i) {
		int v;
		cin >> v;
		--v;
		dist[v] = 0;
		qu.push(v);
	}

	while (szof(qu)) {
		int v = qu.front();
		qu.pop();
		if (dist[v] == k) {
			continue;
		}
		for (int to : graph[v]) {
			if (dist[to] > dist[v] + 1) {
				dist[to] = dist[v] + 1;
				qu.push(to);
			}
			edges.push_back({to, v});
		}
	}

	vector<vector<int>> graph2(n);
	for (auto [a, b] : edges) {
		graph2[a].push_back(b);
		graph2[b].push_back(a);
	}

	vector<int> color(n, -1);

	int cnt_color = 0;

	for (int i = 0; i < n; ++i) {
		if (color[i] == -1 && szof(graph2[i])) {
			qu.push(i);
			color[i] = cnt_color;
			while (szof(qu)) {
				int v = qu.front();
				qu.pop();
				for (int to : graph2[v]) {
					if (color[to] == -1) {
						color[to] = cnt_color;
						qu.push(to);
					}
				}
			}
			++cnt_color;
		}
	}

	int q;
	cin >> q;

	for (int i = 0; i < q; ++i) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		if (get_dist(a, b) <= k * 2) {
			cout << "YES\n";
		} else {
			int a2 = move_in_dir(a, b, k);
			int b2 = move_in_dir(b, a, k);
			if (color[a2] != -1 && color[a2] == color[b2]) {
				cout << "YES\n";
			} else {
				cout << "NO\n";
			}
		}
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