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
	int n, m, a, b;
	cin >> n >> m >> a >> b;
	--a; --b;
	vector<vector<pii>> graph(n);
	vector<pii> edges;
	map<pii, int> edge_ind;
	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		--u; --v;
		edges.push_back({u, v});
		edge_ind[{u, v}] = edge_ind[{v, u}] = i;
		graph[u].push_back({v, i});
		graph[v].push_back({u, i});
	}

	vector<int> dsu(m);
	iota(dsu.begin(), dsu.end(), 0);

	function<int(int)> get_root = [&](int v) {
		return dsu[v] == v ? v : dsu[v] = get_root(dsu[v]);
	};

	auto unite = [&](int a, int b) {
		dsu[get_root(a)] = get_root(b);
	};

	vector<int> up(n);
	vector<int> depth(n);
	vector<int> used(n);

	vector<bool> is_knot(n);

	function<void(int, int, int)> dfs = [&](int v, int pe, int d) {
		used[v] = 1;
		depth[v] = d;
		up[v] = d;
		int cnt = 0;
		for (auto to : graph[v]) {
			if (to.ss != pe) {
				if (!used[to.ff]) {
					dfs(to.ff, to.ss, d + 1);
					++cnt;
					if (pe != -1 && up[to.ff] >= depth[v]) {
						is_knot[v] = true;
					}
					if (up[to.ff] < depth[v]) {
						// cerr << "1 " << to.ss << " " << pe << endl;
						unite(to.ss, pe);
					}
					up[v] = min(up[v], up[to.ff]);
				} else if (used[to.ff] == 1) {
					up[v] = min(up[v], depth[to.ff]);
					// cerr << "2 " << to.ss << " " << pe << endl;
					unite(to.ss, pe);
				}
			}
		}

		if (pe == -1) {
			is_knot[v] = cnt > 1;
		}

		used[v] = 2;
	};

	dfs(0, -1, 0);

	if (!is_knot[a] || !is_knot[b]) {
		cout << "0\n";
		return;
	}

	vector<int> path;

	function<bool(int, int)> find_path = [&](int v, int t) {
		used[v] = true;
		path.push_back(v);
		if (v == t) {
			return true;
		}
		for (auto to : graph[v]) {
			if (!used[to.ff]) {
				if (find_path(to.ff, t)) {
					return true;
				}
			}
		}
		path.pop_back();
		return false;
	};

	fill(used.begin(), used.end(), 0);
	find_path(a, b);
	fill(used.begin(), used.end(), 0);
	for (int v : path) {
		used[v] = true;
	}

	int e1 = edge_ind[{path[0], path[1]}];
	int e2 = edge_ind[{path[szof(path) - 2], path[szof(path) - 1]}];

	for (int i = 0; i < m; ++i) {
		if (get_root(e1) == get_root(i) || get_root(e2) == get_root(i)) {
			used[edges[i].ff] = used[edges[i].ss] = true;
		}
	}

	function<int(int)> dfs_cnt = [&](int v) {
		int ret = 1;
		used[v] = true;
		for (auto to : graph[v]) {
			if (!used[to.ff]) {
				ret += dfs_cnt(to.ff);
			}
		}
		return ret;
	};

	cout << (ll) (dfs_cnt(a) - 1) * (dfs_cnt(b) - 1) << "\n";
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
	cin >> test_count;
	for (int test = 1; test <= test_count; ++test) {
		solve();
	}

#ifdef LOCAL
	auto end_time = clock();
	cerr << "Execution time: " << (end_time - start_time) * (int)1e3 / CLOCKS_PER_SEC << " ms\n";
#endif
}