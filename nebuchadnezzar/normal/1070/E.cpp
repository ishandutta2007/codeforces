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
int const INF = (int)1e9 + 1e3;
ll const INFL = (ll)1e18 + 1e6;
mt19937 tw(9450189);
uniform_int_distribution<ll> ll_distr;
ll rnd(ll a, ll b) { return ll_distr(tw) % (b - a + 1) + a; }

pair<int, ll> comb(pair<int, ll> p1, pair<int, ll> p2) {
	return {p1.ff + p2.ff, p1.ss + p2.ss};
}

void solve() {
	int n, m;
	ll t;
	cin >> n >> m >> t;
	map<int, vector<int>> here;
	for (int i = 0; i < n; ++i) {
		int num;
		cin >> num;
		here[num].push_back(i);
	}

	int bpv = 1;
	while (bpv < n) {
		bpv *= 2;
	}

	vector<pair<int, ll>> rsq(bpv * 2);
	function<void(int, int, ll)> segtree_set = [&](int pos, int val, ll t) {
		pos += bpv;
		rsq[pos] = {val, t};
		pos /= 2;
		while (pos) {
			rsq[pos] = comb(rsq[pos * 2], rsq[pos * 2 + 1]);
			pos /= 2;
		}
	};

	function<pair<int, ll>(int, int, int, int, int)> segtree_get = [&](int v, int vl, int vr, int l, int r) {
		if (r <= vl || vr <= l) {
			return make_pair(0, 0ll);
		}
		if (l <= vl && vr <= r) {
			return rsq[v];
		}
		int vm = (vl + vr) / 2;
		return comb(segtree_get(v * 2, vl, vm, l, r), segtree_get(v * 2 + 1, vm, vr, l, r));
	};

	function<ll(int, int, int, int)> segtree_find = [&](int v, int vl, int vr, int sz) {
		if (rsq[v].ff <= sz) {
			return rsq[v].ss;
		}
		if (vl + 1 == vr) {
			return 0ll;
		}
		int vm = (vl + vr) / 2;
		if (rsq[v * 2].ff <= sz) {
			return rsq[v * 2].ss + segtree_find(v * 2 + 1, vm, vr, sz - rsq[v * 2].ff);
		}
		return segtree_find(v * 2, vl, vm, sz);
	};

	int best = -1;
	int ans = 1;

	for (auto& v : here) {
		for (int ind : v.ss) {
			segtree_set(ind, 1, v.ff);
		}

		int l = 0, r = n + 1;
		while (r - l > 1) {
			int mid = (l + r) / 2;
			auto tmp = segtree_get(1, 0, bpv, 0, mid);
			ll cost = tmp.ss;
			int part = (tmp.ff - 1) / m * m;
			cost += segtree_find(1, 0, bpv, part);
			// if (v.ff == 4 && mid == 11) {
			// 	cout << cost << " " << tmp.ff << " " << tmp.ss << endl;
			// }
			if (cost > t) {
				r = mid;
			} else {
				l = mid;
			}
		}

		int cur = segtree_get(1, 0, bpv, 0, l).ff;
		if (cur > best) {
			best = cur;
			ans = v.ff;
		}
	}

	ans = min((ll) ans, t);

	cout << best << " " << ans << "\n";
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