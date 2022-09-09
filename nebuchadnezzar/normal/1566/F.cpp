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

#define int long long

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


void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> points;
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		points.push_back(x);
	}

	sort(points.begin(), points.end());

	vector<pii> segs;
	for (int i = 0; i < m; ++i) {
		int l, r;
		cin >> l >> r;
		segs.push_back({l, r});
	}

	sort(segs.begin(), segs.end(), [&](pii a, pii b) {
		if (a.ff != b.ff) {
			return a.ff < b.ff;
		}

		return a.ss > b.ss;
	});

	{
		vector<pii> tmp;
		for (auto seg : segs) {
			while (szof(tmp) && tmp.back().ss >= seg.ss) {
				tmp.pop_back();
			}
			tmp.push_back(seg);
		}
		swap(segs, tmp);

		tmp.clear();
		int cnt = 0;
		for (auto seg : segs) {
			while (cnt < szof(points) && points[cnt] < seg.ff) {
				++cnt;
			}
			if (cnt == szof(points) || points[cnt] > seg.ss) {
				tmp.push_back(seg);
			}
		}

		swap(tmp, segs);
	}

	if (szof(segs) == 0) {
		cout << "0\n";
		return;
	}

	vector<pair<int, ll>> vars, next_vars;

	if (segs[0].ff < points[0]) {
		vars.push_back({segs[0].ss, 0});
	} else {
		vars.push_back({points[0], 0});
	}

	int cnt = 0;
	while (cnt < szof(segs) && segs[cnt].ss < points[0]) {
		++cnt;
	}

	for (int i = 0; i < szof(points); ++i) {
		int x = points[i];
		int from = cnt;
		while (cnt < szof(segs) && (i == szof(points) - 1 || segs[cnt].ss < points[i + 1])) {
			++cnt;
		}
		next_vars.clear();

		ll best_double = INFL, best_single = INFL;
		for (int j = 0; j < szof(vars); ++j) {
			best_double = min(best_double, vars[j].ss + (ll) (x - vars[j].ff) * 2);
			best_single = min(best_single, vars[j].ss + x - vars[j].ff);
		}

		for (int j = from; j <= cnt; ++j) {
			ll d = 0;
			if (from < j) {
				d = segs[j - 1].ff - x;
			}
			ll best = min(d * 2 + best_single, d + best_double);
			int nx = i == szof(points) - 1 ? INF : points[i + 1];
			if (j < cnt) {
				nx = segs[j].ss;
			}
			next_vars.push_back({nx, best});
		}

		swap(vars, next_vars);
	}

	cout << vars.back().ss << "\n";
}


int32_t main() {
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