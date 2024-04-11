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
const int M = 41;

bool bad[M][M][M][M];
vii who_bad[M][M];
int lg2[MAXN];

void precalc() {
	forn(i, MAXN) {
		int b = 0;
		while ((1 << b) <= i) ++b;
		lg2[i] = b - 1;
	}

	for (int m1 = 1; m1 < M; ++m1) {
		forn(r1, m1) {
			for (int m2 = 1; m2 < M; ++m2) {
				forn(r2, m2) {
					bad[m1][r1][m2][r2] = true;
					int x = r1;
					forn(it, m2) {
						x += m1;
						if  (x % m2 == r2) {
							assert(x % m1 == r1);
							bad[m1][r1][m2][r2] = false;
							break;
						}
					}
					if  (bad[m1][r1][m2][r2]) {
						who_bad[m1][r1].pb(mp(m2, r2));
					}
				}
			}
		}
	}
}

int n, m;
vi a[MAXN];
vii poses[MAXN];

bool read() {
	if  (scanf("%d%d", &n, &m) < 2) {
		return false;
	}
	forn(i, n) {
		poses[i].clear();
	}
	forn(i, n) {
		int k;
		scanf("%d", &k);
		a[i].resize(k);
		forn(j, k) {
			scanf("%d", &a[i][j]);
			--a[i][j];
			poses[a[i][j]].pb(mp(i, j));
		}
	}
	return true;
}

int last[M][M];
int last_was[M][M];

pii mn[MAXN][21];

void precalc_min(const vi& x) {
	const int B = lg2[sz(x)];
	forn(i, sz(x)) {
		mn[i][0] = mp(x[i], i);
	}
	for (int b = 1; b <= B; ++b) {
		forn(i, sz(x)) {
			if  (i + (1 << b) - 1 >= sz(x)) {
				break;
			}
			mn[i][b] = min(mn[i][b - 1], mn[i + (1 << (b - 1))][b - 1]);
		}
	}
}

pii get_min(int l, int r) {
	int b = lg2[r - l + 1];
	return min(mn[l][b], mn[r - (1 << b) + 1][b]);
}

int rec(int l, int r) {
	if  (l > r) {
		return 0;
	}
	pii MN = get_min(l, r);
	if  (MN.fst >= r) {
		return r - l + 1;
	}
	int ans = MN.fst - l + 1;
	int pos = MN.snd;
	return max(ans, max(rec(l, pos - 1), rec(pos + 1, r)));
}

int solve(vii vals) {
	static int iter = 0;
	++iter;

	if  (sz(vals) <= 1) {
		return sz(vals);
	}

	vi nxt(sz(vals));

	ford(i, sz(vals)) {
		nxt[i] = sz(vals) - 1;
		int r1 = vals[i].fst;
		int m1 = vals[i].snd;
		for (const auto& cur : who_bad[m1][r1]) {
			int m2, r2;
			tie(m2, r2) = cur;
			if  (last_was[m2][r2] == iter) {
				nxt[i] = min(nxt[i], last[m2][r2] - 1);
			}
		}

		last_was[m1][r1] = iter;
		last[m1][r1] = i;
	}

	// printf("vals:\n");
	// for (auto x : vals) {
	// 	printf("%d %d\n", x.fst, x.snd);
	// }
	// puts("");

	// printf("nxt:\n");
	// for (auto x : nxt) {
	// 	printf("%d ", x);
	// }
	// puts("");

	precalc_min(nxt);
	return rec(0, sz(nxt) - 1);
}

int solve(int x) {
	vii& p = poses[x];
	sort(all(p));
	int ans = 0;
	for (int i = 0, j; i < sz(p); i = j) {
		j = i + 1;
		while (j < sz(p) && p[j].fst == p[j - 1].fst + 1) {
			++j;
		}

		// [i, j)
		vii vals;
		for (int z = i; z < j; ++z) {
			vals.pb(mp(p[z].snd, sz(a[p[z].fst])));
		}
		ans = max(ans, solve(vals));
	}
	return ans;
}

void solve() {
	forn(num, m) {
		memset (last_was, -1, sizeof last_was);
		printf("%d\n", solve(num));
	}
}

int main() {
#ifdef LOCAL
	freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif

	precalc();

	while (read()) {
		solve();
	}

#ifdef LOCAL
	cerr.precision(5);
	cerr << "Time: " << fixed << (double) clock() / CLOCKS_PER_SEC << endl;
#endif
	return 0;
}