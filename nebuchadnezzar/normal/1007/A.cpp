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
	sort(inp.begin(), inp.end());

	int cnt = 0, cur_cnt = 0;
	int ans = 0;
	for (int i = n - 1; i >= 0; --i) {
		if (i < n - 1 && inp[i] != inp[i + 1]) {
			cnt += cur_cnt;
			cur_cnt = 0;
		}
		++cur_cnt;
		if (cnt) {
			++ans;
			--cnt;
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