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
			ret = mult(a, ret);
		}
		a = mult(a, a);
		b /= 2;
	}
	return ret;
}

int inv(int num) {
	return mpow(num, MOD - 2);
}

vector<int> fact, inv_fact;
vector<int> arrp2;

int cnk(int n, int k) {
	return mult(fact[n], mult(inv_fact[k], inv_fact[n - k]));
}

void solve() {
	int n, m, k;
	cin >> n >> m >> k;

	if (n == m) {
		cout << (ll) n * k % MOD << "\n";
		return;
	}

	int ans = 0;
	for (int i = 0; i <= m; ++i) {
		int val = mult((ll) i * k % MOD, arrp2[i]);
		// cerr << i << " " << val << " " << cnk(n - i - 1, m - i) << endl;
		add(ans, mult(val, cnk(n - i - 1, m - i)));
	}

	cout << mult(ans, inv(mpow(2, n))) << "\n";
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
	arrp2 = {1};
	const int MAXN = 1e6 + 10;
	for (int i = 1; i <= MAXN; ++i) {
		fact.push_back(mult(fact.back(), i));
		arrp2.push_back(mult(arrp2.back(), 2));
	}

	inv_fact.push_back(inv(fact.back()));
	for (int i = MAXN; i > 0; --i) {
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