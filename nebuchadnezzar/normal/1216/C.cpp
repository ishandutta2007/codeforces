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

bool lies_inside(pair<pii, pii> const& rect, int x, int y) {
	return rect.ff.ff <= x && x < rect.ss.ff && rect.ff.ss <= y && y < rect.ss.ss;
}

void solve() {
	vector<pair<pii, pii>> rects;
	vector<int> arrx, arry;
	for (int i = 0; i < 3; ++i) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		rects.push_back({{x1, y1}, {x2, y2}});
		for (int x : {x1, x2}) {
			for (int dx = -3; dx <= 3; ++dx) {
				arrx.push_back(x + dx);
			}
		}
		for (int y : {y1, y2}) {
			for (int dy = -3; dy <= 3; ++dy) {
				arry.push_back(y + dy);
			}
		}
	}

	sort(arrx.begin(), arrx.end());
	arrx.erase(unique(arrx.begin(), arrx.end()), arrx.end());
	sort(arry.begin(), arry.end());
	arry.erase(unique(arry.begin(), arry.end()), arry.end());

	for (int x : arrx) {
		for (int y : arry) {
			if (lies_inside(rects[0], x, y) && !lies_inside(rects[1], x, y) && !lies_inside(rects[2], x, y)) {
				cout << "YES\n";
				return;
			}
		}
	}
	cout << "NO\n";
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