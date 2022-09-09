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

	vector<bool> removed(n);
	vector<bool> is_not_root(n);

	function<bool(int, int, int)> mark_path = [&](int v, int p, int t) {
		if (v == t) {
			return true;
		}
		for (int to : graph[v]) {
			if (to != p && mark_path(to, v, t)) {
				is_not_root[v] = true;
				return true;
			}
		}
		return false;
	};

	for (int i = 0; i < n / 2; ++i) {
		int a = -1, b = -1;
		for (int j = 0; j < n; ++j) {
			if (removed[j]) {
				continue;
			}
			int cnt = 0;
			for (int to : graph[j]) {
				cnt += !removed[to];
			}
			if (cnt == 1) {
				if (a == -1) {
					a = j;
				} else {
					b = j;
					break;
				}
			}
		}

		cout << "? " << a + 1 << " " << b + 1 << endl;
		int c;
		cin >> c;
		--c;
		mark_path(a, a, c);
		mark_path(b, b, c);
		removed[a] = removed[b] = true;
	}

	for (int i = 0; i < n; ++i) {
		if (!is_not_root[i]) {
			cout << "! " << i + 1 << "\n";
			return;
		}
	}

	assert(false);
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