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
	int n, q;
	cin >> n >> q;
	vector<vector<int>> field(2, vector<int>(n));

	auto get_ok = [&](int r) {
		bool ret = (field[0][r] == 0 || field[1][r] == 0) && (field[0][r + 1] == 0 || field[1][r + 1] == 0);
		if (!ret) {
			return ret;
		}
		return (field[0][r] == 0 && field[0][r + 1] == 0) || (field[1][r] == 0 && field[1][r + 1] == 0);
	};

	int cnt_ok = n - 1;
	for (int i = 0; i < q; ++i) {
		int r, c;
		cin >> r >> c;
		--r; --c;
		if (c) {
			cnt_ok -= get_ok(c - 1);
		}
		if (c < n) {
			cnt_ok -= get_ok(c);
		}
		field[r][c] ^= 1;
		if (c) {
			cnt_ok += get_ok(c - 1);
		}
		if (c < n) {
			cnt_ok += get_ok(c);
		}

		if (cnt_ok == n - 1) {
			cout << "Yes\n";
		} else {
			cout << "No\n";
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