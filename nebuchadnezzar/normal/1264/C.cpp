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
		b >>= 1;
	}
	return ret;
}

int inv(int num) {
	return mpow(num, MOD - 2);
}

pii comb_et(pii a, pii b) {
	return {sum(b.ff, mult(a.ff, b.ss)), mult(a.ss, b.ss)};
}

void solve() {
	int n, q;
	cin >> n >> q;
	vector<int> arr;
	for (int i = 0; i < n; ++i) {
		int p;
		cin >> p;
		arr.push_back(p);
	}
	int bpv = 1;
	while (bpv < n) {
		bpv *= 2;
	}
	vector<pii> segtree(bpv * 2);
	// int inv_100 = inv(100);
	for (int i = 0; i < bpv; ++i) {
		if (i < n) {
			int tmp = mult(100, inv(arr[i]));
			segtree[i + bpv] = {tmp, tmp};
		} else {
			segtree[i + bpv] = {0, 1};
		}
	}
	for (int i = bpv - 1; i; --i) {
		segtree[i] = comb_et(segtree[i * 2], segtree[i * 2 + 1]);
	}
	// for (int i = 1; i < bpv * 2; ++i) {
	// 	cerr << segtree[i].ff << " " << segtree[i].ss << endl;
	// }
	// cerr << endl;
	auto calc_et = [&](int l, int r) {
		l += bpv;
		r += bpv;
		pii resl = {0, 1}, resr = {0, 1};
		while (l < r) {
			if (l & 1) {
				resl = comb_et(resl, segtree[l++]);
			}
			if (r & 1) {
				resr = comb_et(segtree[--r], resr);
			}
			l /= 2;
			r /= 2;
		}
		auto res = comb_et(resl, resr);
		return res.ff;
	};
	int ans = calc_et(0, n);
	// cerr << ans << endl;
	set<int> checkpoints = {0, n};
	for (int i = 0; i < q; ++i) {
		int pos;
		cin >> pos;
		--pos;
		if (checkpoints.count(pos)) {
			checkpoints.erase(pos);
			auto it = checkpoints.lower_bound(pos);
			int next = *it;
			--it;
			int prev = *it;
			add(ans, MOD - calc_et(prev, pos));
			add(ans, MOD - calc_et(pos, next));
			add(ans, calc_et(prev, next));
		} else {
			auto it = checkpoints.lower_bound(pos);
			int next = *it;
			--it;
			int prev = *it;
			// cerr << prev << " " << pos << " " << next << endl;
			checkpoints.insert(pos);
			add(ans, calc_et(prev, pos));
			add(ans, calc_et(pos, next));
			add(ans, MOD - calc_et(prev, next));
		}
		cout << ans << "\n";
	}
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