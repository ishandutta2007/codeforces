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

void add(int& a, int b, int mod) {
	a += b;
	if (a >= mod) {
		a -= mod;
	}
}

int sum(int a, int b, int mod) {
	add(a, b, mod);
	return a;
}

int mult(int a, int b, int mod) {
	return (ll) a * b % mod;
}

int mpow(int a, int b, int mod) {
	int ret = 1;
	while (b) {
		if (b & 1) {
			ret = mult(ret, a, mod);
		}
		a = mult(a, a, mod);
		b /= 2;
	}
	return ret;
}

int inv(int num, int mod) {
	return mpow(num, mod - 2, mod);
}

void solve() {
	int n, m, a, q;
	cin >> n >> m >> a >> q;
	int p = 1;
	while (mpow(a, p, q) != 1) {
		++p;
	}

	vector<int> factorial = {1};
	for (int i = 1; i <= m; ++i) {
		factorial.push_back(mult(factorial.back(), i, p));
	}

	vector<int> inv_factorial = {inv(factorial.back(), p)};

	for (int i = m; i > 0; --i) {
		inv_factorial.push_back(mult(inv_factorial.back(), i, p));
	}

	reverse(inv_factorial.begin(), inv_factorial.end());

	auto cnk = [&](int n, int k) {
		return mult(factorial[n], mult(inv_factorial[k], inv_factorial[n - k], p), p);
	};

	vector<int> pref = {0};
	for (int i = 0; i <= min(n, m); ++i) {
		pref.push_back(sum(pref.back(), cnk(m, i), p));
	}

	for (int i = 0; i < n; ++i) {
		int r = n - i;
		cout << mpow(a, pref[min(m + 1, r)], q) << " ";
	}
	cout << "\n";
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