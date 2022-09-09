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
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	vector<pair<pii, int>> segs;
	for (int i = 0; i < n; ++i) {
		int l = i, r = i + 1;
		if (s[i] == '1') {
			l = max(0, i - k), r = min(n, i + 1 + k);
		}
		segs.push_back({{l, r}, i + 1});
	}
	sort(segs.begin(), segs.end(), [&](auto& p1, auto& p2) {
		return p1.ff.ff < p2.ff.ff;
	});

	int bpv = 1;
	while (bpv < n + 1) {
		bpv *= 2;
	}

	vector<ll> segtree(bpv * 2, INFL);

	function<void(int, ll)> segtree_upd = [&](int pos, ll val) {
		pos += bpv;
		segtree[pos] = min(segtree[pos], val);
		pos /= 2;
		while (pos) {
			segtree[pos] = min(segtree[pos * 2], segtree[pos * 2 + 1]);
			pos /= 2;
		}
	};

	function<ll(int, int, int, int, int)> segtree_get = [&](int v, int vl, int vr, int l, int r) {
		if (r <= vl || vr <= l) {
			return INFL;
		}
		if (l <= vl && vr <= r) {
			return segtree[v];
		}
		int vm = (vl + vr) / 2;
		return min(segtree_get(v * 2, vl, vm, l, r), segtree_get(v * 2 + 1, vm, vr, l, r));
	};

	segtree_upd(0, 0);

	for (auto& s : segs) {
		ll val = segtree_get(1, 0, bpv, s.ff.ff, bpv);
		segtree_upd(s.ff.ss, val + s.ss);
	}

	cout << segtree_get(1, 0, bpv, n, n + 1) << "\n";
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