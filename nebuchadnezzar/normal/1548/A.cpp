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
	vector<set<int>> graph(n);
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		graph[a].insert(b);
		graph[b].insert(a);
	}
	int q;
	cin >> q;
	vector<int> is_ok(n);

	auto check_is_ok = [&](int i) {
		return szof(graph[i]) == 0 || *--graph[i].end() < i;
	};

	int ans = 0;
	for (int i = 0; i < n; ++i) {
		is_ok[i] = check_is_ok(i);
		ans += is_ok[i];
	}

	for (int i = 0; i < q; ++i) {
		int t;
		cin >> t;
		if (t == 1 || t == 2) {
			int a, b;
			cin >> a >> b;
			--a; --b;
			ans -= is_ok[a];
			ans -= is_ok[b];
			if (t == 1) {
				graph[a].insert(b);
				graph[b].insert(a);
			} else {
				graph[a].erase(b);
				graph[b].erase(a);
			}
			is_ok[a] = check_is_ok(a);
			is_ok[b] = check_is_ok(b);
			ans += is_ok[a];
			ans += is_ok[b];
		} else {
			cout << ans << "\n";
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