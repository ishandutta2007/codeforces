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

const int MAXN = 55;
int field[MAXN][MAXN];

void solve() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		for (int j = 0; j < m; ++j) {
			field[i][j] = s[j] == '#';
		}
	}

	vector<bool> usedh(n), usedv(m);
	for (int i = 0; i < n; ++i) {
		if (!usedh[i]) {
			vector<int> vers;
			for (int j = 0; j < m; ++j) {
				if (field[i][j]) {
					vers.push_back(j);
					if (usedv[j]) {
						cout << "No\n";
						return;
					}
				}
			}
			if (szof(vers)) {
				vector<int> hors;
				for (int k = 0; k < n; ++k) {
					if (field[k][vers[0]]) {
						if (usedh[k]) {
							cout << "No\n";
							return;
						}
						hors.push_back(k);
					}
				}
				for (int j : vers) {
					vector<int> curh;
					for (int k = 0; k < n; ++k) {
						if (field[k][j]) {
							curh.push_back(k);
						}
					}
					if (curh != hors) {
						cout << "No\n";
						return;
					}
				}

				for (int k : hors) {
					vector<int> curv;
					for (int j = 0; j < m; ++j) {
						if (field[k][j]) {
							curv.push_back(j);
						}
					}
					if (curv != vers) {
						cout << "No\n";
						return;
					}
				}

				for (int j : vers) {
					usedv[j] = true;
				}
				for (int k : hors) {
					usedh[k] = true;
				}
			}
		}
	}
	cout << "Yes\n";
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