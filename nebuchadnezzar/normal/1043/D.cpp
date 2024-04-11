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
	int n, m;
	cin >> n >> m;
	if (m == 1) {
		cout << (ll) n * (n + 1) / 2 << "\n";
		return;
	}
	vector<vector<int>> inp(m);
	vector<vector<int>> where(n);
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			int num;
			cin >> num;
			--num;
			inp[i].push_back(num);
			where[num].push_back(j);
		}
	}

	vector<int> d(n, -1);

	function<int(int)> calc = [&](int num) {
		if (d[num] != -1) {
			return d[num];
		}
		int vars = -1;
		for (int i = 0; i < m; ++i) {
			int pos = where[num][i];
			if (pos == n - 1) {
				return d[num] = 1;
			}
			if (vars >= 0) {
				if (vars != inp[i][pos + 1]) {
					return d[num] = 1;
				}
			} else {
				vars = inp[i][pos + 1];
			}
		}
		return d[num] = calc(vars) + 1;
	};

	ll ans = 0;
	for (int i = 0; i < n; ++i) {
		ans += calc(i);
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