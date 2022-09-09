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

void solve() {
	int n, m;
	cin >> n >> m;

	vector<int> fact = {1};
	for (int i = 1; i < max(n, m) + 5; ++i) {
		fact.push_back(mult(fact.back(), i));
	}
	vector<int> inv_fact = {inv(fact.back())};
	for (int i = max(n, m) + 4; i >= 1; --i) {
		inv_fact.push_back(mult(inv_fact.back(), i));
	}
	reverse(inv_fact.begin(), inv_fact.end());

	auto cnk = [&](int n, int k) {
		return mult(fact[n], mult(inv_fact[k], inv_fact[n - k]));
	};

	auto ank = [&](int n, int k) {
		return mult(fact[n], inv_fact[n - k]);
	};

	vector<ll> pref = {0};
	for (int i = 0; i < n; ++i) {
		int num;
		cin >> num;
		pref.push_back(pref.back() + num);
	}

	int cnt_pairs = 0;
	if (pref.back() % 2 == 0) {
		ll half = pref.back() / 2;
		set<ll> have(pref.begin(), pref.end());
		for (ll pos : pref) {
			if (pos < half && have.count(pos + half)) {
				++cnt_pairs;
			}
		}
	}

	int ans = 0;
	for (int i = 0; i <= cnt_pairs && i <= m; ++i) {
		int cur = mult(mult(mult(ank(m, i), cnk(cnt_pairs, i)), 
			mpow((ll) (m - i) * (m - i - 1) % MOD, cnt_pairs - i)), mpow(m - i, n - cnt_pairs * 2));
		add(ans, cur);
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