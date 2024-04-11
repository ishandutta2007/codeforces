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

	auto all = arr;
	all.push_back(-1);
	sort(all.begin(), all.end());
	all.erase(unique(all.begin(), all.end()), all.end());

	int bpv = 1;
	while (bpv < szof(all)) {
		bpv *= 2;
	}

	vector<int> segtree(bpv * 2, -INF);
	vector<int> add_here(bpv * 2, 0);

	auto push_down = [&](int v) {
		if (add_here[v]) {
			add_here[v * 2] += add_here[v];
			segtree[v * 2] += add_here[v];
			add_here[v * 2 + 1] += add_here[v];
			segtree[v * 2 + 1] += add_here[v];
			add_here[v] = 0;
		}
	};

	function<void(int, int, int, int, int, int)> segtree_segadd = [&](int v, int vl, int vr, int l, int r, int val) {
		if (r <= vl || vr <= l) {
			return;
		}
		if (l <= vl && vr <= r) {
			add_here[v] += val;
			segtree[v] += val;
			return;
		}
		push_down(v);
		int vm = (vl + vr) / 2;
		segtree_segadd(v * 2, vl, vm, l, r, val);
		segtree_segadd(v * 2 + 1, vm, vr, l, r, val);
		segtree[v] = max(segtree[v * 2], segtree[v * 2 + 1]);
	};

	function<int(int, int, int, int, int)> segtree_get = [&](int v, int vl, int vr, int l, int r) {
		if (r <= vl || vr <= l) {
			return -INF * 2;
		}
		if (l <= vl && vr <= r) {
			return segtree[v];
		}
		push_down(v);
		int vm = (vl + vr) / 2;
		return max(segtree_get(v * 2, vl, vm, l, r), segtree_get(v * 2 + 1, vm, vr, l, r));
	};

	for (int& num : arr) {
		num = lower_bound(all.begin(), all.end(), num) - all.begin();
	}

	segtree_segadd(1, 0, bpv, 0, 1, -segtree_get(1, 0, bpv, 0, 1) + 1);
	for (int i = 1; i < n; ++i) {
		int add = arr[i] != arr[i - 1];
		int val2 = max(max(segtree_get(1, 0, bpv, 0, arr[i]), segtree_get(1, 0, bpv, arr[i] + 1, bpv)) + 1, 
			segtree_get(1, 0, bpv, arr[i], arr[i] + 1));

		// cerr << add << " " << val2 << endl;

		segtree_segadd(1, 0, bpv, 0, bpv, add);
		int val3 = segtree_get(1, 0, bpv, arr[i - 1], arr[i - 1] + 1);
		if (val2 > val3) {
			segtree_segadd(1, 0, bpv, arr[i - 1], arr[i - 1] + 1, val2 - val3);
		}

		// for (int i = 0; i < szof(all); ++i) {
		// 	cerr << all[i] << " " << segtree_get(1, 0, bpv, i, i + 1) << "    ";
		// }
		// cerr << endl;
	}

	cout << segtree_get(1, 0, bpv, 0, bpv) << "\n";
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