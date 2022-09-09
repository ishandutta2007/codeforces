// Created by Nikolay Budin

#ifdef DEBUG
#  define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
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
	vector<pair<pii, int>> segs;
	vector<int> arrx;
	for (int i = 0; i < n; ++i) {
		int x, y, c;
		cin >> x >> y >> c;
		segs.push_back({{min(x, y), max(x, y)}, c});
		arrx.push_back(x);
		arrx.push_back(y);
	}
	sort(arrx.begin(), arrx.end());
	arrx.erase(unique(arrx.begin(), arrx.end()), arrx.end());
	int bpv = 1;
	while (bpv < szof(arrx)) {
		bpv *= 2;
	}
	vector<pair<ll, int>> segtree(bpv * 2);
	vector<ll> add_here(bpv * 2);
	for (int i = 0; i < szof(arrx); ++i) {
		segtree[bpv + i] = {arrx[i], i};
	}
	for (int i = bpv - 1; i; --i) {
		segtree[i] = max(segtree[i * 2], segtree[i * 2 + 1]);
	}

	function<void(int, int, int, int, int, int)> segtree_segadd = [&](int v, int vl, int vr, int l, int r, int val) {
		if (vr <= l || r <= vl) {
			return;
		}
		if (l <= vl && vr <= r) {
			add_here[v] += val;
			segtree[v].ff += val;
			return;
		}
		if (add_here[v]) {
			add_here[v * 2] += add_here[v];
			add_here[v * 2 + 1] += add_here[v];
			segtree[v * 2].ff += add_here[v];
			segtree[v * 2 + 1].ff += add_here[v];
			add_here[v] = 0;
		}
		int vm = (vl + vr) / 2;
		segtree_segadd(v * 2, vl, vm, l, r, val);
		segtree_segadd(v * 2 + 1, vm, vr, l, r, val);
		segtree[v] = max(segtree[v * 2], segtree[v * 2 + 1]);
	};

	function<pair<ll, int>(int, int, int, int, int)> segtree_getmax = [&](int v, int vl, int vr, int l, int r) {
		if (vr <= l || r <= vl) {
			return make_pair(-INFL, -1);
		}
		if (l <= vl && vr <= r) {
			return segtree[v];
		}
		if (add_here[v]) {
			add_here[v * 2] += add_here[v];
			add_here[v * 2 + 1] += add_here[v];
			segtree[v * 2].ff += add_here[v];
			segtree[v * 2 + 1].ff += add_here[v];
			add_here[v] = 0;
		}
		int vm = (vl + vr) / 2;
		return max(segtree_getmax(v * 2, vl, vm, l, r), segtree_getmax(v * 2 + 1, vm, vr, l, r));
	};

	sort(segs.begin(), segs.end(), [&](auto& p1, auto& p2) {
		return p1.ff.ss < p2.ff.ss;
	});

	ll best = 0;
	int lans = INF, rans = INF;
	int cnt = 0;
	for (int x : arrx) {
		while (cnt < szof(segs) && segs[cnt].ff.ss <= x) {
			auto& s = segs[cnt++];
			int l = lower_bound(arrx.begin(), arrx.end(), s.ff.ff) - arrx.begin();
			segtree_segadd(1, 0, bpv, 0, l + 1, s.ss);
		}
		int pos = lower_bound(arrx.begin(), arrx.end(), x) - arrx.begin();
		auto tmp = segtree_getmax(1, 0, bpv, 0, pos + 1);
		ll val = tmp.ff - x;
		if (val > best) {
			best = val;
			lans = arrx[tmp.ss];
			rans = x;
		}
	}

	cout << best << "\n" << lans << " " << lans << " " << rans << " " << rans << "\n";
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