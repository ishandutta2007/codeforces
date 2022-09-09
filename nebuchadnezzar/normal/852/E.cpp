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

const int MOD = 1'000'000'007;

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

void solve() {
	int n;
	cin >> n;
	if (n == 1) {
		cout << "1\n";
		return;
	}
	vector<vector<int>> graph(n);
	for (int i = 0; i < n - 1; ++i) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	vector<pii> dp(n);

	function<void(int, int)> dfs = [&](int v, int p) {
		int sum_odd = 1, sum_even = 1;
		int cnt = 0;
		for (int to : graph[v]) {
			if (to != p) {
				++cnt;
				dfs(to, v);
				sum_odd = mult(sum_odd, dp[to].ss);
				sum_even = mult(sum_even, dp[to].ff);
			}
		}
		if (cnt == 0) {
			sum_odd = 0;
		}
		int res = sum(sum_odd, sum_even);
		dp[v] = {res, res};
		// cerr << v << " " << dp[v].ff << " " << dp[v].ss << endl;
	};

	dfs(0, 0);

	int ans = 0;

	function<void(int, int, int, int)> dfs2 = [&](int v, int p, int val_odd, int val_even) {
		for (int to : graph[v]) {
			if (to != p) {
				val_odd = mult(val_odd, dp[to].ss);
				val_even = mult(val_even, dp[to].ff);
			}
		}

		// cerr << val_odd << " " << val_even << endl;
		// cerr << v << " " << sum(val_odd, val_even) << endl;
		add(ans, sum(val_odd, val_even));

		add(val_even, val_odd);
		val_odd = val_even;

		if (v == 0 && szof(graph[v]) == 1) {
			val_odd = val_even = dp[graph[v][0]].ff;
		}

		for (int to : graph[v]) {
			if (to != p) {
				dfs2(to, v, mult(val_odd, inv(dp[to].ss)), mult(val_even, inv(dp[to].ff)));
			}
		}
	};

	dfs2(0, 0, 1, 1);
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