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

int field[4][55];

void solve() {
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < n; ++j) {
			int num;
			cin >> num;
			--num;
			field[i][j] = num;
		}
	}

	vector<tuple<int, int, int>> ans;
	for (int i = 0; i < n; ++i) {
		if (field[1][i] != -1 && field[1][i] == field[0][i]) {
			ans.push_back({field[0][i], 0, i});
			field[0][i] = field[1][i] = -1;
			--k;
		}
		if (field[2][i] != -1 && field[2][i] == field[3][i]) {
			ans.push_back({field[2][i], 3, i});
			field[2][i] = field[3][i] = -1;
			--k;
		}
	}
	if (k == n * 2) {
		cout << "-1\n";
		return;
	}

	while (k) {
		//cerr << k << endl;
		vector<bool> used(100);
		for (int i = 1; i < 3; ++i) {
			for (int j = 0; j < n; ++j) {
				if (field[i][j] != -1 && !used[field[i][j]]) {
					vector<pii> st;
					st.push_back({i, j});
					while (szof(st)) {
						int curx, cury;
						tie(curx, cury) = st.back();
						int nextx = curx, nexty = cury;
						if (curx == 1) {
							++nexty;
							if (nexty == n) {
								nextx = 2, nexty = n - 1;
							}
						} else {
							--nexty;
							if (nexty == -1) {
								nextx = 1, nexty = 0;
							}
						}

						if (field[nextx][nexty] == -1) {
							ans.push_back({field[curx][cury], nextx, nexty});
							used[field[curx][cury]] = true;
							swap(field[nextx][nexty], field[curx][cury]);
							st.pop_back();
						} else {
							st.push_back({nextx, nexty});
						}
					}
				}
			}
		}
		
		for (int i = 0; i < n; ++i) {
			if (field[1][i] != -1 && field[1][i] == field[0][i]) {
				ans.push_back({field[0][i], 0, i});
				field[0][i] = field[1][i] = -1;
				--k;
			}
			if (field[2][i] != -1 && field[2][i] == field[3][i]) {
				ans.push_back({field[2][i], 3, i});
				field[2][i] = field[3][i] = -1;
				--k;
			}
		}
	}

	cout << szof(ans) << "\n";
	for (auto p : ans) {
		cout << get<0>(p) + 1 << " " << get<1>(p) + 1 << " " << get<2>(p) + 1 << "\n";
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