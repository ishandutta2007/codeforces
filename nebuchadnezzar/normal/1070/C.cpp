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


void solve() {
	int n, k, m;
	cin >> n >> k >> m;
	vector<pii> plans;
	vector<pii> acts;
	for (int i = 0; i < m; ++i) {
		int l, r, c, p;
		cin >> l >> r >> c >> p;
		--l;
		acts.push_back({l, i});
		acts.push_back({r, i});
		plans.push_back({c, p});
	}

	vector<int> order(m);
	iota(order.begin(), order.end(), 0);
	sort(order.begin(), order.end(), [&](int a, int b) {
		return plans[a].ss < plans[b].ss;
	});
	vector<int> where(m);
	for (int i = 0; i < m; ++i) {
		where[order[i]] = i;
	}
	sort(acts.begin(), acts.end());

	int bpv = 1;
	while (bpv < m) {
		bpv *= 2;
	}

	vector<pair<ll, ll>> rsq(bpv * 2);

	function<void(int, ll, ll)> segtree_set = [&](int pos, ll val1, ll val2) {
		pos += bpv;
		rsq[pos] = {val1, val2};
		pos /= 2;
		while (pos) {
			rsq[pos] = {rsq[pos * 2].ff + rsq[pos * 2 + 1].ff, rsq[pos * 2].ss + rsq[pos * 2 + 1].ss};
			pos /= 2;
		}
	};

	function<pair<int, pair<ll, ll>>(int, int, int, int)> segtree_find = [&](int v, int vl, int vr, int sz) {
		if (rsq[v].ff <= sz) {
			return make_pair(vr, rsq[v]);
		}
		if (vl + 1 == vr) {
			return make_pair(vl, make_pair(0ll, 0ll));
		}
		int vm = (vl + vr) / 2;
		auto tmp = segtree_find(v * 2, vl, vm, sz);
		if (tmp.ff < vm) {
			return tmp;
		}
		auto tmp2 = segtree_find(v * 2 + 1, vm, vr, sz - tmp.ss.ff);
		return make_pair(tmp2.ff, make_pair(tmp.ss.ff + tmp2.ss.ff, tmp.ss.ss + tmp2.ss.ss));
	};

	int c = 0;
	vector<bool> state(m);
	ll ans = 0;
	for (int i = 0; i < n; ++i) {
		while (c < szof(acts) && acts[c].ff == i) {
			int ind = acts[c].ss;
			if (state[ind]) {
				segtree_set(where[ind], 0, 0);
			} else {
				segtree_set(where[ind], plans[ind].ff, (ll) plans[ind].ff * plans[ind].ss);
			}

			state[ind] = state[ind] ^ 1;
			++c;
		}

		auto tmp = segtree_find(1, 0, bpv, k);
		ans += tmp.ss.ss;
		if (tmp.ff < bpv && tmp.ss.ff < k) {
			ans += (ll) (k - tmp.ss.ff) * plans[order[tmp.ff]].ss;
		}
	}

	cout << ans << "\n";
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