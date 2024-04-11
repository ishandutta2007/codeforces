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
	int x1, y1, x2, y2, x3, y3;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

	vector<pii> have = {{x1, y1}, {x2, y2}, {x3, y3}};
	set<pii> ans;
	for (auto p : have) {
		ans.insert(p);
	}

	while (true) {
		int cnt = 0;
		int minx = INF;
		int any = -1;
		for (int j = 0; j < 3; ++j) {
			if (minx > have[j].ff) {
				minx = have[j].ff;
				cnt = 1;
				any = j;
			} else if (minx == have[j].ff) {
				++cnt;
			}
		}

		if (cnt > 1) {
			break;
		}

		have[any].ff++;
		ans.insert(have[any]);
	}

	while (true) {
		int cnt = 0;
		int maxx = -INF;
		int any = -1;
		for (int j = 0; j < 3; ++j) {
			if (maxx < have[j].ff) {
				maxx = have[j].ff;
				cnt = 1;
				any = j;
			} else if (maxx == have[j].ff) {
				++cnt;
			}
		}

		if (cnt > 1) {
			break;
		}

		have[any].ff--;
		ans.insert(have[any]);
	}

	while (true) {
		int cnt = 0;
		int miny = INF;
		int any = -1;
		for (int j = 0; j < 3; ++j) {
			if (miny > have[j].ss) {
				miny = have[j].ss;
				cnt = 1;
				any = j;
			} else if (miny == have[j].ss) {
				++cnt;
			}
		}

		if (cnt > 1) {
			break;
		}

		have[any].ss++;
		ans.insert(have[any]);
	}

	while (true) {
		int cnt = 0;
		int maxy = -INF;
		int any = -1;
		for (int j = 0; j < 3; ++j) {
			if (maxy < have[j].ss) {
				maxy = have[j].ss;
				cnt = 1;
				any = j;
			} else if (maxy == have[j].ss) {
				++cnt;
			}
		}

		if (cnt > 1) {
			break;
		}

		have[any].ss--;
		ans.insert(have[any]);
	}

	cout << szof(ans) << "\n";

	for (auto p : ans) {
		cout << p.ff << " " << p.ss << "\n";
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