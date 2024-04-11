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

const int MOD = 31607;

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
	return a * b % MOD;
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
	vector<vector<int>> prob(n, vector<int>(n));
	int C = inv(10000);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			int num;
			cin >> num;
			prob[i][j] = mult(num, C);
		}
	}

	int ans = 0;
	int none = 1;
	for (int i = 0; i < n; ++i) {
		int cur = 1;
		for (int j = 0; j < n; ++j) {
			cur = mult(cur, prob[i][j]);
		}
		none = mult(none, sum(1, MOD - cur));
	}
	ans = sum(1, MOD - none);
	// cerr << none << " " << mult(23438, inv(17734)) << endl;

	vector<int> column_prod(n, 1);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			column_prod[j] = mult(column_prod[j], prob[i][j]);
		}
	}

	vector<vector<int>> vals(n, vector<int>(1 << n));
	for (int i = 0; i < n; ++i) {
		vals[i][0] = 1;
		for (int mask = 1; mask < 1 << n; ++mask) {
			int any = __builtin_ctz(mask);
			vals[i][mask] = mult(vals[i][mask ^ (1 << any)], prob[i][any]);
		}
	}

	for (int mask = 1; mask < 1 << (n + 2); ++mask) {
		int cur_prod = 1;
		for (int i = 0; i < n; ++i) {
			if (mask & (1 << i)) {
				cur_prod = mult(cur_prod, column_prod[i]);
			} else {
				if (mask & (1 << n)) {
					cur_prod = mult(cur_prod, prob[i][i]);
				}
				if ((mask & (1 << (n + 1))) && (!(mask & (1 << n)) || i != n - 1 - i)) {
					cur_prod = mult(cur_prod, prob[n - 1 - i][i]);
				}
			}
		}

		// cerr << mask << " " << cur_prod << " " << mult(3 * 5 * 7, inv(1000)) << endl;

		for (int i = 0; i < n; ++i) {
			int left_mask = ~mask & ((1 << n) - 1);
			if (mask & (1 << n)) {
				left_mask &= ~(1 << i);
			}
			if (mask & (1 << (n + 1))) {
				left_mask &= ~(1 << (n - 1 - i));
			}
			cur_prod = mult(cur_prod, sum(1, MOD - vals[i][left_mask]));
		}

		// cerr << mask << " " << cur_prod << endl;

		if (__builtin_popcount(mask) % 2) {
			add(ans, cur_prod);
		} else {
			add(ans, MOD - cur_prod);
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
	// cin >> test_count;
	for (int test = 1; test <= test_count; ++test) {
		solve();
	}

#ifdef LOCAL
	auto end_time = clock();
	cerr << "Execution time: " << (end_time - start_time) * (int)1e3 / CLOCKS_PER_SEC << " ms\n";
#endif
}