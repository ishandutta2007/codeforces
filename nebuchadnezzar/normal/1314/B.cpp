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
	int n, k;
	cin >> n >> k;
	if (k == 0) {
		cout << "0\n";
		return;
	}
	vector<bool> good(1 << n);
	for (int i = 0; i < k; ++i) {
		int ind;
		cin >> ind;
		--ind;
		good[ind] = true;
	}

	vector<vector<vector<int>>> dp(1 << n, vector<vector<int>>(2, vector<int>(2, -INF)));

	function<void(int)> dfs = [&](int v) {
		if (1 << (n - 1) <= v) {
			int sum = good[v * 2 - (1 << n)] + good[v * 2 + 1 - (1 << n)];
			if (sum == 0) {
				dp[v][0][0] = 0;
			}
			if (sum == 1) {
				dp[v][0][1] = dp[v][1][0] = 1;
			}
			if (sum == 2) {
				dp[v][1][1] = 1;
			}
			return;
		}

		dfs(v * 2);
		dfs(v * 2 + 1);

		for (int u1 = 0; u1 <= 1; ++u1) {
			for (int d1 = 0; d1 <= 1; ++d1) {
				for (int u2 = 0; u2 <= 1; ++u2) {
					for (int d2 = 0; d2 <= 1; ++d2) {
						int val = dp[v * 2][u1][d1] + dp[v * 2 + 1][u2][d2] + (d1 | d2);
						int left = d1 | d2;
						val += u1 | u2;
						dp[v][u1][left | u2] = max(dp[v][u1][left | u2], val + (left | u2));
						dp[v][u2][left | u1] = max(dp[v][u2][left | u1], val + (left | u1));
					}
				}
			}
		}
	};

	dfs(1);

	// for (int i = 1; i < 1 << n; ++i) {
	// 	cerr << dp[i][0][0] << " " << dp[i][0][1] << " " << dp[i][1][0] << " " << dp[i][1][1] << endl;
	// }

	cout << max({dp[1][0][0], dp[1][0][1], dp[1][1][0], dp[1][1][1]}) + 1 << "\n";
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