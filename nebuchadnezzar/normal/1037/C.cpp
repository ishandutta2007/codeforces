#ifdef LOCAL
#  define _GLIBCXX_DEBUG
#  define _GLIBCXX_DEBUG_PEDANTIC
#endif

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
	int n;
	cin >> n;
	string s, t;
	cin >> s >> t;
	vector<int> cost(n + 1, INF);
	cost[0] = 0;
	for (int i = 0; i < n; ++i) {
		if (s[i] != t[i]) {
			cost[i + 1] = cost[i] + 1;
			if (i > 0 && s[i - 1] != t[i - 1] && s[i - 1] != s[i]) {
				cost[i + 1] = min(cost[i + 1], cost[i - 1] + 1);
			}
		} else {
			cost[i + 1] = cost[i];
		}
	}

	cout << cost.back() << "\n";
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