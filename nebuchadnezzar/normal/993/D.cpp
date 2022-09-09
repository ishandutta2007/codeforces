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
	vector<pii> tasks;
	for (int i = 0; i < n; ++i) {
		int num;
		cin >> num;
		tasks.push_back({num, -1});
	}
	for (int i = 0; i < n; ++i) {
		cin >> tasks[i].ss;
	}

	sort(tasks.begin(), tasks.end());

	vector<vector<vector<ll>>> d(2, vector<vector<ll>>(n + 5, vector<ll>(100 * n + 5, INFL)));
	d[0][0][0] = 0;

	for (int i = n - 1; i >= 0; --i) {
		int next = i;
		while (next >= 0 && tasks[i].ff == tasks[next].ff) {
			--next;
		}
		//cerr << i << " " << next << endl;

		for (int j = 0; j <= n; ++j) {
			fill(d[1][j].begin(), d[1][j].end(), INFL);
		}

		for (int q = 0; q <= n; ++q) {
			for (int j = 0; j < 100 * n + 5; ++j) {
				int bal = q, p = j;
				if (d[0][q][j] == INFL) {
					continue;
				}
				ll take = 0;
				for (int k = i; k > next; --k) {
					if (q >= k - next) {
						d[1][bal - (k - next)][p] = min(d[1][bal - (k - next)][p], d[0][q][j] + take);
					}
					bal++;
					p += tasks[k].ss;
					take += tasks[k].ff;
				}
				d[1][bal][p] = min(d[1][bal][p], d[0][q][j] + take);
			}
		}

		swap(d[0], d[1]);
		i = next;
		++i;
	}

	ll ans = INFL;

	for (int i = 0; i < szof(d[0]); ++i) {
		for (int j = 1; j < szof(d[0][i]); ++j) {
			if ((d[0][i][j] * 1000 + j - 1) / j == 8750) {
				cerr << i << " " << j << " " << d[0][i][j] << endl;
			}
			ans = min(ans, (d[0][i][j] * 1000 + j - 1) / j);
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