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
	int a, b;
	cin >> a >> b;
	int sum = a + b;
	vector<int> arr;
	int c = 1;
	while (sum >= c) {
		arr.push_back(c);
		sum -= c;
		++c;
	}

	vector<int> arra, arrb;
	for (int i = szof(arr) - 1; i >= 0; --i) {
		if (a >= arr[i]) {
			a -= arr[i];
			arra.push_back(arr[i]);
		} else {
			arrb.push_back(arr[i]);
		}
	}

	cout << szof(arra) << "\n";
	for (int num : arra) {
		cout << num << " ";
	}
	cout << "\n";
	cout << szof(arrb) << "\n";
	for (int num : arrb) {
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