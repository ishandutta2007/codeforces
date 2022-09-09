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
	ll n;
	cin >> n;

	vector<int> inp;
	while (n) {
		inp.push_back(n % 10);
		n /= 10;
	}

	vector<int> d = {0, -INF};

	for (int i = 0; i < szof(inp); ++i) {
		vector<int> next = {-INF, -INF};
		for (int j = 0; j < 2; ++j) {
			for (int d1 = 0; d1 < 10; ++d1) {
				for (int d2 = 0; d2 < 10; ++d2) {
					if ((d1 + d2 + j) % 10 == inp[i]) {
						next[(d1 + d2 + j) / 10] = max(next[(d1 + d2 + j) / 10], d[j] + d1 + d2);
					}
				}
			}
		}
		swap(next, d);
	}

	cout << d[0] << "\n";
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