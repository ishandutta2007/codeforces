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
	vector<vector<int>> part(m);
	for (int i = 0; i < n; ++i) {
		int p, c;
		cin >> p >> c;
		--p;
		part[p].push_back(c);
	}

	for (int i = 0; i < m; ++i) {
		sort(part[i].begin(), part[i].end());
	}

	ll ans = INFL;
	for (int i = szof(part[0]); i <= n; ++i) {
		ll cur = 0;
		int have = szof(part[0]);
		vector<int> rest;
		for (int j = 1; j < m; ++j) {
			int k = 0;
			for (; k < szof(part[j]) - max(i - 1, 0); ++k) {
				cur += part[j][k];
				++have;
			}
			for (; k < szof(part[j]); ++k) {
				rest.push_back(part[j][k]);
			}
		}
		if (have < i) {
			nth_element(rest.begin(), rest.begin() + (i - have - 1), rest.end());
			for (int j = 0; j < i - have; ++j) {
				cur += rest[j];
			}
		}
		ans = min(ans, cur);
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