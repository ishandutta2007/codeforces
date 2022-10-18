#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <cstdlib>
#include <memory>
#include <queue>
#include <cassert>
#include <cmath>
#include <ctime>
#include <complex>
#include <bitset>
#include <fstream>
#include <unordered_map>
#include <unordered_set>
#include <numeric>

using namespace std;

#define ws ws_____________________
#define y1 y1_____________________
#define y0 y0_____________________
#define left left_________________
#define right right_______________
#define next next_________________
#define prev prev_________________
#define hash hash_________________

#define pb push_back
#define fst first
#define snd second
#define mp make_pair 
#define sz(C) ((int) (C).size())
#define forn(i, n) for (int i = 0; i < (int) n; ++i)
#define ford(i, n) for (int i = ((int) n) - 1; i >= 0; --i)
#define all(C) begin(C), end(C)

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vector <int> > vvi;
typedef vector<pii> vii;
typedef long double ld;
typedef complex<double> cd;
typedef vector<cd> vcd;

#define FILE_NAME "a"


const int MAXN = 1e5 + 10;
const int MOD = 1e9 + 7;

void add(int& x, int y) {
	((x += y) >= MOD) && (x -= MOD);
}

int mul(int x, int y) {
	return x * 1ll * y % MOD;
}

int mpow(int a, int p) {
	int res = 1;
	for (; p > 0; a = mul(a, a), p >>= 1) {
		if  (p & 1) {
			res = mul(res, a);
		}
	}
	return res;
}

int a[MAXN][2];
vi g[MAXN];
int n, m;

bool read() {
	if  (scanf("%d%d", &n, &m) < 2) {
		return false;
	}
	forn(i, n) {
		int k;
		scanf("%d", &k);
		forn(j, k) {
			scanf("%d", &a[i][j]);
		}
		if  (k == 1) {
			a[i][1] = a[i][0];
		}
	}
	forn(i, n) {
		g[i].clear();
	}
	return true;
}

vi where[MAXN];
bool was[MAXN];

void dfs(int v, vi& vs) {
	assert(!was[v]);
	was[v] = true;
	vs.pb(v);
	for (int to : g[v]) {
		if  (!was[to]) {
			dfs(to, vs);
		}
	}
}

vi get_comp(int v) {
	vi vs;
	dfs(v, vs);
	return vs;
}

int val[MAXN];

bool put(int pos, int nval) {
	pos = abs(pos) - 1;
	if (val[pos] != -1 && val[pos] != nval) {
		return false;
	}
	val[pos] = nval;
	return true;
}

void unput(int pos) {
	pos = abs(pos) - 1;
	val[pos] = -1;
}

int dp[MAXN][2][2][2];

int get_pos_vector(const vi& v, int x) {
	forn(i, sz(v)) {
		if  (v[i] == x) {
			return i;
		}
	}
	assert(false);
	return -1;
}

void rec(const vi& vars, vi& val_vars, int pos, const vi& vs, vi& dp) {
	if  (pos == sz(vars)) {
		int f = 0;
		for (int v : vs) {
			int x1 = get_pos_vector(vars, abs(a[v][0]) - 1);
			int x2 = get_pos_vector(vars, abs(a[v][1]) - 1);
			int cur = (val_vars[x1] ^ (a[v][0] < 0)) || (val_vars[x2] ^ (a[v][1] < 0));
			f ^= cur;
		}
		dp[f] += 1;
		return;
	}
	forn(C, 2) {
		val_vars[pos] = C;
		rec(vars, val_vars, pos + 1, vs, dp);
	}
}

vi brut_comp(const vi& vs) {
	vi vars;
	for (int v : vs) {
		forn(i, 2) {
			vars.pb(abs(a[v][i]) - 1);
		}
	} 
	sort(all(vars));
	vars.resize(unique(all(vars)) - vars.begin());

	vi dp(2, 0);
	vi val_vars(sz(vars));
	rec(vars, val_vars, 0, vs, dp);
	return dp;
}

