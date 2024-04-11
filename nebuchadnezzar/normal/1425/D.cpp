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

const int MAXN = 2007;
vector<int> factorial, inv_factorial;

int cnk(int n, int k) {
	if (k < 0 || k > n) {
		return 0;
	}
	return mult(factorial[n], mult(inv_factorial[k], inv_factorial[n - k]));
}

void solve() {
	int n, m, r;
	cin >> n >> m >> r;
	vector<pair<pii, int>> inp;
	for (int i = 0; i < n; ++i) {
		int x, y, b;
		cin >> x >> y >> b;
		inp.push_back({{x, y}, b});
	}

	factorial = {1};
	for (int i = 1; i < n + 10; ++i) {
		factorial.push_back(mult(factorial.back(), i));
	}

	inv_factorial = {inv(factorial.back())};
	for (int i = n + 9; i > 0; --i) {
		inv_factorial.push_back(mult(inv_factorial.back(), i));
	}
	reverse(inv_factorial.begin(), inv_factorial.end());

	int ans = 0;
	vector<bitset<MAXN>> matr(n);
	vector<int> szs(n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (max(abs(inp[i].ff.ff - inp[j].ff.ff), abs(inp[i].ff.ss - inp[j].ff.ss)) <= r) {
				matr[i][j] = 1;
			}
		}

		szs[i] = matr[i].count();
		// cerr << i << " " << sum(cnk(n, m), MOD - cnk(n - szs[i], m)) << endl;
		add(ans, mult(mult(inp[i].ss, inp[i].ss), sum(cnk(n, m), MOD - cnk(n - szs[i], m))));
	}

	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			int a = szs[i];
			int c = szs[j];
			int b = (matr[i] & matr[j]).count();
			int val = sum(sum(sum(cnk(n, m), MOD - cnk(n - a, m)), MOD - cnk(n - c, m)), cnk(n - a - c + b, m));
			// cerr << i << " " << j << " " << val << endl;
			add(ans, mult(2, mult(val, mult(inp[i].ss, inp[j].ss))));
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