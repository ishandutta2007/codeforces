#ifdef LOCAL
#  define _GLIBCXX_DEBUG
#else
#  define cerr __get_ce
#endif
#include <bits/stdc++.h>
#define ff first
#define ss second
#define szof(x) ((int)x.size())

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
int const INF = (int)1e9 + 1e3;
ll const INFL = (ll)1e18 + 1e6;
mt19937 tw(9450189);
uniform_int_distribution<ll> ll_distr;
ll rnd(ll a, ll b) { return ll_distr(tw) % (b - a + 1) + a; }


void solve() {
	int n, m;
	cin >> n >> m;
	string lets = "ACGT";
	vector<vector<int>> field(n, vector<int>(m));
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		for (int j = 0; j < m; ++j) {
			for (int k = 0; k < 4; ++k) {
				 if (s[j] == lets[k]) {
				 	field[i][j] = k;
				 	break;
				 }
			}
		}
	}

	int ans = -1;
	vector<vector<int>> ans_field;

	for (int mask = 0; mask < 16; ++mask) {
		if (__builtin_popcount(mask) != 2) {
			continue;
		}

		int cur = 0;
		vector<vector<int>> res(n, vector<int>(m));
		for (int i = 0; i < m; ++i) {
			int cnt[2][4] = {{0, 0, 0, 0}, {0, 0, 0, 0}};
			for (int j = 0; j < n; ++j) {
				cnt[j % 2][field[j][i]]++;
			}
			int one = -1, other = -1;
			if (i & 1) {
				mask = ~mask & 15;
			}
			for (int j = 0; j < 4; ++j) {
				if (mask & (1 << j)) {
					if (one == -1) {
						one = j;
					} else {
						other = j;
					}
				}
			}
			if (cnt[0][one] + cnt[1][other] < cnt[1][one] + cnt[0][other]) {
				swap(one, other);
			}

			cur += cnt[0][one] + cnt[1][other];

			for (int j = 0; j < n; ++j) {
				if (j & 1) {
					res[j][i] = other;
				} else {
					res[j][i] = one;
				}
			}

			if (i & 1) {
				mask = ~mask & 15;
			}
		}

		if (ans < cur) {
			ans = cur;
			ans_field = res;
		}
	}

	for (int mask = 0; mask < 16; ++mask) {
		if (__builtin_popcount(mask) != 2) {
			continue;
		}

		int cur = 0;
		vector<vector<int>> res(n, vector<int>(m));
		for (int i = 0; i < n; ++i) {
			int cnt[2][4] = {{0, 0, 0, 0}, {0, 0, 0, 0}};
			for (int j = 0; j < m; ++j) {
				cnt[j % 2][field[i][j]]++;
			}
			int one = -1, other = -1;
			if (i & 1) {
				mask = ~mask & 15;
			}
			for (int j = 0; j < 4; ++j) {
				if (mask & (1 << j)) {
					if (one == -1) {
						one = j;
					} else {
						other = j;
					}
				}
			}
			if (cnt[0][one] + cnt[1][other] < cnt[1][one] + cnt[0][other]) {
				swap(one, other);
			}

			cur += cnt[0][one] + cnt[1][other];

			for (int j = 0; j < m; ++j) {
				if (j & 1) {
					res[i][j] = other;
				} else {
					res[i][j] = one;
				}
			}

			if (i & 1) {
				mask = ~mask & 15;
			}
		}

		if (ans < cur) {
			ans = cur;
			ans_field = res;
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cout << lets[ans_field[i][j]];
		}
		cout << "\n";
	}
}


int main() {
#ifdef LOCAL
	auto start_time = clock();
	cerr << setprecision(3) << fixed;
#endif
	cout << setprecision(15) << fixed;
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int test_count = 1;
	// cin >> test_count;
	for (int test = 1; test <= test_count; ++test) {
		solve();
	}
	
#ifdef LOCAL
	auto end_time = clock();
	cerr << "Execution time: " << (end_time - start_time) * (int)1e3 / CLOCKS_PER_SEC << " ms\n";
#endif
}