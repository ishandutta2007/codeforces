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
	int n, k, p;
	cin >> n >> k >> p;
	vector<int> inp;
	for (int i = 0; i < n; ++i) {
		int num;
		cin >> num;
		inp.push_back(num);
	}
	vector<vector<int>> d(k, vector<int>(p, -INF));
	d[0][0] = 0;
	for (int i = 0; i < n - 1; ++i) {
		vector<vector<int>> next(k, vector<int>(p, -INF));
		for (int j = 0; j < k; ++j) {
			for (int j2 = 0; j2 < p; ++j2) {
				next[j][(j2 + inp[i]) % p] = max(next[j][(j2 + inp[i]) % p], d[j][j2]);
				if (j < k - 1) {
					next[j + 1][0] = max(next[j + 1][0], d[j][j2] + (j2 + inp[i]) % p);
				}
			}
		}
		swap(d, next);
	}

	int ans = 0;
	for (int j = 0; j < p; ++j) {
		ans = max(ans, d[k - 1][j] + (j + inp[n - 1]) % p);
	}

	cout << ans << "\n";
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