// Created by Nikolay Budin

#ifdef LOCAL
#  define _GLIBCXX_DEBUG
#else
#  define cerr __get_ce
#endif
#include <bits/stdc++.h>
#define ff first
#define ss second
#define szof(x) ((int)x.size())

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
	vector<int> arr;
	for (int i = 0; i < n; ++i) {
		int num;
		cin >> num;
		arr.push_back(num);
	}

	int q;
	cin >> q;

	int bpv = 1;
	while (bpv < q) {
		bpv *= 2;
	}

	vector<int> segtree(bpv * 2);
	vector<vector<pii>> here(n);

	for (int i = 0; i < q; ++i) {
		int type;
		cin >> type;
		if (type == 1) {
			int p, x;
			cin >> p >> x;
			--p;
			here[p].push_back({i, x});
		} else {
			int x;
			cin >> x;
			segtree[bpv + i] = x;
		}
	}

	for (int i = bpv - 1; i; --i) {
		segtree[i] = max(segtree[i * 2], segtree[i * 2 + 1]);
	}

	function<int(int, int, int, int, int)> segtree_get = [&](int v, int vl, int vr, int l, int r) {
		if (vr <= l || r <= vl) {
			return 0;
		}
		if (l <= vl && vr <= r) {
			return segtree[v];
		}
		int vm = (vl + vr) / 2;
		return max(segtree_get(v * 2, vl, vm, l, r), segtree_get(v * 2 + 1, vm, vr, l, r));
	};

	for (int i = 0; i < n; ++i) {
		int val = arr[i];
		int from = 0;
		if (szof(here[i])) {
			val = here[i].back().ss;
			from = here[i].back().ff;
		}
		val = max(val, segtree_get(1, 0, bpv, from, q));
		cout << val << " ";
	}
	cout << "\n";
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