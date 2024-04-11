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
	vector<vector<pii>> graph(n);
	vector<pii> edges;
	for (int i = 0; i < n - 1; ++i) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		graph[a].push_back({b, szof(edges)});
		edges.push_back({a, b});
		graph[b].push_back({a, szof(edges)});
		edges.push_back({b, a});
	}

	vector<int> sz(n);
	vector<int> sz_by_edge(n * 2 - 2);

	function<void(int, int, int)> dfs = [&](int v, int p, int pe) {
		sz[v] = 1;
		for (auto to : graph[v]) {
			if (to.ff != p) {
				dfs(to.ff, v, to.ss ^ 1);
				sz_by_edge[to.ss] = sz[to.ff];
				sz[v] += sz[to.ff];
			}
		}
		if (pe != -1) {
			sz_by_edge[pe] = n - sz[v];
		}
	};

	dfs(0, 0, -1);

	// for (int num : sz_by_edge) {
	// 	cerr << num << endl;
	// }

	vector<vector<ll>> dp(n * 2 - 2, vector<ll>(n * 2 - 2, -1));

	function<ll(int, int)> calc = [&](int e1, int e2) {
		if (dp[e1][e2] != -1) {
			return dp[e1][e2];
		}
		auto [pv, v] = edges[e1];
		auto [pu, u] = edges[e2];
		auto& ret = dp[e1][e2];
		ret = 0;
		for (auto to : graph[v]) {
			if (to.ff != pv) {
				ret = max(ret, calc(to.ss, e2));
			}
		}
		for (auto to : graph[u]) {
			if (to.ff != pu) {
				ret = max(ret, calc(e1, to.ss));
			}
		}
		ret += sz_by_edge[e1] * sz_by_edge[e2];
		return ret;
	};

	ll ans = 0;

	for (int i = 0; i < n - 1; ++i) {
		ans = max(ans, calc(i * 2, i * 2 + 1));
	}

	cout << ans << "\n";
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