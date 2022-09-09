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
typedef pair<ll, ll> pll;
int const INF = (int)1e9 + 1e3;
ll const INFL = (ll)1e18 + 1e6;
mt19937 tw(9450189);
uniform_int_distribution<ll> ll_distr;
ll rnd(ll a, ll b) { return ll_distr(tw) % (b - a + 1) + a; }


void solve() {
	int n;
	cin >> n;
	vector<ll> arr;
	for (int i = 0; i < n; ++i) {
		ll l;
		cin >> l;
		arr.push_back(l);
	}
	string s;
	cin >> s;

	vector<pll> poly;
	pll from = {0, 0};
	if (s[0] == 'G') {
		poly.push_back({0, 5});
	} else {
		poly.push_back({0, 3});
	}

	function<void(int, ll)> add_seg = [&](int coef, ll len) {
		for (int j = 0; j < szof(poly); ++j) {
			if (poly[j].ss == coef) {
				for (int k = j + 1; k < szof(poly); ++k) {
					poly[k].ff += len;
				}
				return;
			} else if (poly[j].ss > coef) {
				ll mem = poly[j].ff;
				for (int k = j; k < szof(poly); ++k) {
					poly[k].ff += len;
				}
				poly.insert(poly.begin() + j, {mem, coef});
				return;
			}
		}
	};

	for (int i = 0; i < n; ++i) {
		if (s[i] == 'G') {
			pll shift = {-arr[i], arr[i]};
			pll seg = {arr[i] * 2, arr[i] * 4};
			from.ff += shift.ff;
			from.ss += shift.ss;
			add_seg(2, seg.ff);
			ll last = INFL * 5;
			while (szof(poly) && poly.back().ss > 5) {
				last = poly.back().ff;
				poly.pop_back();
			}
			if (!szof(poly) || (poly.back().ss != 5 && last != INFL * 5)) {
				poly.push_back({last, 5});
			}
		} else if (s[i] == 'W') {
			pll shift = {-arr[i], arr[i]};
			pll seg = {arr[i] * 2, arr[i] * 2};
			from.ff += shift.ff;
			from.ss += shift.ss;
			add_seg(1, seg.ff);
			ll last = INFL * 5;
			while (szof(poly) && poly.back().ss > 3) {
				last = poly.back().ff;
				poly.pop_back();
			}
			if (!szof(poly) || (poly.back().ss != 3 && last != INFL * 5)) {
				poly.push_back({last, 3});
			}
		} else {
			from.ff -= arr[i];
			from.ss += arr[i];
		}

		vector<pll> next;
		pll next_from;
		for (int i = 0; i < szof(poly); ++i) {
			if (from.ff >= 0) {
				next.push_back({from.ff, poly[i].ss});
				if (i < szof(poly) - 1) {
					from.ff += poly[i + 1].ff - poly[i].ff;
				}
			} else {
				if (i == szof(poly) - 1) {
					next_from = {0, from.ss + (-from.ff) * poly[i].ss};
					next.push_back({0, poly[i].ss});
				} else {
					if (from.ff + (poly[i + 1].ff - poly[i].ff) < 0) {
						from.ff += poly[i + 1].ff - poly[i].ff;
						from.ss += (poly[i + 1].ff - poly[i].ff) * poly[i].ss;
					} else {
						next_from = {0, from.ss + (-from.ff) * poly[i].ss};
						next.push_back({0, poly[i].ss});
						from.ff += poly[i + 1].ff - poly[i].ff;
						from.ss += (poly[i + 1].ff - poly[i].ff) * poly[i].ss;
					}
				}
			}
		}

		swap(from, next_from);
		swap(poly, next);

		// for (auto p : poly) {
		// 	cerr << p.ff << " " << p.ss << endl;
		// }
		// cerr << endl;
	}

	// cerr << from.ff << " " << from.ss << endl;

	for (int i = 0; i < szof(poly); ++i) {
		// cerr << i << " " << poly[i].ff << " " << poly[i].ss << endl;
		if (i == szof(poly) - 1 || from.ff + (poly[i + 1].ff - poly[i].ff) > 0) {
			cout << from.ss + poly[i].ss * (-from.ff) << "\n";
			return;
		} else {
			from.ss += poly[i].ss * (poly[i + 1].ff - poly[i].ff);
			from.ff += poly[i + 1].ff - poly[i].ff;
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