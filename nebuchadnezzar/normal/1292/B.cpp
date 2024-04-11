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
typedef pair<ll, ll> pll;

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

void add(ll& a, ll b) {
	a += b;
	if (a > INFL) {
		a = INFL;
	}
}

void solve() {
	ll x0, y0, ax, ay, bx, by;
	cin >> x0 >> y0 >> ax >> ay >> bx >> by;
	ll sx, sy, t;
	cin >> sx >> sy >> t;
	vector<pll> points;
	while (true) {
		points.push_back({x0, y0});
		double nx = (double) x0 * ax + bx;
		double ny = (double) y0 * ay + by;
		if (nx > INFL * 2 || ny > INFL * 2) {
			break;
		}
		x0 = x0 * ax + bx;
		y0 = y0 * ay + by;
	}

	// for (auto p : points) {
	// 	cerr << p.ff << " " << p.ss << endl;
	// }

	int ans = 0;

	for (int l = 0; l < szof(points); ++l) {
		for (int r = l; r < szof(points); ++r) {
			ll sum = 0;
			ll cx = sx, cy = sy;
			for (int i = l; i <= r; ++i) {
				add(sum, abs(cx - points[i].ff));
				add(sum, abs(cy - points[i].ss));
				tie(cx, cy) = points[i];
			}
			if (sum <= t) {
				ans = max(ans, r - l + 1);
			}
			cx = sx, cy = sy;
			sum = 0;
			for (int i = r; i >= l; --i) {
				// if (l == 2 && r == 3) {
				// 	cerr << sum << " " << cx << " " << cy << " " << points[i].ff << " " << points[i].ss << endl;
				// }
				add(sum, abs(cx - points[i].ff));
				add(sum, abs(cy - points[i].ss));
				tie(cx, cy) = points[i];
			}
			// cerr << r << " " << l << " " << sum << endl;
			if (sum <= t) {
				ans = max(ans, r - l + 1);
			}
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