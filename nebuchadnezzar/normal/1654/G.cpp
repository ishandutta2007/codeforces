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
	int n;
	cin >> n;
	vector<int> dist(n, INF);
	queue<int> qu;
	for (int i = 0; i < n; ++i) {
		int t;
		cin >> t;
		if (t == 1) {
			dist[i] = 0;
			qu.push(i);
		}
	}

	vector<vector<int>> graph(n);
	for (int i = 0; i < n - 1; ++i) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	while (szof(qu)) {
		int v = qu.front();
		qu.pop();
		for (int to : graph[v]) {
			if (dist[to] > dist[v] + 1) {
				dist[to] = dist[v] + 1;
				qu.push(to);
			}
		}
	}

	vector<bool> is_good(n);
	for (int i = 0; i < n; ++i) {
		for (int to : graph[i]) {
			if (dist[i] == dist[to]) {
				is_good[i] = true;
			}
		}
	}

	vector<bool> used(n);
	vector<int> sz(n);
	vector<int> largest(n);
	vector<int> visited;

	vector<int> ans = dist;

	function<void(int, int)> calc_szs = [&](int v, int p) {
		sz[v] = 1;
		largest[v] = 0;
		visited.push_back(v);
		for (int to : graph[v]) {
			if (to != p && !used[to]) {
				calc_szs(to, v);
				sz[v] += sz[to];
				largest[v] = max(largest[v], sz[to]);
			}
		}
	};

	vector<pii> best;

	function<void(int, int, int, int)> dfs1 = [&](int v, int p, int min_pref, int cur_pref) {
		if ( is_good[v]) {
			best.push_back({dist[v], min_pref});
		}
		for (int to : graph[v]) {
			if (to != p && !used[to]) {
				if (dist[to] < dist[v]) {
					dfs1(to, v, min_pref, cur_pref + 1);
				} else if (dist[to] == dist[v]) {
					dfs1(to, v, min(min_pref, cur_pref - 1), cur_pref - 1);
				}
			}
		}
	};

	auto get_best = [&](int bal) {
		auto it = lower_bound(best.begin(), best.end(), pii(-bal, -INF));
		if (it == best.end()) {
			return INF;
		}
		return it->ss;
	};

	function<void(int, int, int, int)> dfs2 = [&](int v, int p, int min_pref, int cur_pref) {
		if (min_pref >= 0) {
			// cerr << "upd " << v << " " << cur_pref << " " << min_pref << " " << get_best(cur_pref) << endl;
			ans[v] = min(ans[v], get_best(cur_pref));
		}
		for (int to : graph[v]) {
			if (to != p && !used[to]) {
				if (dist[to] > dist[v]) {
					dfs2(to, v, min(min_pref + 1, 0), cur_pref + 1);
				} else if (dist[to] == dist[v]) {
					dfs2(to, v, min(min_pref - 1, 0), cur_pref - 1);
				}
			}
		}
	};
	
	function<void(int)> build_centroid = [&](int v) {
		visited.clear();
		calc_szs(v, v);
		for (int u : visited) {
			largest[u] = max(largest[u], szof(visited) - sz[u]);
			if (largest[u] < largest[v]) {
				v = u;
			}
		}

		used[v] = true;
		// cerr << "centroid " << v << endl;

		best.clear();
		dfs1(v, v, 0, 0);
		sort(best.begin(), best.end());
		{
			vector<pii> tmp;
			int larest_bal = -INF;
			for (auto p : best) {
				// cerr << p.ff << " " << p.ss << endl;
				if (szof(tmp) && tmp.back().ff == p.ff) {
					tmp.back().ss = p.ss;
				} else {
					if (p.ss > larest_bal) {
						tmp.push_back(p);
					}
				}
				larest_bal = max(larest_bal, p.ss);
			}
			// swap(tmp, best);
			best.clear();
			for (auto p : tmp) {
				best.push_back({p.ss, p.ff});
			}
		}
		dfs2(v, v, 0, 0);
		// cerr << "centroid " << v << endl;

		for (int to : graph[v]) {
			if (!used[to]) {
				build_centroid(to);
			}
		}
	};

	build_centroid(0);

	// for (int i = 0; i < n; ++i) {
	// 	cerr << ans[i] << " ";
	// }
	// cerr << endl;

	for (int i = 0; i < n; ++i) {
		cout << dist[i] * 2 - ans[i] << " ";
	}
	cout << "\n";
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