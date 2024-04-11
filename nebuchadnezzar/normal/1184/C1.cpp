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
	vector<pii> points;
	vector<int> arrx, arry;
	for (int i = 0; i < n * 4 + 1; ++i) {
		int x, y;
		cin >> x >> y;
		points.push_back({x, y});
		arrx.push_back(x);
		arry.push_back(y);
	}
	sort(arrx.begin(), arrx.end());
	arrx.erase(unique(arrx.begin(), arrx.end()), arrx.end());
	sort(arry.begin(), arry.end());
	arry.erase(unique(arry.begin(), arry.end()), arry.end());

	for (int x1 : arrx) {
		for (int x2 : arrx) {
			if (x2 <= x1) {
				continue;
			}
			for (int y1 : arry) {
				int y2 = y1 + (x2 - x1);
				auto it = lower_bound(arry.begin(), arry.end(), y2);
				if (it == arry.end() || *it != y2) {
					continue;
				}
				// cerr << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
				int cnt = 0;
				int any = -1;
				for (int i = 0; i < szof(points); ++i) {
					auto [x, y] = points[i];
					if ((x == x1 && y1 <= y && y <= y2) || (x == x2 && y1 <= y && y <= y2) || (y == y1 && x1 <= x && x <= x2) || (y == y2 && x1 <= x && x <= x2)) {

					} else {
						++cnt;
						any = i;
						if (cnt > 1) {
							break;
						}
					}
				}
				if (cnt == 1) {
					cout << points[any].ff << " " << points[any].ss << "\n";
					return;
				}
			}
		}
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