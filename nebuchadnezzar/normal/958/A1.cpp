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
	vector<vector<char>> field(n, vector<char>(n));
	vector<vector<char>> res(n, vector<char>(n));
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		for (int j = 0; j < n; ++j) {
			field[i][j] = s[j];
		}
	}

	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		for (int j = 0; j < n; ++j) {
			res[i][j] = s[j];
		}
	}

	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < 4; ++j) {
			if (res == field) {
				cout << "Yes\n";
				return;
			}

			vector<vector<char>> tmp(n, vector<char>(n));
			for (int x = 0; x < n; ++x) {
				for (int y = 0; y < n; ++y) {
					tmp[y][n - 1 - x] = res[x][y];
				}
			}

			res = tmp;
		}

		for (int x = 0; x < n - 1 - x; ++x) {
			for (int y = 0; y < n; ++y) {
				swap(res[x][y], res[n - 1 - x][y]);
			}
		}
	}
	cout << "No\n";
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