#include "bits/stdc++.h"
#define ff first
#define ss second
#define szof(_x) ((int) (_x).size())
#define TASK_NAME ""

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 1e9 + 7;
const ll INFL = 1e18 + 123;
const double PI = atan2(0, -1);
mt19937 tw(960172);
ll rnd(ll x, ll y) { static uniform_int_distribution<ll> d; return d(tw) % (y - x + 1) + x; }


void solve() {
	int n, m;
	cin >> n >> m;
	vector<pii> arr1, arr2;
	for (int i = 0; i < n; ++i) {
		int a, b;
		cin >> a >> b;
		if (a > b) {
			swap(a, b);
		}
		arr1.push_back({a, b});
	}
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		if (a > b) {
			swap(a, b);
		}
		arr2.push_back({a, b});
	}

	int cnt = 0, any = -1;
	for (int i = 1; i <= 9; ++i) {
		bool fl = false;
		for (auto tmp1 : arr1) {
			for (auto tmp2 : arr2) {
				if (tmp2.ff == tmp1.ff && tmp2.ss == tmp1.ss) {
					continue;
				}
				//cerr << tmp1.ff << " " << tmp1.ss << " " << tmp2.ff << " " << tmp2.ss << endl;
				if ((tmp2.ff == i || tmp2.ss == i) && (tmp1.ff == i || tmp1.ss == i)) {
					fl = true;
					break;
				}
			}
			if (fl) {
				break;
			}
		}
		if (fl) {
			cnt++;
			any = i;
			//cerr << i << endl;
		}
	}

	if (cnt == 1) {
		cout << any << "\n";
		return;
	}

	for (auto tmp1 : arr1) {
		int a, b;
		tie(a, b) = tmp1;
		for (auto tmp2 : arr2) {
			int c, d;
			tie(c, d) = tmp2;
			if (a == c && b == d) {
				continue;
			}

			if (a != c && a != d && b != c && b != d) {
				continue;
			}

			int cnt1 = 0;
			for (int i : {a, b}) {
				bool fl2 = false;
				for (auto p : arr2) {
					if (p.ff == a && p.ss == b) {
						continue;
					}
					fl2 |= p.ff == i || p.ss == i;
				}
				if (fl2) {
					++cnt1;
				}
			}

			if (cnt1 > 1) {
				cout << "-1\n";
				return;
			}

			int cnt2 = 0;
			for (int i : {c, d}) {
				bool fl1 = false;
				for (auto p : arr1) {
					if (p.ff == c && p.ss == d) {
						continue;
					}
					fl1 |= p.ff == i || p.ss == i;
				}
				if (fl1) {
					++cnt2;
				}
			}

			if (cnt2 > 1) {
				cout << "-1\n";
				return;
			}
		}
	}

	cout << "0\n";
}


int main() {
	//freopen(TASK_NAME ".in", "r", stdin);
	//freopen(TASK_NAME ".out", "w", stdout);
	cerr << fixed << setprecision(15);
	cout << fixed << setprecision(15);
	ios::sync_with_stdio(false);

	int tests = 1;
	// cin >> tests;
	for (int it = 1; it <= tests; ++it) {
		solve();
	}
	
	#ifdef LOCAL
		cerr << "time: " << clock() << " ms\n";
	#endif
	return 0;
}