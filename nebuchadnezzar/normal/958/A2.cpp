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

const int P = 239, MOD = 1e9 + 7;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<vector<char>> field1(n, vector<char>(m));
	vector<vector<char>> field2(m, vector<char>(n));
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		for (int j = 0; j < m; ++j) {
			field1[i][j] = s[j];
		}
	}

	for (int i = 0; i < m; ++i) {
		string s;
		cin >> s;
		for (int j = 0; j < n; ++j) {
			field2[i][j] = s[j];
		}
	}

	map<int, int> have;
	for (int i = 0; i + m <= n; ++i) {
		ll h = 0;
		for (int x = 0; x < m; ++x) {
			for (int y = 0; y < m; ++y) {
				h = (h * P + field1[i + x][y]) % MOD;
			}
		}
		have[h] = i;
	}

	for (int i = 0; i + m <= n; ++i) {
		ll h = 0;
		for (int x = 0; x < m; ++x) {
			for (int y = 0; y < m; ++y) {
				h = (h * P + field2[x][i + y]) % MOD;
			}
		}
		if (have.count(h)) {
			cout << have[h] + 1 << " " << i + 1 << "\n";
			return;
		}
	}
	assert(false);
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