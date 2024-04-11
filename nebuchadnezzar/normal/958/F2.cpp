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

	vector<int> have(m);
	int cnt = 0;
	int above = 0;
	for (int i = 0; i < m; ++i) {
		if (have[i] == need[i]) {
			++cnt;
		}
	}
	int ans = INF;
	int c = 0;
	for (int i = 0; i < n; ++i) {
		while (c < n && cnt < m) {
			have[inp[c]]++;
			if (have[inp[c]] == need[inp[c]]) {
				++cnt;
			} else if (have[inp[c]] > need[inp[c]]) {
				++above;
			}
			++c;
		}
		if (cnt < m) {
			break;
		}
		ans = min(ans, above);

		if (have[inp[i]] == need[inp[i]]) {
			--cnt;
		} else if (have[inp[i]] > need[inp[i]]) {
			--above;
		}

		have[inp[i]]--;
	}
	if (ans == INF) {
		ans = -1;
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