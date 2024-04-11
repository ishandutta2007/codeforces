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
	int n, q;
	cin >> n >> q;
	vector<int> state(n, -1);
	vector<int> dsu(n + 1);
	vector<int> left_el(n + 1);
	iota(dsu.begin(), dsu.end(), 0);
	iota(left_el.begin(), left_el.end(), 0);
	auto get_root = [&](int v) {
		int mem = v;
		while (dsu[v] != v) {
			v = dsu[v];
		}
		while (dsu[mem] != mem) {
			int tmp = dsu[mem];
			dsu[mem] = v;
			mem = tmp;
		}
		return v;
	};

	vector<multiset<int>> segs_in_el(n);

	auto del_seg = [&](int l, int r) {
		while (true) {
			int pos = get_root(l);
			if (pos >= r) {
				break;
			}
			state[pos] = 0;
			dsu[pos] = pos + 1;
			int next = get_root(pos);
			left_el[next] = left_el[pos];
			if (szof(segs_in_el[pos])) {
				int next2 = get_root(next + 1);
				while (szof(segs_in_el[pos]) && *segs_in_el[pos].begin() <= next2) {
					state[next] = 1;
					segs_in_el[pos].erase(segs_in_el[pos].begin());
				}
				if (szof(segs_in_el[pos]) > szof(segs_in_el[next])) {
					swap(segs_in_el[pos], segs_in_el[next]);
				}
				for (int num : segs_in_el[pos]) {
					segs_in_el[next].insert(num);
				}
				segs_in_el[pos].clear();
			}
		}
		int next = get_root(l);
		int from = left_el[next];
		if (0 < from) {
			if (szof(segs_in_el[from - 1])) {
				while (szof(segs_in_el[from - 1]) && *segs_in_el[from - 1].begin() <= next) {
					state[from - 1] = 1;
					segs_in_el[from - 1].erase(segs_in_el[from - 1].begin());
				}
			}
		}
	};

	auto add_seg = [&](int l, int r) {
		int pos = get_root(l);
		if (get_root(pos + 1) >= r) {
			state[pos] = 1;
			return;
		}
		segs_in_el[pos].insert(r);
	};

	for (int i = 0; i < q; ++i) {
		int t;
		cin >> t;
		if (t == 0) {
			int l, r, x;
			cin >> l >> r >> x;
			--l;
			if (x == 0) {
				del_seg(l, r);
			} else {
				add_seg(l, r);
			}
		} else {
			int ind;
			cin >> ind;
			--ind;
			if (state[ind] == -1) {
				cout << "N/A\n";
			} else if (state[ind] == 0) {
				cout << "NO\n";
			} else {
				cout << "YES\n";
			}
		}
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