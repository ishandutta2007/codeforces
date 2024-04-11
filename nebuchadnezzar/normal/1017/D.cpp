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
	int n, m, q;
	cin >> n >> m >> q;
	vector<int> cost;
	for (int i = 0; i < n; ++i) {
		int num;
		cin >> num;
		cost.push_back(num);
	}
	vector<int> amount(1 << n);
	for (int i = 0; i < m; ++i) {
		string s;
		cin >> s;
		int num = 0;
		for (char c : s) {
			num = num * 2 + c - '0';
		}
		amount[num]++;
	}

	vector<int> mask_cost(1 << n);
	for (int i = 1; i < 1 << n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (i & (1 << j)) {
				mask_cost[i] = mask_cost[i ^ (1 << j)] + cost[n - j - 1];
				break;
			}
		}
	}

	const int MAXCOST = 105;
	vector<vector<int>> ans(1 << n, vector<int>(MAXCOST));
	int mask = (1 << n) - 1;

	for (int i = 0; i < 1 << n; ++i) {
		for (int j = 0; j < 1 << n; ++j) {
			int tmp = (~(i ^ j)) & mask;
			//cerr << i << " " << j << " " << mask_cost[tmp] << " " << amount[j] << endl;
			ans[i][min(MAXCOST - 1, mask_cost[tmp])] += amount[j];
		}

		for (int j = 0; j < MAXCOST - 1; ++j) {
			ans[i][j + 1] += ans[i][j];
		}
	}

	for (int i = 0; i < q; ++i) {
		string s;
		cin >> s;
		int co;
		cin >> co;
		int num = 0;
		for (char c : s) {
			num = num * 2 + c - '0';
		}

		cout << ans[num][co] << "\n";
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