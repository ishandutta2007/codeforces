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

const int MOD = 998'244'353;

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
	string s;
	cin >> s;
	rotate(s.begin(), find(s.begin(), s.end(), '?'), s.end());
	reverse(s.begin(), s.end());

	int zero = n + 2;
	bool is_even = true;
	int shift = 0;
	int cnt = 0;

	for (int i = 0; i < n - 1; ++i) {
		if (s[i] == 'w') {
			if (is_even) {
				++shift;
			} else {
				--shift;
			}
		} else if (s[i] == 'b') {
			if (is_even) {
				--shift;
			} else {
				++shift;
			}
		} else {
			--shift;
			++cnt;
		}

		is_even = !is_even;
	}

	int ans = 0;

	vector<int> factorial = {1};
	for (int i = 1; i < cnt + 5; ++i) {
		factorial.push_back(mult(factorial.back(), i));
	}

	vector<int> inv_factorial = {inv(factorial.back())};
	for (int i = cnt + 4; i >= 1; --i) {
		inv_factorial.push_back(mult(inv_factorial.back(), i));
	}
	reverse(inv_factorial.begin(), inv_factorial.end());

	auto cnk = [&](int n, int k) {
		return mult(factorial[n], mult(inv_factorial[k], inv_factorial[n - k]));
	};

	// cerr << shift << endl;

	for (int i = 0; i <= cnt; ++i) {
		int vars = cnk(cnt, i);
		int pos = i * 2 + shift;
		int segs = abs(pos);
		int last;
		if (pos > 0) {
			if (pos & 1) {
				last = 0;
			} else {
				last = 1;
			}
		} else {
			if (pos & 1) {
				last = 1;
			} else {
				last = 0;
			}
		}
		if (segs % 4 == 3) {
			++segs;
		} else {
			--segs;
		}
		add(ans, mult(vars, segs / 4));
	}

	ans = mult(ans, mpow(inv(2), count(s.begin(), s.end(), '?') - 1));

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