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
	vector<int> a(n);
	vector<int> any_in(n, -1);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		--a[i];
		any_in[a[i]] = i;
	}

	vector<int> result(n, -1);
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		if (any_in[i] != -1) {
			result[any_in[i]] = i;
			++ans;
		}
	}

	// for (int num : result) {
	// 	cerr << num << " ";
	// }
	// cerr << endl;

	vector<pii> paths;
	for (int i = 0; i < n; ++i) {
		if (result[i] == -1) {
			int end = i;
			int v = i;
			while (any_in[v] != -1) {
				v = any_in[v];
			}
			paths.push_back({v, end});
			// cerr << v << " " << end << endl;
		}
	}

	if (szof(paths) == 1 && paths[0].ff == paths[0].ss) {
		result[paths[0].ff] = a[paths[0].ff];
		result[any_in[a[paths[0].ff]]] = paths[0].ff;
	} else if (szof(paths)) {
		for (int i = 0; i < szof(paths); ++i) {
			int next = (i + 1) % szof(paths);
			result[paths[i].ss] = paths[next].ff;
		}
	}

	cout << ans << "\n";
	for (int i = 0; i < n; ++i) {
		cout << result[i] + 1 << " ";
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
	cin >> test_count;
	for (int test = 1; test <= test_count; ++test) {
		solve();
	}

#ifdef LOCAL
	auto end_time = clock();
	cerr << "Execution time: " << (end_time - start_time) * (int)1e3 / CLOCKS_PER_SEC << " ms\n";
#endif
}