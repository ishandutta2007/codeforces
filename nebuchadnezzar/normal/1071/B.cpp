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
	int n, k;
	cin >> n >> k;
	vector<vector<char>> field(n, vector<char>(n));
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		for (int j = 0; j < n; ++j) {
			field[i][j] = s[j];
		}
	}

	vector<pair<pii, int>> vars;
	string ans = "";
	if (k && field[0][0] != 'a') {
		vars.push_back({{0, 0}, k - 1});
		ans += 'a';
	} else {
		vars.push_back({{0, 0}, k});
		ans += field[0][0];
	}

	vector<pii> shifts = {{1, 0}, {0, 1}};

	while (vars[0].ff.ff + vars[0].ff.ss < (n - 1) * 2) {
		vector<vector<pair<pii, int>>> next(26);
		for (auto p : vars) {
			for (pii d : shifts) {
				int nx = p.ff.ff + d.ff;
				int ny = p.ff.ss + d.ss;
				if (nx < n && ny < n) {
					char c = field[nx][ny];
					int k = p.ss;
					if (k && c > 'a') {
						c = 'a';
						--k;
					}
					next[c - 'a'].push_back({{nx, ny}, k});
				}
			}
		}

		for (int i = 0; i < 26; ++i) {
			if (szof(next[i])) {
				sort(next[i].begin(), next[i].end());
				ans += 'a' + i;
				vars.clear();
				// cerr << szof(next[i]) << endl;
				for (int j = 0; j < szof(next[i]); ++j) {
					if (j < szof(next[i]) - 1 && next[i][j].ff == next[i][j + 1].ff) {
						vars.push_back({next[i][j].ff, max(next[i][j].ss, next[i][j + 1].ss)});
						++j;
					} else {
						vars.push_back(next[i][j]);
					}
				}
				break;
			}
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