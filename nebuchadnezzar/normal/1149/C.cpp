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

struct value {
	int ans;
	int maxv, minv, maxvsl, maxvsr;
	int add;
	value() {}
	value(int num) : ans(0), maxv(num), minv(num), maxvsl(-num), maxvsr(-num), add(0) {}
	value operator+(value const& other) const {
		if (maxv == -INF) {
			return other;
		}
		if (other.maxv == -INF) {
			return *this;
		}
		value ret;
		ret.add = 0;
		ret.ans = max(ans, other.ans);
		ret.ans = max(ret.ans, max(maxvsr + other.maxv, maxv + other.maxvsl));
		ret.maxv = max(maxv, other.maxv);
		ret.minv = min(minv, other.minv);
		ret.maxvsl = max(maxvsl, other.maxvsl);
		ret.maxvsl = max(ret.maxvsl, other.maxv - 2 * minv);
		ret.maxvsr = max(maxvsr, other.maxvsr);
		ret.maxvsr = max(ret.maxvsr, maxv - 2 * other.minv);
		return ret;
	}
};

void solve() {
	int n, q;
	cin >> n >> q;
	string s;
	cin >> s;
	int bpv = 1;
	while (bpv < szof(s) + 1) {
		bpv *= 2;
	}
	vector<value> segtree(bpv * 2);

	int pref = 0;
	for (int i = 0; i < szof(s); ++i) {
		segtree[bpv + i] = value(pref);
		if (s[i] == '(') {
			++pref;
		} else {
			--pref;
		}
	}
	segtree[bpv + szof(s)] = value(pref);

	for (int i = bpv - 1; i; --i) {
		segtree[i] = segtree[i * 2] + segtree[i * 2 + 1];
	}

	function<void(int, int, int, int, int, int)> segtree_add = [&](int v, int vl, int vr, int l, int r, int val) {
		if (vr <= l || r <= vl) {
			return;
		}
		if (l <= vl && vr <= r) {
			segtree[v].add += val;
			segtree[v].maxvsl -= val;
			segtree[v].maxvsr -= val;
			segtree[v].maxv += val;
			segtree[v].minv += val;
			return;
		}
		int vm = (vl + vr) / 2;
		if (segtree[v].add) {
			segtree_add(v * 2, vl, vm, vl, vm, segtree[v].add);
			segtree_add(v * 2 + 1, vm, vr, vm, vr, segtree[v].add);
			segtree[v].add = 0;
		}
		segtree_add(v * 2, vl, vm, l, r, val);
		segtree_add(v * 2 + 1, vm, vr, l, r, val);
		segtree[v] = segtree[v * 2] + segtree[v * 2 + 1];
	};

	function<value(int, int, int, int, int)> segtree_get = [&](int v, int vl, int vr, int l, int r) {
		if (vr <= l || r <= vl) {
			return value(-INF);
		}
		if (l <= vl && vr <= r) {
			return segtree[v];
		}
		int vm = (vl + vr) / 2;
		if (segtree[v].add) {
			segtree_add(v * 2, vl, vm, vl, vm, segtree[v].add);
			segtree_add(v * 2 + 1, vm, vr, vm, vr, segtree[v].add);
			segtree[v].add = 0;
		}
		return segtree_get(v * 2, vl, vm, l, r) + segtree_get(v * 2 + 1, vm, vr, l, r);
	};

	cout << segtree_get(1, 0, bpv, 0, szof(s) + 1).ans << "\n";

	for (int i = 0; i < q; ++i) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		if (a > b) {
			swap(a, b);
		}

		if (s[a] != s[b]) {
			if (s[a] == '(') {
				segtree_add(1, 0, bpv, a + 1, b + 1, -2);
			} else {
				segtree_add(1, 0, bpv, a + 1, b + 1, 2);
			}
			swap(s[a], s[b]);
		}

		auto tmp = segtree_get(1, 0, bpv, 0, szof(s) + 1);
		cout << tmp.ans << "\n";
		// cerr << tmp.maxv << " " << tmp.minv << " " << tmp.maxvsl << " " << tmp.maxvsr << endl;
		// for (int j = 0; j <= szof(s); ++j) {
		// 	cerr << segtree_get(1, 0, bpv, j, j + 1).maxv << " ";
		// }
		// cerr << endl;
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