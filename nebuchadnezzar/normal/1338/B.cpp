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
	vector<vector<int>> graph(n);
	for (int i = 0; i < n - 1; ++i) {
		int a, b;
		cin >> a >> b;

		--a; --b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	vector<int> color(n);
	vector<bool> used(n);
	function<void(int, int)> dfs = [&](int v, int col) {
		color[v] = col;
		used[v] = true;
		for (int to : graph[v]) {
			if (!used[to]) {
				dfs(to, 1 - col);
			}
		}
	};

	dfs(0, 0);
	vector<bool> leafs(n);
	set<int> leafs_col;
	for (int i = 0; i < n; ++i) {
		if (szof(graph[i]) == 1) {
			leafs[i] = true;
			leafs_col.insert(color[i]);
		}
	}


	if (szof(leafs_col) == 1) {
		cout << "1 ";
	} else {
		cout << "3 ";
	}

	int ans = n - 1;
	for (int i = 0; i < n; ++i) {
		if (leafs[i]) {
			continue;
		}
		int cnt = 0;
		for (int to : graph[i]) {
			cnt += leafs[to];
		}
		if (cnt) {
			ans = ans - cnt + 1;
		}
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