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
	int n, k0, k1;
	cin >> n >> k0 >> k1;
	int k = k0 + k1;
	vector<int> arr;
	for (int i = 0; i < n; ++i) {
		int num;
		cin >> num;
		arr.push_back(num);
	}

	for (int i = 0; i < n; ++i) {
		int num;
		cin >> num;
		arr[i] = abs(arr[i] - num);
	}

	for (int i = 0; i < k; ++i) {
		int pos = max_element(arr.begin(), arr.end()) - arr.begin();
		if (arr[pos] == 0) {
			++arr[pos];
		} else {
			--arr[pos];
		}
	}

	ll ans = 0;
	for (int i = 0; i < n; ++i) {
		ans += (ll) arr[i] * arr[i];
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