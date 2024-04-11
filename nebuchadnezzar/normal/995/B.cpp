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
	vector<int> inp;
	for (int i = 0; i < n * 2; ++i) {
		int num;
		cin >> num;
		--num;
		inp.push_back(num);
	}

	int ans = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			vector<int> v1, v2;
			for (int k = 0; k < n * 2; ++k) {
				if (inp[k] == i) {
					v1.push_back(k);
				}
				if (inp[k] == j) {
					v2.push_back(k);
				}
			}

			int tmp1 = 0, tmp2 = 0;
			for (int num1 : v1) {
				for (int num2 : v2) {
					tmp1 += (num1 < num2);
					tmp2 += (num2 < num1);
				}
			}
			ans += min(tmp1, tmp2);
		}
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