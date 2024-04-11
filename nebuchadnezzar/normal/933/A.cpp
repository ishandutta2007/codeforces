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

	vector<int> ones_before = {0};
	for (int i = 0; i < n; ++i) {
		if (inp[i] == 2) {
			ones_before.push_back(ones_before.back());
		} else {
			ones_before.push_back(ones_before.back() + 1);
		}
	}
	vector<int> twos_after = {0};
	for (int i = n - 1; i >= 0; --i) {
		if (inp[i] == 1) {
			twos_after.push_back(twos_after.back());
		} else {
			twos_after.push_back(twos_after.back() + 1);
		}
	}
	reverse(twos_after.begin(), twos_after.end());
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		vector<int> d = {0, 0};
		for (int j = i; j < n; ++j) {
			auto next = d;
			if (inp[j] == 2) {
				next[0] = d[0] + 1;
			} else {
				next[1] = max(d[0], d[1]) + 1;
			}
			ans = max(ans, ones_before[i] + max(next[0], next[1]) + twos_after[j + 1]);
			d = next;
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