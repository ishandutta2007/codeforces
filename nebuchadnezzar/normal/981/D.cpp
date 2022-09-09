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

const int MAXN = 105;
int d[MAXN][MAXN];

void solve() {
	int n, k;
	cin >> n >> k;
	vector<ll> arr;
	for (int i = 0; i < n; ++i) {
		ll num;
		cin >> num;
		arr.push_back(num);
	}

	ll cur_mask = 0;
	for (int b = 62; b >= 0; --b) {
		cur_mask |= (1ll << b);

		for (int i = 0; i <= n; ++i) {
			for (int j = 0; j <= k; ++j) {
				d[i][j] = 0;
			}
		}
		d[0][0] = 1;
		for (int i = 0; i < n; ++i) {
			ll cur_sum = 0;
			for (int j = i; j < n; ++j) {
				cur_sum += arr[j];
				if ((cur_sum & cur_mask) == cur_mask) {
					for (int q = 0; q < k; ++q) {
						//d[j + 1] = max(d[j + 1], d[i] + 1);
						d[j + 1][q + 1] |= d[i][q];
					}
				}
			}
		}

		if (d[n][k]) {
			//cerr << "setted " << b << endl;
		} else {
			cur_mask ^= (1ll << b);
		}
	}

	cout << cur_mask << "\n";
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