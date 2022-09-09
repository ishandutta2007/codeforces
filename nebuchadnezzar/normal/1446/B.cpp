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

void upd(int16_t& a, int16_t b) {
	a = max(a, b);
}

void solve() {
	int n, m;
	cin >> n >> m;
	string s, t;
	cin >> s >> t;
	vector<vector<vector<int16_t>>> dp(2, vector<vector<int16_t>>(n + 1, vector<int16_t>(m + 1, -13000)));
	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= m; ++j) {
			if (i && j) {
				if (s[i - 1] == t[j - 1]) {
					upd(dp[0][i][j], 2);
					upd(dp[0][i][j], dp[0][i - 1][j - 1] + 2);
					upd(dp[1][i][j], 2);
					upd(dp[1][i][j], dp[0][i - 1][j - 1] + 2);
				}
			}
			if (i) {
				upd(dp[0][i][j], dp[0][i - 1][j] - 1);
				upd(dp[1][i][j], dp[1][i - 1][j]);
			}
			if (j) {
				upd(dp[0][i][j], dp[0][i][j - 1] - 1);
				upd(dp[1][i][j], dp[1][i][j - 1]);
			}
		}
	}

	cout << max(0, (int) dp[1][n][m]) << "\n";
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