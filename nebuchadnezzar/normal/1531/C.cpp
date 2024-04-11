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
	for (int m = 1; m <= n; ++m) {
		for (int diag = 1; diag <= m; ++diag) {
			if ((n - diag) % 2) {
				continue;
			}
			int mins = diag * diag;
			int maxs = diag * m + (m - diag) * diag;
			if (mins <= n && n <= maxs) {
				vector<vector<char>> outp(m, vector<char>(m, '.'));
				for (int i = 0; i < diag; ++i) {
					for (int j = 0; j < diag; ++j) {
						outp[m - 1 - i][j] = 'o';
					}
				}
				int cur = diag * diag;
				int x = diag;
				int y = 0;
				while (cur < n) {
					outp[m - 1 - x][y] = outp[m - 1 - y][x] = 'o';
					++y;
					if (y == diag) {
						y = 0;
						++x;
					}
					cur += 2;
				}

				cout << m << "\n";
				for (int i = 0; i < m; ++i) {
					for (int j = 0; j < m; ++j) {
						cout << outp[i][j];
					}
					cout << "\n";
				}
				return;
			}
		}
	}
	cout << "-1\n";
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