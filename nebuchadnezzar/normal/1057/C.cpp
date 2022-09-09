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
	int n, s, k;
	cin >> n >> s >> k;
	--s;
	vector<int> inp;
	for (int i = 0; i < n; ++i) {
		int num;
		cin >> num;
		inp.push_back(num);
	}

	string col;
	cin >> col;

	vector<vector<int>> d(n, vector<int>(k + 1, INF));
	for (int i = 0; i < n; ++i) {
		d[i][min(k, inp[i])] = abs(i - s);
	}

	for (int i = 0; i < k; ++i) {
		for (int j = 0; j < n; ++j) {
			for (int j2 = 0; j2 < n; ++j2) {
				if (inp[j2] > inp[j] && col[j2] != col[j]) {
					d[j2][min(k, i + inp[j2])] = min(d[j2][min(k, i + inp[j2])], d[j][i] + abs(j2 - j));
				}
			}
		}
	}

	int ans = INF;
	for (int i = 0; i < n; ++i) {
		ans = min(ans, d[i][k]);
	}

	if (ans == INF) {
		cout << "-1\n";
	} else {
		cout << ans << "\n";
	}
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