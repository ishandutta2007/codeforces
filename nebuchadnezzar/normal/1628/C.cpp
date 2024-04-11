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

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void solve() {
	int n;
	cin >> n;
	vector<vector<int>> coloring(n, vector<int>(n));
	for (int i = 0; i < (n / 2 + 1) / 2; i += 2) {
		int x1 = i * 2;
		int x2 = n - 1 - i * 2;
		for (int j = x1; j < x2; ++j) {
			coloring[x1][j] = 1;
			coloring[x2 - 1][j] = 1;
			coloring[j][x1] = 1;
			coloring[j][x2 - 1] = 1;
			if (x2 - x1 > 1) {
				coloring[x1 + 1][j] = 1;
				coloring[x2 - 2][j] = 1;
				coloring[j][x1 + 1] = 1;
				coloring[j][x2 - 2] = 1;
			}
		}
	}

	/*
	bool ok = true;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if ((i + j) % 2 == 1) {
				int cnt = 0;
				for (int d = 0; d < 4; ++d) {
					int nx = i + dx[d];
					int ny = j + dy[d];
					if (0 <= nx && nx < n && 0 <= ny && ny < n) {
						cnt += coloring[nx][ny];
					}
				}
				if (cnt % 2 == 0) {
					ok = false;
					break;
				}
			}
		}
		if (!ok) {
			break;
		}
	}
	assert(ok);
	*/
	/*
	cerr << "\n";
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if ((i + j) % 2 == 0) {
				cerr << coloring[i][j];
			} else {
				cerr << ".";
			}
		}
		cerr << endl;
	}
	*/
	
	vector field(n, vector<int>(n));
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> field[i][j];
			if ((i + j) % 2 == 0 && coloring[i][j]) {
				ans ^= field[i][j];
			}
			if ((i + j) % 2 == 1 && coloring[n - 1 - i][j]) {
				ans ^= field[i][j];
			}
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
	cin >> test_count;
	for (int test = 1; test <= test_count; ++test) {
		solve();
	}

#ifdef LOCAL
	auto end_time = clock();
	cerr << "Execution time: " << (end_time - start_time) * (int)1e3 / CLOCKS_PER_SEC << " ms\n";
#endif
}