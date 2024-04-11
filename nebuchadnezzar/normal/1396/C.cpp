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
	ll r1, r2, r3, d;
	cin >> n >> r1 >> r2 >> r3 >> d;
	vector<ll> arr;
	for (int i = 0; i < n; ++i) {
		int num;
		cin >> num;
		arr.push_back(num);
	}

	vector<vector<ll>> dp(n, {INFL, INFL, INFL});
	dp[0] = {arr[0] * r1 + r3 + d,
			min((arr[0] + 1) * r1 + d + d + r1, r2 + d + d + r1),
			min((arr[0] + 1) * r1 + d + d + r1 + d, r2 + d + d + r1 + d)};

	for (int i = 1; i < n - 1; ++i) {
		ll complete = arr[i] * r1 + r3;
		ll part1 = min((arr[i] + 1) * r1, r2);
		// cerr << i << " " << complete << " " << part1 << endl;
		dp[i][0] = min(complete + min(dp[i - 1][0], dp[i - 1][2]) + d, part1 + dp[i - 1][2] + r1 + d);
		dp[i][1] = min(complete + d + d + dp[i - 1][1], part1 + d + d + r1 + min(dp[i - 1][1], dp[i - 1][0]));
		dp[i][2] = min(complete + d + d + dp[i - 1][2] + d, part1 + d + d + r1 + min(dp[i - 1][2], dp[i - 1][0]) + d);
	}

	ll complete = arr[n - 1] * r1 + r3;
	ll part1 = min((arr[n - 1] + 1) * r1, r2);

	// for (int i = 0; i < n - 1; ++i) {
	// 	cout << dp[i][0] << " " << dp[i][1] << " " << dp[i][2] << endl;
	// }

	ll ans = INFL;
	ans = min(ans, complete + min(dp[n - 2][0], dp[n - 2][1]));
	ans = min(ans, part1 + dp[n - 2][2] + r1);
	ans = min(ans, part1 + d + dp[n - 2][0] + d + r1);

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
	// cin >> test_count;
	for (int test = 1; test <= test_count; ++test) {
		solve();
	}

#ifdef LOCAL
	auto end_time = clock();
	cerr << "Execution time: " << (end_time - start_time) * (int)1e3 / CLOCKS_PER_SEC << " ms\n";
#endif
}