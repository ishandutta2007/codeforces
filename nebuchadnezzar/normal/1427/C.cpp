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

int dist(pii& a, pii& b) {
	return abs(a.ff - b.ff) + abs(a.ss - b.ss);
}

void solve() {
	int r, n;
	cin >> r >> n;
	vector<pair<pii, int>> inp = {{{0, 0}, 0}};
	vector<int> dp(n + 1, -INF);
	dp[0] = 0;
	int pref_max = -INF;
	for (int i = 0; i < n; ++i) {
		int t, x, y;
		cin >> t >> x >> y;
		--x; --y;
		inp.push_back({{x, y}, t});
		dp[i + 1] = max(dp[i + 1], pref_max + 1);
		for (int j = max(0, i - r * 2); j <= i; ++j) {
			if (dist(inp[j].ff, inp[i + 1].ff) <= inp[i + 1].ss - inp[j].ss) {
				dp[i + 1] = max(dp[i + 1], dp[j] + 1);
			}
		}
		if (i - r * 2 >= 0) {
			pref_max = max(pref_max, dp[i - r * 2]);
		}
	}

	cout << *max_element(dp.begin(), dp.end()) << "\n";
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