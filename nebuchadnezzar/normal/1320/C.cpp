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
typedef pair<ll, ll> pll;
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

pll comb(pll const& a, pll const& b) {
	return {a.ff + b.ff, max(a.ss, a.ff + b.ss)};
}

void solve() {
	int n, m, p;
	cin >> n >> m >> p;
	vector<pii> arra;
	vector<pii> arrb;
	for (int i = 0; i < n; ++i) {
		int a, ca;
		cin >> a >> ca;
		arra.push_back({a, ca});
	}
	for (int i = 0; i < m; ++i) {
		int b, cb;
		cin >> b >> cb;
		arrb.push_back({b, cb});
	}

	vector<tuple<int, int, int>> events;
	vector<tuple<int, int, int>> monsters;
	for (int i = 0; i < p; ++i) {
		int x, y, z;
		cin >> x >> y >> z;
		monsters.push_back({x, y, z});
		events.push_back({x, 1, i});
	}

	for (int i = 0; i < n; ++i) {
		auto [a, ca] = arra[i];
		events.push_back({a, 0, i});
	}

	sort(events.begin(), events.end());

	vector<pii> arry;
	for (int i = 0; i < m; ++i) {
		arry.push_back({arrb[i].ff, 0});
	}
	for (int i = 0; i < p; ++i) {
		arry.push_back({get<1>(monsters[i]), i + 1});
	}

	sort(arry.begin(), arry.end());
	arry.resize(unique(arry.begin(), arry.end()) - arry.begin());

	int bpv = 1;
	while (bpv < szof(arry)) {
		bpv *= 2;
	}

	vector<pll> segtree(bpv * 2, {0, -INFL});

	auto segtree_set = [&](int pos, pll val) {
		pos += bpv;
		segtree[pos] = val;
		pos /= 2;
		while (pos) {
			segtree[pos] = comb(segtree[pos * 2], segtree[pos * 2 + 1]);
			pos /= 2;
		}
	};

	sort(arrb.begin(), arrb.end(), [&](auto& a, auto& b) {
		if (a.ff != b.ff) {
			return a.ff < b.ff;
		}
		return a.ss > b.ss;
	});
	vector<pii> new_arrb;
	for (auto [b, cb] : arrb) {
		while (szof(new_arrb) && new_arrb.back().ss >= cb) {
			new_arrb.pop_back();
		}
		new_arrb.push_back({b, cb});
	}

	for (auto [b, cb] : new_arrb) {
		int y_ind = lower_bound(arry.begin(), arry.end(), pii(b, 0)) - arry.begin();
		segtree_set(y_ind, {0, -cb});
	}

	ll ans = -INFL;

	for (auto [cx, t, ind] : events) {
		// cerr << cx << " " << t << " " << ind << " " << segtree[1].ss << endl;
		if (t == 0) {
			ans = max(ans, -arra[ind].ss + segtree[1].ss);
		} else {
			int y_ind = lower_bound(arry.begin(), arry.end(), pii(get<1>(monsters[ind]), ind + 1)) - arry.begin();
			segtree_set(y_ind, {get<2>(monsters[ind]), -INFL});
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