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


void solve() {
	int n;
	cin >> n;
	vector<int> arr;
	for (int i = 0; i < n; ++i) {
		int num;
		cin >> num;
		arr.push_back(num);
	}

	vector<int> sum(n);
	int bpv = 131072;
	vector<int> segtree(bpv * 2);

	auto segtree_add = [&](int pos, int val) {
		pos += bpv;
		while (pos) {
			segtree[pos] += val;
			pos /= 2;
		}
	};

	auto segtree_get = [&](int l, int r) {
		int ret = 0;
		l += bpv;
		r += bpv;
		while (l < r) {
			if (l & 1) {
				ret += segtree[l++];
			}
			if (r & 1) {
				ret += segtree[--r];
			}
			l /= 2; r /= 2;
		}

		return ret;
	};

	for (int i = 0; i < n; ++i) {
		segtree_add(arr[i], 1);
		sum[i] = segtree_get(arr[i] + 1, bpv);
	}

	fill(segtree.begin(), segtree.end(), 0);

	for (int i = n - 1; i >= 0; --i) {
		segtree_add(arr[i], 1);
		sum[i] += segtree_get(0, arr[i]);
	}

	vector<int> order(n);
	iota(order.begin(), order.end(), 0);

	stable_sort(order.begin(), order.end(), [&](int a, int b) {
		return arr[a] < arr[b];
	});

	int from = 0;
	for (int i = 0; i <= n; ++i) {
		if (i == n || arr[order[i]] != arr[order[from]]) {
			vector<pii> st;
			for (int j = from; j < i; ++j) {
				int cur = sum[order[j]] % 2;
				if (szof(st) && st.back().ss == cur) {
					st.back().ff++;
				} else {
					st.push_back({1, cur});
				}

				while (true) {
					if (szof(st) > 1 && st.back().ff % 2 == 0) {
						int tmp = st.back().ff;
						st.pop_back();
						st.back().ff += tmp;
					} else if (szof(st) == 2 && st.front().ff % 2 == 0) {
						int tmp = st.front().ff;
						st.erase(st.begin());
						st.back().ff += tmp;
					} else {
						break;
					}
				}
			}

			if (szof(st) != 1) {
				cout << "NO\n";
				return;
			}
			if (st[0].ss == 1 && st[0].ff % 2) {
				cout << "NO\n";
				return;
			}

			from = i;
		}
	}

	cout << "YES\n";
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