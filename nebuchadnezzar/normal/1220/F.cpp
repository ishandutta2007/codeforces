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
	vector<int> perm;
	for (int i = 0; i < n; ++i) {
		int num;
		cin >> num;
		--num;
		perm.push_back(num);
	}

	int bpv = 1;
	while (bpv < n * 2) {
		bpv *= 2;
	}
	int bp = 1;
	while (1 << bp <= n * 2) {
		++bp;
	}

	vector<int> segtree(bpv * 2);
	vector<vector<pii>> minv;

	minv.push_back({});
	for (int i = 0; i < n * 2; ++i) {
		minv[0].push_back({perm[i % n], i});
	}

	for (int i = 1; i < bp; ++i) {
		minv.push_back({});
		for (int j = 0; j + (1 << i) <= n * 2; ++j) {
			minv[i].push_back(min(minv[i - 1][j], minv[i - 1][j + (1 << (i - 1))]));
		}
	}

	vector<int> maxp(n * 2 + 5);
	for (int i = 1; i < n * 2 + 5; ++i) {
		maxp[i] = maxp[i - 1];
		if (1 << (maxp[i] + 1) <= i) {
			++maxp[i];
		}
	}

	auto get_min = [&](int l, int r) {
		int p = maxp[r - l];
		return min(minv[p][l], minv[p][r - (1 << p)]);
	};

	function<void(int, int, int)> rec = [&](int l, int r, int d) {
		if (l >= r) {
			return;
		}
		// cerr << l << " " << r << " " << d << endl;
		int pos = get_min(l, r).ss;
		segtree[bpv + pos] = d;
		if (l + 1 == r) {
			return;
		}
		rec(l, pos, d + 1);
		rec(pos + 1, r, d + 1);
	};

	rec(0, n, 0);
	for (int i = bpv - 1; i; --i) {
		segtree[i] = max(segtree[i * 2], segtree[i * 2 + 1]);
	}
	vector<int> add_here(bpv * 2);

	function<void(int, int, int, int, int, int)> segtree_segadd = [&](int v, int vl, int vr, int l, int r, int val) {
		if (vr <= l || r <= vl) {
			return;
		}
		if (l <= vl && vr <= r) {
			segtree[v] += val;
			add_here[v] += val;
			return;
		}
		if (add_here[v]) {
			segtree[v * 2] += add_here[v];
			segtree[v * 2 + 1] += add_here[v];
			add_here[v * 2] += add_here[v];
			add_here[v * 2 + 1] += add_here[v];
			add_here[v] = 0;
		}
		int vm = (vl + vr) / 2;
		segtree_segadd(v * 2, vl, vm, l, r, val);
		segtree_segadd(v * 2 + 1, vm, vr, l, r, val);
		segtree[v] = max(segtree[v * 2], segtree[v * 2 + 1]);
	};

	function<int(int, int, int, int, int)> segtree_getmax = [&](int v, int vl, int vr, int l, int r) {
		if (r <= vl || vr <= l) {
			return 0;
		}
		if (l <= vl && vr <= r) {
			return segtree[v];
		}
		if (add_here[v]) {
			segtree[v * 2] += add_here[v];
			segtree[v * 2 + 1] += add_here[v];
			add_here[v * 2] += add_here[v];
			add_here[v * 2 + 1] += add_here[v];
			add_here[v] = 0;
		}
		int vm = (vl + vr) / 2;
		return max(segtree_getmax(v * 2, vl, vm, l, r), segtree_getmax(v * 2 + 1, vm, vr, l, r));
	};

	int best = INF;
	int mem = -1;

	for (int i = 0; i < n; ++i) {
		int from = i, to = i + n;
		// cerr << i << endl;
		// for (int j = from; j < to; ++j) {
		// 	cerr << segtree_getmax(1, 0, bpv, j, j + 1) << " ";
		// }
		// cerr << endl;
		if (segtree_getmax(1, 0, bpv, from, to) < best) {
			best = segtree_getmax(1, 0, bpv, from, to);
			mem = i;
		}
		int l = 0, r = n + 1;
		while (r - l > 1) {
			int mid = (l + r) / 2;
			if (get_min(from, from + mid).ff < perm[i]) {
				r = mid;
			} else {
				l = mid;
			}
		}
		// cerr << r << endl;
		segtree_segadd(1, 0, bpv, from + 1, from + l, -1);
		l = 0, r = n;
		while (r - l > 1) {
			int mid = (l + r) / 2;
			if (get_min(to - mid, to).ff < perm[i]) {
				r = mid;
			} else {
				l = mid;
			}
		}
		int pos_parent = to - r;
		if (r < n) {
			segtree_segadd(1, 0, bpv, to, to + 1, segtree_getmax(1, 0, bpv, pos_parent, pos_parent + 1) + 1);
		}
		segtree_segadd(1, 0, bpv, pos_parent + 1, to, 1);
	}

	cout << best + 1 << " " << mem << "\n";
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