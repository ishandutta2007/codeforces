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

	vector<int> p2 = {1};
	for (int i = 0; i < n; ++i) {
		p2.push_back(mult(p2.back(), 2));
	}

	int bpv = 1;
	while (bpv < n + 1) {
		bpv *= 2;
	}
	vector<int> segtree(bpv * 2);

	auto segtree_segadd = [&](int l, int r, int val) {
		l += bpv; r += bpv;
		while (l < r) {
			if (l & 1) {
				add(segtree[l++], val);
			}
			if (r & 1) {
				add(segtree[--r], val);
			}
			l /= 2; r /= 2;
		}
	};

	auto segtree_get = [&](int pos) {
		int ret = 0;
		pos += bpv;
		while (pos) {
			add(ret, segtree[pos]);
			pos /= 2;
		}
		return ret;
	};

	for (int i = 0; i * 2 < n; ++i) {
		segtree_segadd(n - i, n - i + 1, 1);
	}
	for (int i = n - 1; i >= 0; --i) {
		int val = segtree_get(i + 1);
		int part = i / 2;
		segtree_segadd(i - part + 1, i + 1, val);
	}

	// for (int i = 0; i <= n; ++i) {
	// 	cerr << segtree_get(i) << " ";
	// }
	// cerr << endl;

	int coef = inv(p2[n]);

	for (int i = 0; i < n; ++i) {
		int to_left = i;
		int part = (to_left + 1) / 2;
		int cur = p2[part];
		int res = mult(cur, segtree_get(i + 1));
		if (i == n - 1) {
			add(res, p2[n / 2]);
		}
		cout << mult(res, coef) << "\n";
	}
	// cout << "\n";
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