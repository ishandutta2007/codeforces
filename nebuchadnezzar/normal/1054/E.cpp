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

int n, m;

vector<pair<pii, pii>> find_path(vector<vector<string>> field2) {
	vector<pair<pii, pii>> ret;
	vector<vector<deque<char>>> field(n, vector<deque<char>>(m));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			for (char c : field2[i][j]) {
				field[i][j].push_back(c);
			}
		}
	}

	function<void(int x1, int y1, int x2, int y2)> move = [&](int x1, int y1, int x2, int y2) {
		// cerr << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
		assert(x1 != x2 || y1 != y2);
		assert(x1 == x2 || y1 == y2);
		ret.push_back({{x1, y1}, {x2, y2}});
		assert(szof(field[x1][y1]));
		field[x2][y2].push_front(field[x1][y1].back());
		field[x1][y1].pop_back();
	};

	for (int i = 0; i < m - 1; ++i) {
		while (szof(field[0][i])) {
			move(0, i, 0, m - 1);
		}
	}

	for (int i = 1; i < n; ++i) {
		while (szof(field[i][m - 1])) {
			move(i, m - 1, 0, m - 1);
		}
	}

	while (szof(field[0][m - 1])) {
		if (field[0][m - 1].back() == '0') {
			move(0, m - 1, 0, 0);
		} else {
			move(0, m - 1, n - 1, m - 1);
		}
	}

	for (int i = 1; i < n; ++i) {
		for (int j = 0; j < m - 1; ++j) {
			while (szof(field[i][j])) {
				if (field[i][j].back() == '0') {
					move(i, j, 0, j);
					if (j != 0) {
						move(0, j, 0, 0);
					}
				} else {
					move(i, j, i, m - 1);
					if (i != n - 1) {
						move(i, m - 1, n - 1, m - 1);
					}
				}
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (i == 0 && j == 0) {
				for (char c : field[i][j]) {
					assert(c == '0');
				}
			} else if (i == n - 1 && j == m - 1) {
				for (char c : field[i][j]) {
					assert(c == '1');
				}
			} else {
				assert(!szof(field[i][j]));
			}
		}
	}

	return ret;
}

void solve() {
	cin >> n >> m;
	vector<pair<pii, pii>> ans;
	for (int i = 0; i < 2; ++i) {
		vector<vector<string>> field(n, vector<string>(m));
		for (int j = 0; j < n; ++j) {
			for (int k = 0; k < m; ++k) {
				cin >> field[j][k];
				if (i) {
					reverse(field[j][k].begin(), field[j][k].end());
				}
			}
		}
		auto tmp = find_path(field);
		if (i == 0) {
			ans = tmp;
		} else {
			reverse(tmp.begin(), tmp.end());
			for (auto p : tmp) {
				ans.push_back({p.ss, p.ff});
			}
		}
	}

	cout << szof(ans) << "\n";
	for (auto p : ans) {
		cout << p.ff.ff + 1 << " " << p.ff.ss + 1 << " " << p.ss.ff + 1 << " " << p.ss.ss + 1 << "\n";
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