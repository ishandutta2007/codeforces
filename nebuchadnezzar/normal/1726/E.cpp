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

int inv(int num) {
	return mpow(num, MOD - 2);
}

const int MAXN = 3e5 + 5;
vector<int> fact, inv_fact;

int cnk(int n, int k) {
	return mult(fact[n], mult(inv_fact[k], inv_fact[n - k]));
}

void solve() {
	int n;
	cin >> n;

	int ans = 0;
	vector<int> dp(n + 1);
	vector<int> dp2(n + 1);
	dp2[0] = 1;
	dp[0] = 1;
	for (int i = 1; i <= n; ++i) {
		dp2[i] = dp2[i - 1];
		if (i >= 2) {
			add(dp[i], mult(2, mult(i - 1, dp[i - 2])));
			add(dp2[i], mult(i - 1, dp2[i - 2]));
		}
	}
	for (int k = 0; k <= n; ++k) {
		if ((n - k) % 4) {
			continue;
		}

		int pairs = (n - k) / 2;
		int cur = cnk(pairs + k, k);
		cur = mult(cur, dp[pairs]);
		cur = mult(cur, dp2[k]);
		add(ans, cur);
		// cerr << k << " " << cur << endl;
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

	fact = {1};
	for (int i = 1; i < MAXN; ++i) {
		fact.push_back(mult(fact.back(), i));
	}

	inv_fact = {inv(fact.back())};
	for (int i = MAXN - 1; i >= 1; --i) {
		inv_fact.push_back(mult(inv_fact.back(), i));
	}

	reverse(inv_fact.begin(), inv_fact.end());

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