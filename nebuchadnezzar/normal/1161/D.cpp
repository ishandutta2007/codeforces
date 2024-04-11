// Created by Nikolay Budin

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
typedef unsigned long long ull;
int const INF = (int)1e9 + 1e3;
ll const INFL = (ll)1e18 + 1e6;
#ifdef LOCAL
	mt19937 tw(9450189);
#else
	mt19937 tw(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif
uniform_int_distribution<ll> ll_distr;
ll rnd(ll a, ll b) { return ll_distr(tw) % (b - a + 1) + a; }

const int MAXL = 1005;

const int MOD = 998244353;

void add(int& a, int b) {
	a += b;
	if (a >= MOD) {
		a -= MOD;
	}
}

int mult(int a, int b) {
	return (ll) a * b % MOD;
}

int mpow(int a, int b) {
	int ret = 1;
	while (b) {
		if (b & 1) {
			ret = mult(ret, a);
		}
		a = mult(a, a);
		b >>= 1;
	}
	return ret;
}

void solve() {
	string s;
	cin >> s;
	vector<int> vars(szof(s), -1);
	int cnt = 0;
	for (int i = 0; i < szof(s); ++i) {
		if (s[i] == '?') {
			vars[i] = cnt++;
		}
	}

	vector<bitset<MAXL>> vala(szof(s));
	vector<bitset<MAXL>> valb(szof(s));
	vector<vector<bool>> used(2, vector<bool>(szof(s)));

	bitset<MAXL> zero;

	int ans = 0;

	for (int i = 1; i < szof(s); ++i) {
		for (int j = 0; j < 2; ++j) {
			fill(used[j].begin(), used[j].end(), 0);
		}
		queue<pii> qu;
		for (int j = 0; j + i < szof(s); ++j) {
			vala[j] = zero;
			if (s[j] == '1') {
				vala[j][MAXL - 1] = 1;
			} else if (s[j] == '?') {
				vala[j][vars[j]] = 1;
			}
			qu.push({0, j});
			used[0][j] = true;
		}

		while (szof(qu)) {
			pii p = qu.front();
			qu.pop();

			if (p.ff == 0) {
				if (p.ss >= szof(s) - i && !used[1][p.ss]) {
					used[1][p.ss] = true;
					qu.push({1, p.ss});
					valb[p.ss] = vala[p.ss];
					if (s[p.ss] == '1') {
						valb[p.ss][MAXL - 1] = valb[p.ss][MAXL - 1] ^ 1;
					} else if (s[p.ss] == '?') {
						valb[p.ss][vars[p.ss]] = valb[p.ss][vars[p.ss]] ^ 1;
					}
				}
				if (!used[0][szof(s) - 1 - p.ss]) {
					used[0][szof(s) - 1 - p.ss] = true;
					qu.push({0, szof(s) - 1 - p.ss});
					vala[szof(s) - 1 - p.ss] = vala[p.ss];
				}
			} else {
				if (!used[0][p.ss]) {
					used[0][p.ss] = true;
					qu.push({0, p.ss});
					vala[p.ss] = valb[p.ss];
					if (s[p.ss] == '1') {
						vala[p.ss][MAXL - 1] = vala[p.ss][MAXL - 1] ^ 1;
					} else if (s[p.ss] == '?') {
						vala[p.ss][vars[p.ss]] = vala[p.ss][vars[p.ss]] ^ 1;
					}
				}
				if (!used[1][szof(s) - 1 - p.ss + szof(s) - i]) {
					used[1][szof(s) - 1 - p.ss + szof(s) - i] = true;
					qu.push({1, szof(s) - 1 - p.ss + szof(s) - i});
					valb[szof(s) - 1 - p.ss + szof(s) - i] = valb[p.ss];
				}
			}
		}

		// cerr << i << endl;
		// for (int j = 0; j < szof(s); ++j) {
		// 	for (int k = 0; k < cnt; ++k) {
		// 		cerr << vala[j][k];
		// 	}
		// 	cerr << vala[j][MAXL - 1] << endl;
		// }

		// cerr << endl;
		// for (int j = szof(s) - i; j < szof(s); ++j) {
		// 	for (int k = 0; k < cnt; ++k) {
		// 		cerr << valb[j][k];
		// 	}
		// 	cerr << valb[j][MAXL - 1] << endl;
		// }

		vector<bitset<MAXL>> matr;
		for (int j = 0; j < szof(s) - 1 - j; ++j) {
			matr.push_back(vala[j] ^ vala[szof(s) - 1 - j]);
		}

		for (int j = 0; szof(s) - i + j < szof(s) - 1 - j; ++j) {
			matr.push_back(valb[szof(s) - i + j] ^ valb[szof(s) - 1 - j]);
		}

		matr.push_back(valb[szof(s) - i]);
		matr.back()[MAXL - 1] = matr.back()[MAXL - 1] ^ 1;

		int cur = 0;
		int var = 0;
		int free_vars = 0;
		for (var = 0; var < cnt && cur < szof(matr); ++var) {
			for (int k = cur; k < szof(matr); ++k) {
				if (matr[k][var]) {
					swap(matr[k], matr[cur]);
					break;
				}
			}
			if (!matr[cur][var]) {
				++free_vars;
				continue;
			}

			for (int k = 0; k < szof(matr); ++k) {
				if (k != cur && matr[k][var]) {
					matr[k] ^= matr[cur];
				}
			}

			++cur;
		}
		free_vars += cnt - var;

		bool bad = false;
		for (int j = cur; j < szof(matr); ++j) {
			if (matr[j][MAXL - 1]) {
				bad = true;
				break;
			}
		}

		// cerr << cur << " " << free_vars << endl;

		if (!bad) {
			// cerr << "here" << endl;
			add(ans, mpow(2, free_vars));
		}
	}

	cout << ans << "\n";
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