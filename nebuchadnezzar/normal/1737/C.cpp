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
	vector<pii> cells;
	map<int, int> cnt_x, cnt_y;
	for (int i = 0; i < 3; ++i) {
		int x, y;
		cin >> x >> y;
		--x; --y;
		cells.push_back({x, y});
		cnt_x[x]++;
		cnt_y[y]++;
	}

	int x, y;
	cin >> x >> y;
	--x; --y;

	if (find(cells.begin(), cells.end(), pii(x, y)) != cells.end()) {
		cout << "YES\n";
		return;
	}

	int cx, cy;
	for (auto p : cnt_x) {
		if (p.ss == 2) {
			cx = p.ff;
		}
	}

	for (auto p : cnt_y) {
		if (p.ss == 2) {
			cy = p.ff;
		}
	}

	if ((x + y) % 2 == (cx + cy) % 2 && x % 2 != cx % 2) {
		cout << "NO\n";
		return;
	}

	if (cx == 0 && cy == 0) {
		if (x == 0 || y == 0) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
		return;
	}

	if (cx == 0 && cy == n - 1) {
		if (x == 0 || y == n - 1) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
		return;
	}

	if (cx == n - 1 && cy == n - 1) {
		if (x == n - 1 || y == n - 1) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
		return;
	}

	if (cx == n - 1 && cy == 0) {
		if (x == n - 1 || y == 0) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
		return;
	}

	cout << "YES\n";
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