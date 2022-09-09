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
	string s;
	cin >> s;
	int ans = INF;
	for (int d0 = 0; d0 <= 1; ++d0) {
		for (int d1 = 0; d1 <= 1; ++d1) {
			// cerr << d0 << " " << d1 << endl;
			vector<vector<int>> dp = {{INF, INF}, {INF, INF}};
			dp[d0][d1] = (int) ("LR"[d0] != s[0]) + (int) ("LR"[d1] != s[1]);
			for (int i = 2; i < n; ++i) {
				vector<vector<int>> next = {{INF, INF}, {INF, INF}};

				for (int a = 0; a <= 1; ++a) {
					for (int b = 0; b <= 1; ++b) {
						// cerr << dp[a][b] << " ";
						for (int c = 0; c <= 1; ++c) {
							if (c == 0 && b == 0 && a == 0) {
								continue;
							}
							if (a == 1 && b == 1 && c == 1) {
								continue;
							}
							next[b][c] = min(next[b][c], dp[a][b] + (int) (s[i] != "LR"[c]));
						}
					}
				}
				// cerr << endl;
				swap(dp, next);
			}

			for (int a = 0; a <= 1; ++a) {
				for (int b = 0; b <= 1; ++b) {
					if (d0 == 0 && d1 == 0 && b == 0) {
						continue;
					}
					if (d0 == 1 && d1 == 1 && b == 1) {
						continue;
					}
					if (a == 0 && b == 0 && d0 == 0) {
						continue;
					}
					if (a == 1 && b == 1 && d0 == 1) {
						continue;
					}
					// cerr << d0 << " " << d1 << " " << a << " " << b << " " << dp[a][b] << endl;
					ans = min(ans, dp[a][b]);
				}
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