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

int get_mex(int mask) {
	if (!(mask & 1)) {
		return 0;
	}
	if (!(mask & 2)) {
		return 1;
	}
	return 2;
}

void solve() {
	int n;
	cin >> n;
	vector<string> arr;
	for (int i = 0; i < 2; ++i) {
		string s;
		cin >> s;
		arr.push_back(s);
	}

	vector<int> dp(4, -INF);
	vector<int> next(4);
	dp[0] = 0;
	for (int i = 0; i < n; ++i) {
		fill(next.begin(), next.end(), -INF);
		for (int old_mask = 0; old_mask < 4; ++old_mask) {
			int mask = old_mask | (1 << (arr[0][i] - '0')) | (1 << (arr[1][i] - '0'));
			next[mask] = max(next[mask], dp[old_mask]);
			next[0] = max(next[0], dp[old_mask] + get_mex(mask));
		}

		swap(next, dp);
	}

	cout << dp[0] << "\n";
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