vi solve_comp(int v0) {
	vi vs = get_comp(v0);

	if  (sz(vs) == 1) {
		if  (abs(a[v0][0]) == abs(a[v0][1])) {
			return a[v0][0] == a[v0][1] ? vi{1, 1} : vi{0, 2};
		}
		return vi{1, 3};
	}

	int start = -1;
	for (int v : vs) {
		if  (sz(g[v]) == 1) {
			start = v;
			break;
		}
	}

	if  (start != -1) {
		vi nvs;
		while (1) {
			int nxt = -1;
			for (int to : g[start]) {
				if  (nvs.empty() || to != nvs.back()) {
					nxt = to;
					break;
				}
			}
			nvs.pb(start);
			if  (nxt == -1) {
				break;
			}
			start = nxt;
		}
		vs = nvs;
	}

	// printf("comp:\n");
	// for (int v : vs) {
	// 	printf("%d ", v);
	// }
	// puts("");

	vi res(2, 0);
	forn(C, 2) {
		int var = -1;
		for (int to : g[vs[0]]) {
			if  (to == vs.back()) {
				forn(z1, 2) forn(z2, 2) {
					if  (abs(a[vs[0]][z1]) == abs(a[vs.back()][z2])) {
						var = abs(a[vs[0]][z1]) - 1;
					}
				}
			}
		}

		if  (var == -1) {
			var = abs(a[vs[0]][0]) - 1;
		}

		assert(put(var + 1, C));

		forn(i, sz(vs) + 1) {
			memset (dp[i], 0, sizeof dp[i]);
		}
		dp[0][0][0][0] = 1;
		forn(i, sz(vs)) forn(c0, 2) forn(c1, 2) forn(func, 2) {
			int cur_dp = dp[i][c0][c1][func];
			if  (!cur_dp) {
				continue;
			}

			int Old0 = -1;
			int Old1 = -1;
			if  (i > 0) {
				int pv = vs[i - 1];
				bool ok = true;
				Old0 = val[abs(a[pv][0]) - 1];
				Old1 = val[abs(a[pv][1]) - 1];
				ok &= put(a[pv][0], c0);
				ok &= put(a[pv][1], c1);
				if  (!ok) {
					val[abs(a[pv][0]) - 1] = Old0;
					val[abs(a[pv][1]) - 1] = Old1;
					continue;
				}
			}

			int v = vs[i];

			forn(cc0, 2) forn(cc1, 2) {
				int old0 = val[abs(a[v][0]) - 1];
				int old1 = val[abs(a[v][1]) - 1];
			
				bool ok = true;
				ok &= put(a[v][0], cc0);
				ok &= put(a[v][1], cc1);
				if  (!ok) {
					val[abs(a[v][0]) - 1] = old0;
					val[abs(a[v][1]) - 1] = old1;
					continue;
				}

				int nfunc = func ^ ((cc0 ^ (a[v][0] < 0)) || (cc1 ^ (a[v][1] < 0)));
				add(dp[i + 1][cc0][cc1][nfunc], cur_dp);
				val[abs(a[v][0]) - 1] = old0;
				val[abs(a[v][1]) - 1] = old1;
			}

			if  (i > 0) {
				int pv = vs[i - 1];
				val[abs(a[pv][0]) - 1] = Old0;
				val[abs(a[pv][1]) - 1] = Old1;
			}
		}

		forn(c0, 2) forn(c1, 2) forn(func, 2) {
			add(res[func], dp[sz(vs)][c0][c1][func]);
		}

		unput(var + 1);
	}

	// forn(f, 2) {
	// 	printf("%d ", res[f]);
	// }
	// puts("");

	// vi br = brut_comp(vs);
	// puts("Brut:");
	// forn(f, 2) {
	// 	printf("%d ", br[f]);
	// }
	// puts("");

	return res;
}

int solve() {
	forn(i, m) {
		where[i].clear();
	}
	forn(i, n) {
		forn(j, 2) {
			where[abs(a[i][j]) - 1].pb(i);
		}
	}

	int cnt_free = 0;
	forn(i, m) {
		sort(all(where[i]));
		where[i].resize(unique(all(where[i])) - where[i].begin());
		assert(sz(where[i]) <= 2);
		// printf("where[%d]:\n", i);
		// for (int x : where[i]) {
		// 	printf("%d ", x);
		// }
		// puts("");
		if  (where[i].empty()) {
			++cnt_free;
			continue;
		}
		if  (sz(where[i]) == 2) {
			g[where[i][0]].pb(where[i][1]);
			g[where[i][1]].pb(where[i][0]);
		}
	}

	memset (val, -1, sizeof val);
	vi dp(2, 0);
	dp[0] = 1;
	memset (was, 0, sizeof was);
	forn(i, n) {
		if  (was[i]) {
			continue;
		}
		vi d = solve_comp(i);
		vi ndp(2, 0);
		forn(was, 2) forn(nw, 2) {
			add(ndp[was ^ nw], mul(dp[was], d[nw]));
		}
		dp.swap(ndp);
	}

	// printf("cnt_free = %d\n", cnt_free);
	return mul(dp[1], mpow(2, cnt_free));
}

int main() {
#ifdef LOCAL
	freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif

	while (read()) {
		printf("%d\n", solve());
	}

#ifdef LOCAL
	cerr.precision(5);
	cerr << "Time: " << fixed << (double) clock() / CLOCKS_PER_SEC << endl;
#endif
	return 0;
}