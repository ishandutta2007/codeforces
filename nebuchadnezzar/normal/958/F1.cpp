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
	int n, m;
	cin >> n >> m;
	vector<int> inp;
	for (int i = 0; i < n; ++i) {
		int num;
		cin >> num;
		--num;
		inp.push_back(num);
	}
	vector<int> need(m);
	for (int i = 0; i < m; ++i) {
		cin >> need[i];
	}

	int l = accumulate(need.begin(), need.end(), 0);

	vector<int> have(m);
	for (int i = 0; i < l; ++i) {
		have[inp[i]]++;
	}

	for (int i = 0; i + l <= n; ++i) {
		if (have == need) {
			cout << "YES\n";
			return;
		}
		if (i + l < n) {
			have[inp[i]]--;
			have[inp[i + l]]++;
		}
	}
	cout << "NO\n";
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