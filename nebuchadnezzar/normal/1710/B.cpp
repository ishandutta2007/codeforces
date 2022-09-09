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

tuple<ll, ll, ll> comb(tuple<ll, ll, ll> const& v1, tuple<ll, ll, ll> const& v2) {
	return {max(get<0>(v1), get<0>(v2)), max(get<1>(v1), get<1>(v2)), max(get<2>(v1), get<2>(v2))};
}

void solve() {
	int n, m;
	cin >> n >> m;
	vector<pii> days;
	vector<pii> events;
	vector<int> arrx;
	for (int i = 0; i < n; ++i) {
		int x, p;
		cin >> x >> p;
		days.push_back({x, p});
		events.push_back({x - p, 1});
		events.push_back({x, -2});
		events.push_back({x + p, 1});
		arrx.push_back(x);
	}

	sort(events.begin(), events.end());
	sort(arrx.begin(), arrx.end());
	arrx.erase(unique(arrx.begin(), arrx.end()), arrx.end());

	ll dy = 0;
	ll y = 0;
	int prevx = -INF;
	int cnt = 0;
	vector<ll> arry;
	for (int x : arrx) {
		while (cnt < szof(events) && events[cnt].ff < x) {
			y += (events[cnt].ff - prevx) * dy;
			prevx = events[cnt].ff;
			dy += events[cnt].ss;
			++cnt;
		}
		arry.push_back(y + dy * (x - prevx));
	}

	int bpv = 1;
	while (bpv < szof(arrx)) {
		bpv *= 2;
	}

	vector<tuple<ll, ll, ll>> segtree(bpv * 2, {-INFL, -INFL, -INFL});
	for (int i = 0; i < szof(arrx); ++i) {
		segtree[bpv + i] = {arry[i], arry[i] + arrx[i], arry[i] - arrx[i]};
	}

	for (int i = bpv - 1; i > 0; --i) {
		segtree[i] = comb(segtree[i * 2], segtree[i * 2 + 1]);
	}

	auto segtree_get = [&](int l, int r) {
		l += bpv; r += bpv;
		tuple<ll, ll, ll> ret = {-INFL, -INFL, -INFL};
		while (l < r) {
			if (l & 1) {
				ret = comb(ret, segtree[l++]);
			}
			if (r & 1) {
				ret = comb(ret, segtree[--r]);
			}
			l /= 2; r /= 2;
		}
		return ret;
	};

	for (int i = 0; i < n; ++i) {
		int pos1 = lower_bound(arrx.begin(), arrx.end(), days[i].ff - days[i].ss) - arrx.begin();
		int pos2 = lower_bound(arrx.begin(), arrx.end(), days[i].ff) - arrx.begin();
		int pos3 = lower_bound(arrx.begin(), arrx.end(), days[i].ff + days[i].ss) - arrx.begin();
		ll res = get<0>(segtree_get(0, pos1));
		res = max(res, get<2>(segtree_get(pos1, pos2)) - days[i].ss + days[i].ff);
		res = max(res, get<1>(segtree_get(pos2, pos3)) - days[i].ss - days[i].ff);
		res = max(res, get<0>(segtree_get(pos3, bpv)));
		if (res <= m) {
			cout << "1";
		} else {
			cout << "0";
		}
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
	cin >> test_count;
	for (int test = 1; test <= test_count; ++test) {
		solve();
	}

#ifdef LOCAL
	auto end_time = clock();
	cerr << "Execution time: " << (end_time - start_time) * (int)1e3 / CLOCKS_PER_SEC << " ms\n";
#endif
}