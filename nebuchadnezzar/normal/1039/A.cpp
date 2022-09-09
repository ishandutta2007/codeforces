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
	ll t;
	cin >> n >> t;
	vector<ll> a;
	for (int i = 0; i < n; ++i) {
		ll num;
		cin >> num;
		a.push_back(num);
	}
	vector<int> x;
	for (int i = 0; i < n; ++i) {
		int num;
		cin >> num;
		--num;
		x.push_back(num);
	}

	vector<vector<int>> pref(2, vector<int>(n + 2));
	for (int i = 0; i < n; ++i) {
		if (x[i] < i) {
			cout << "No\n";
			return;
		}
		pref[0][i + 1] += 1;
		pref[0][x[i] + 1] -= 1;
		pref[1][x[i] + 1] += 1;
		pref[1][x[i] + 2] -= 1;
	}

	vector<ll> b;
	int amount[2] = {0, 0};
	for (int i = 1; i < n; ++i) {
		amount[0] += pref[0][i];
		amount[1] += pref[1][i];
		if (amount[0] && amount[1]) {
			cout << "No\n";
			return;
		}
		if (amount[0]) {
			ll from = 1;
			if (szof(b)) {
				from = b.back() + 1;
			}
			b.push_back(max(from, a[i] + t));
		} else if (amount[1]) {
			ll from = 1;
			if (szof(b)) {
				from = b.back() + 1;
			}
			b.push_back(max(from, a[i - 1] + t));
			if (b.back() >= a[i] + t) {
				cout << "No\n";
				return;
			}
		} else {
			ll from = 1;
			if (szof(b)) {
				from = b.back() + 1;
			}
			b.push_back(max(from, a[i - 1] + t));
		}
	}

	ll from = 1;
	if (szof(b)) {
		from = b.back() + 1;
	}
	b.push_back(max(from, a.back() + t));

	for (int i = 0; i < n - 1; ++i) {
		if (b[i] >= b[i + 1]) {
			cout << "No\n";
			return;
		}
	}

	cout << "Yes\n";
	for (auto num : b) {
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