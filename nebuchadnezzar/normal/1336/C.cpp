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

const int MOD = 998244353;

void add(int& a, int b) {
	a += b;
	if (a >= MOD) {
		a -= MOD;
	}
}

int sum(int a, int b) {
	add(a, b);
	return a;
}

int mult(int a, int b) {
	return (ll) a * b % MOD;
}

int mpow(int a, int b) {
	int ret = 1;
	while (b) {
		if (b & 1) {
			ret = mult(ret, a);
		}
		a = mult(a, a);
		b /= 2;
	}
	return ret;
}

void solve() {
	string s, t;
	cin >> s >> t;

	int ans = 0;
	vector<int> dp(szof(t));
	for (int i = 0; i < szof(t); ++i) {
		if (t[i] == s[0]) {
			dp[i] = 2;
		}
	}

	vector<int> next(szof(t));
	for (int i = 1; i < szof(s); ++i) {
		fill(next.begin(), next.end(), 0);
		for (int j = 0; j < szof(t); ++j) {
			if (j && t[j - 1] == s[i]) {
				add(next[j - 1], dp[j]);
			}
			int pos = j + i;
			if (pos >= szof(t) || s[i] == t[pos]) {
				add(next[j], dp[j]);
			}
			if (j == 0 && pos >= szof(t)) {
				// cerr << i << " " << dp[0] << endl;
				add(ans, dp[0]);
			}
		}
		swap(next, dp);
		// cerr << "i: " << i << endl;
		// for (int num : next) {
		// 	cerr << num << " ";
		// }
		// cerr << endl;
	}

	// cerr << dp[0] << endl;

	add(ans, dp[0]);

	// cerr << ans << endl;

	next = dp = vector<int>(szof(t) + 1);
	dp[0] = 2;
	for (int i = 1; i < szof(s); ++i) {
		fill(next.begin(), next.end(), 0);
		for (int j = 0; j < szof(t); ++j) {
			add(next[j], dp[j]);
			if (t[szof(t) - 1 - j] == s[i]) {
				add(next[j + 1], dp[j]);
			}
		}
		add(next[0], dp[0]);
		// cerr << i << " " << mult(next[szof(t)], sum(mpow(2, szof(s) - i), MOD - 1)) << endl;
		add(ans, mult(next[szof(t)], szof(s) - i));
		swap(next, dp);
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
	// cin >> test_count;
	for (int test = 1; test <= test_count; ++test) {
		solve();
	}

#ifdef LOCAL
	auto end_time = clock();
	cerr << "Execution time: " << (end_time - start_time) * (int)1e3 / CLOCKS_PER_SEC << " ms\n";
#endif
}