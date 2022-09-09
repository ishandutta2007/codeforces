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
typedef pair<ll, ll> pll;

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


void solve() {
	int k, q;
	cin >> k >> q;
	int mask = (1 << k) - 1;
	int bpv = 1 << k;
	vector<int> segtree_l(bpv * 2), segtree_m(bpv * 2);
	auto segtree_or_eq = [&](vector<int>& segtree, int l, int r, int val) {
		l += bpv; r += bpv;
		while (l < r) {
			if (l & 1) {
				segtree[l++] |= val;
			}
			if (r & 1) {
				segtree[--r] |= val;
			}
			l /= 2; r /= 2;
		}
	};

	vector<pair<pll, int>> inp;
	for (int i = 0; i < q; ++i) {
		ll l, r;
		int v;
		cin >> l >> r >> v;
		inp.push_back({{l, r}, v});
		int lm = l >> k;
		int rm = r >> k;
		segtree_or_eq(segtree_m, lm, rm + 1, v);
		if (lm == rm) {
			segtree_or_eq(segtree_l, l & mask, (r & mask) + 1, v);
		} else if (lm + 1 == rm) {
			segtree_or_eq(segtree_l, l & mask, 1 << k, v);
			segtree_or_eq(segtree_l, 0, (r & mask) + 1, v);
		} else {
			segtree_or_eq(segtree_l, 0, 1 << k, v);
		}
	}

	for (int i = 1; i < bpv; ++i) {
		segtree_l[i * 2] |= segtree_l[i];
		segtree_l[i * 2 + 1] |= segtree_l[i];

		segtree_m[i * 2] |= segtree_m[i];
		segtree_m[i * 2 + 1] |= segtree_m[i];
	}

	// for (int i = 0; i < 1 << k; ++i) {
	// 	cerr << segtree_l[bpv + i] << " ";
	// }
	// cerr << endl;
	// for (int i = 0; i < 1 << k; ++i) {
	// 	cerr << segtree_m[bpv + i] << " ";
	// }
	// cerr << endl;

	vector<vector<int>> pref_sum_m, pref_sum_l;
	for (int i = 0; i < 16; ++i) {
		pref_sum_m.push_back({0});
		for (int j = 0; j < 1 << k; ++j) {
			pref_sum_m[i].push_back(pref_sum_m[i].back() + ((segtree_m[bpv + j] >> i) & 1));
		}

		pref_sum_l.push_back({0});
		for (int j = 0; j < 1 << k; ++j) {
			pref_sum_l[i].push_back(pref_sum_l[i].back() + ((segtree_l[bpv + j] >> i) & 1));
		}
	}

	for (int i = 0; i < q; ++i) {
		auto [l, r] = inp[i].ff;
		int lm = l >> k;
		int rm = r >> k;
		for (int j = 0; j < 16; ++j) {
			if (inp[i].ss & (1 << j)) {
				continue;
			}
			// bool has_m = pref_sum_m[j][lm] != pref_sum_m[j][rm + 1];
			// bool has_l = false;
			if (lm == rm) {
				// segtree_or_eq(segtree_l, l & mask, (r & mask) + 1, v);
				bool has_m = pref_sum_m[j][lm] != pref_sum_m[j][rm + 1];
				bool has_l = pref_sum_l[j][l & mask] != pref_sum_l[j][(r & mask) + 1];
				if (has_l && has_m) {
					// cerr << i << " " << j << endl;
					cout << "impossible\n";
					return;
				}
			} else {
				bool has_m = pref_sum_m[j][lm] != pref_sum_m[j][lm + 1];
				bool has_l = pref_sum_l[j][l & mask] != pref_sum_l[j][1 << k];
				if (has_l && has_m) {
					// cerr << i << " " << j << endl;
					cout << "impossible\n";
					return;
				}
				has_m = pref_sum_m[j][rm] != pref_sum_m[j][rm + 1];
				has_l = pref_sum_l[j][0] != pref_sum_l[j][(r & mask) + 1];
				if (has_l && has_m) {
					// cerr << i << " " << j << endl;
					cout << "impossible\n";
					return;
				}
				if (lm + 1 < rm) {
					has_m = pref_sum_m[j][lm + 1] != pref_sum_m[j][rm];
					has_l = pref_sum_l[j][0] != pref_sum_l[j][1 << k];
					if (has_l && has_m) {
						// cerr << i << " " << j << endl;
						cout << "impossible\n";
						return;
					}
				}
			}
		}
	}

	cout << "possible\n";
	for (int i = 0; i < 1 << k; ++i) {
		cout << segtree_l[bpv + i] << "\n";
	}
	for (int i = 0; i < 1 << k; ++i) {
		cout << segtree_m[bpv + i] << "\n";
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