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
	int n, m;
	cin >> n >> m;
	vector<vector<pii>> graph(n);
	vector<vector<int>> type(n, vector<int>(n, -2));
	for (int i = 0; i < m; ++i) {
		int a, b, t;
		cin >> a >> b >> t;
		--a; --b;
		graph[a].push_back({b, t});
		graph[b].push_back({a, -t});
	}

	vector<int> color(n);
	vector<bool> used(n);

	function<bool(int, int)> dfs = [&](int v, int col) {
		color[v] = col;
		used[v] = true;
		for (auto to : graph[v]) {
			if (!used[to.ff]) {
				if (dfs(to.ff, 1 - col)) {
					return true;
				}
			} else if (color[to.ff] == color[v]) {
				return true;
			}
		}
		return false;
	};

	if (dfs(0, 0)) {
		cout << "NO\n";
		return;
	}

	vector<int> dist(n), mem_dist(n);
	vector<int> ans;
	int best = -INF;
	for (int st = 0; st < n; ++st) {
		fill(dist.begin(), dist.end(), INF);
		dist[st] = 0;
		for (int i = 0; i < n + 1; ++i) {
			if (i == n) {
				copy(dist.begin(), dist.end(), mem_dist.begin());
			}
			for (int j = 0; j < n; ++j) {
				for (auto to : graph[j]) {
					if (to.ss) {
						dist[to.ff] = min(dist[to.ff], dist[j] + to.ss);
					} else {
						dist[to.ff] = min(dist[to.ff], dist[j] + 1);
					}
				}
			}
		}

		if (dist != mem_dist) {
			cout << "NO\n";
			return;
		}

		int val = *max_element(dist.begin(), dist.end());
		if (val > best) {
			best = val;
			ans = dist;
		}
	}

	cout << "YES\n";
	cout << best << "\n";
	for (int num : ans) {
		cout << num << " ";
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