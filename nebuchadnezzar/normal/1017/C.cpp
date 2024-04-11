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
	/*
	int n = 1;
	//cin >> n;
	for (; n <= 10; ++n) {
		vector<int> order(n);
		iota(order.begin(), order.end(), 0);
		int ans = INF;
		do {
			vector<int> d1(n), d2(n);
			for (int i = 0; i < n; ++i) {
				d1[i] = 1;
				d2[i] = 1;
				for (int j = 0; j < i; ++j) {
					if (order[j] < order[i]) {
						d1[i] = max(d1[i], d1[j] + 1);
					} else {
						d2[i] = max(d2[i], d2[j] + 1);
					}
				}
			}
			ans = min(ans, *max_element(d1.begin(), d1.end()) + *max_element(d2.begin(), d2.end()));
		} while (next_permutation(order.begin(), order.end()));

		cout << n << " " << ans << "\n";
	}
	*/
	int n;
	cin >> n;
	int ans = INF;
	int mem = 1;
	for (int i = 1; i <= n; ++i) {
		if (ans > i + (n + i - 1) / i) {
			ans = i + (n + i - 1) / i;
			mem = i;
		}
	}

	//cout << ans << "\n";
	//cerr << mem << endl;
	for (int i = n - mem; i + mem > 0; i -= mem) {
		for (int j = i; j < i + mem; ++j) {
			if (j >= 0) {
				cout << j + 1 << " ";
			}
		}
	}
	cout << "\n";
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