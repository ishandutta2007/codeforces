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
	vector<int> inp;
	for (int i = 0; i < n; ++i) {
		int num;
		cin >> num;
		inp.push_back(num);
	}

	vector<int> ans;
	for (int k = 1; k <= n; ++k) {
		int prev = 0;
		vector<int> arr;
		bool flag = true;
		for (int i = 0; i < n; ++i) {
			int diff = inp[i] - prev;
			if (i < k) {
				arr.push_back(diff);
			} else {
				if (arr[i % k] != diff) {
					flag = false;
				}
			}
			prev = inp[i];
		}
		if (flag) {
			ans.push_back(k);
		}
	}

	cout << szof(ans) << "\n";
	for (int num : ans) {
		cout << num << " ";
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