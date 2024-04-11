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
	int cl, ce, v;
	cin >> cl >> ce >> v;

	vector<int> ladders;
	for (int i = 0; i < cl; ++i) {
		int x;
		cin >> x;
		ladders.push_back(x);
	}

	vector<int> elevators;
	for (int i = 0; i < ce; ++i) {
		int x;
		cin >> x;
		elevators.push_back(x);
	}

	int q;
	cin >> q;
	for (int i = 0; i < q; ++i) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		if (y1 > y2) {
			swap(y1, y2);
		}
		if (x1 == x2) {
			cout << abs(y1 - y2) << "\n";
		} else {
			int ans = INF * 2;
			if (szof(ladders)) {
				auto it = lower_bound(ladders.begin(), ladders.end(), y1);
				if (it != ladders.end()) {
					ans = min(ans, abs(*it - y1) + abs(*it - y2) + abs(x1 - x2));
				}
				it = upper_bound(ladders.begin(), ladders.end(), y2);
				if (it != ladders.begin()) {
					--it;
					ans = min(ans, abs(*it - y1) + abs(*it - y2) + abs(x1 - x2));
				}
			}

			if (szof(elevators)) {
				auto it = lower_bound(elevators.begin(), elevators.end(), y1);
				if (it != elevators.end()) {
					ans = min(ans, abs(*it - y1) + abs(*it - y2) + (abs(x1 - x2) + v - 1) / v);
				}
				it = upper_bound(elevators.begin(), elevators.end(), y2);
				if (it != elevators.begin()) {
					--it;
					ans = min(ans, abs(*it - y1) + abs(*it - y2) + (abs(x1 - x2) + v - 1) / v);
				}
			}
			cout << ans << "\n";
		}

	}
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