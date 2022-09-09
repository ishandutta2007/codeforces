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
	int n;
	ll t;
	cin >> n >> t;
	vector<pll> bad_seg;
	for (int i = 0; i < n; ++i) {
		ll g, c;
		cin >> g >> c;
		bad_seg.push_back({g - c, t - c});
	}
	ll tot_d = 0;
	ll pref = 0;
	for (int i = 0; i < n; ++i) {
		bad_seg[i].ff -= pref;
		bad_seg[i].ss -= pref;
		if (i < n - 1) {
			ll num;
			cin >> num;
			pref += num;
			tot_d += num;
		}
	}

	vector<ll> arrx;

	for (int i = 0; i < n; ++i) {
		if (bad_seg[i].ff >= 0) {
			ll q = bad_seg[i].ff / t;
			bad_seg[i].ff -= q * t;
			bad_seg[i].ss -= q * t;
		} else {
			ll q = (abs(bad_seg[i].ff) + t - 1) / t;
			bad_seg[i].ff += q * t;
			bad_seg[i].ss += q * t;
		}
		// cerr << bad_seg[i].ff << " " << bad_seg[i].ss << endl;
		arrx.push_back(bad_seg[i].ss % t);
		arrx.push_back((bad_seg[i].ff + t - 1) % t);
	}

	sort(arrx.begin(), arrx.end());
	arrx.erase(unique(arrx.begin(), arrx.end()), arrx.end());

	int bpv = 1;
	while (bpv < szof(arrx)) {
		bpv *= 2;
	}

	vector<ll> segtree(bpv * 2), set_here(bpv * 2, INFL * 2);
	auto segtree_pushdown = [&](int v) {
		if (set_here[v] != INFL * 2) {
			segtree[v * 2] = set_here[v];
			set_here[v * 2] = set_here[v];
			segtree[v * 2 + 1] = set_here[v];
			set_here[v * 2 + 1] = set_here[v];
			set_here[v] = INFL * 2;
		}
	};

	function<void(int, int, int, int, int, ll)> segtree_segset = [&](int v, int vl, int vr, int l, int r, ll val) {
		if (r <= vl || vr <= l) {
			return;
		}
		if (l <= vl && vr <= r) {
			segtree[v] = val;
			set_here[v] = val;
			return;
		}
		segtree_pushdown(v);
		int vm = (vl + vr) / 2;
		segtree_segset(v * 2, vl, vm, l, r, val);
		segtree_segset(v * 2 + 1, vm, vr, l, r, val);
		segtree[v] = min(segtree[v * 2], segtree[v * 2 + 1]);
	};

	function<ll(int, int, int, int, int)> segtree_get = [&](int v, int vl, int vr, int l, int r) {
		if (r <= vl || vr <= l) {
			return INFL;
		}
		if (l <= vl && vr <= r) {
			return segtree[v];
		}
		segtree_pushdown(v);
		int vm = (vl + vr) / 2;
		return min(segtree_get(v * 2, vl, vm, l, r), segtree_get(v * 2 + 1, vm, vr, l, r));
	};

	for (int i = 0; i < szof(arrx); ++i) {
		segtree_segset(1, 0, bpv, i, i + 1, -arrx[i]);
	}
	
	for (int i = 0; i < n; ++i) {
		// for (int j = 0; j < szof(arrx); ++j) {
		// 	cerr << arrx[j] << " " << segtree_get(1, 0, bpv, j, j + 1) + arrx[j] << "\n";
		// }
		// cerr << bad_seg[i].ff << " " << bad_seg[i].ss << endl;
		// cerr << endl;
		ll val = INFL;
		int from = lower_bound(arrx.begin(), arrx.end(), bad_seg[i].ff) - arrx.begin();
		int to = upper_bound(arrx.begin(), arrx.end(), bad_seg[i].ss) - arrx.begin();
		ll tmp = segtree_get(1, 0, bpv, from, to);
		segtree_segset(1, 0, bpv, from, to, INFL);
		val = min(val, tmp + bad_seg[i].ss);
		if (bad_seg[i].ss >= t) {
			int to2 = upper_bound(arrx.begin(), arrx.end(), bad_seg[i].ss % t) - arrx.begin();
			tmp = segtree_get(1, 0, bpv, 0, to2);
			val = min(val, tmp + bad_seg[i].ss % t);
			segtree_segset(1, 0, bpv, 0, to2, INFL);
		}
		int pos = lower_bound(arrx.begin(), arrx.end(), bad_seg[i].ss % t) - arrx.begin();
		segtree_segset(1, 0, bpv, pos, pos + 1, val - arrx[pos]);
	}

	ll ans = INFL;

	for (int i = 0; i < szof(arrx); ++i) {
		ans = min(ans, segtree_get(1, 0, bpv, i, i + 1) + arrx[i]);
	}

	cout << ans + tot_d << "\n";
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