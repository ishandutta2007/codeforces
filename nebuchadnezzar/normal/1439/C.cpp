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
	int bpv = 1;
	while (bpv < n) {
		bpv *= 2;
	}
	vector<ll> segtree(bpv * 2);
	vector<int> segtree_min(bpv * 2);
	vector<int> here(bpv * 2, -1);
	vector<int> arr;
	set<pii> segs;
	for (int i = 0; i < n; ++i) {
		int num;
		cin >> num;
		arr.push_back(num);
		segs.insert({-num, i});
		segtree[i + bpv] = num;
		segtree_min[i + bpv] = num;
	}
	for (int i = bpv - 1; i; --i) {
		segtree[i] = segtree[i * 2] + segtree[i * 2 + 1];
		segtree_min[i] = min(segtree_min[i * 2], segtree_min[i * 2 + 1]);
	}

	function<void(int, int, int, int, int, int)> segtree_segset = [&](int v, int vl, int vr, int l, int r, int val) {
		if (vr <= l || r <= vl) {
			return;
		}
		if (l <= vl && vr <= r) {
			segtree[v] = (ll) (vr - vl) * val;
			here[v] = val;
			segtree_min[v] = val;
			return;
		}

		int vm = (vl + vr) / 2;
		if (here[v] != -1) {
			segtree[v * 2] = (ll) (vm - vl) * here[v];
			segtree_min[v * 2] = here[v];
			here[v * 2] = here[v];
			segtree[v * 2 + 1] = (ll) (vm - vl) * here[v];
			segtree_min[v * 2 + 1] = here[v];
			here[v * 2 + 1] = here[v];
			here[v] = -1;
		}

		segtree_segset(v * 2, vl, vm, l, r, val);
		segtree_segset(v * 2 + 1, vm, vr, l, r, val);
		segtree[v] = segtree[v * 2] + segtree[v * 2 + 1];
		segtree_min[v] = min(segtree_min[v * 2], segtree_min[v * 2 + 1]);
	};

	function<int(int, int, int, int, int&)> find_take = [&](int v, int vl, int vr, int from, int& left) {
		if (from <= vl && segtree[v] <= left) {
			left -= segtree[v];
			return vr - vl;
		}
		if (vr - vl == 1) {
			return 0;
		}
		int vm = (vl + vr) / 2;
		if (here[v] != -1) {
			segtree[v * 2] = (ll) (vm - vl) * here[v];
			segtree_min[v * 2] = here[v];
			here[v * 2] = here[v];
			segtree[v * 2 + 1] = (ll) (vm - vl) * here[v];
			segtree_min[v * 2 + 1] = here[v];
			here[v * 2 + 1] = here[v];
			here[v] = -1;
		}
		int ret = 0;
		if (vm > from) {
			ret = find_take(v * 2, vl, vm, from, left);
			if (ret < vm - from) {
				return ret;
			}
		}

		return ret + find_take(v * 2 + 1, vm, vr, max(vm, from), left);
	};

	function<int(int, int, int, int, int)> find_skip = [&](int v, int vl, int vr, int from, int left) {
		if (from <= vl && segtree_min[v] > left) {
			return vr - vl;
		}
		if (vr - vl == 1) {
			return 0;
		}
		int vm = (vl + vr) / 2;
		if (here[v] != -1) {
			segtree[v * 2] = (ll) (vm - vl) * here[v];
			segtree_min[v * 2] = here[v];
			here[v * 2] = here[v];
			segtree[v * 2 + 1] = (ll) (vm - vl) * here[v];
			segtree_min[v * 2 + 1] = here[v];
			here[v * 2 + 1] = here[v];
			here[v] = -1;
		}
		int ret = 0;
		if (vm > from) {
			ret = find_skip(v * 2, vl, vm, from, left);
			if (ret < vm - from) {
				return ret;
			}
		}

		return ret + find_skip(v * 2 + 1, vm, vr, max(vm, from), left);
	};	

	segs.insert({0, n});

	for (int i = 0; i < q; ++i) {
		int t, x, y;
		cin >> t >> x >> y;
		if (t == 1) {
			auto it = segs.lower_bound({-y, -1});
			int from = it->ss;
			int to = x;
			if (from < to) {
				while (true) {
					if (it->ss >= x) {
						break;
					}
					auto next_it = it;
					++next_it;
					if (next_it->ss <= x) {
						segs.erase(it);
						it = next_it;
					} else {
						segs.insert({it->ff, x});
						segs.erase(it);
						break;
					}
				}
				segs.insert({-y, from});

				segtree_segset(1, 0, bpv, from, to, y);
			}
		} else {
			int pos = x - 1;
			int ans = 0;
			int left = y;
			while (pos < n) {
				// cerr << pos << " ";
				int val = min(find_take(1, 0, bpv, pos, left), n - pos);
				ans += val;
				pos += val;
				// cerr << pos << " ";
				pos += min(find_skip(1, 0, bpv, pos, left), n - pos);
				// cerr << pos << endl;
			}

			cout << ans << "\n";
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