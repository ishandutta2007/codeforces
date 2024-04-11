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
#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define ford(i, n) for (int i = int(n) - 1; i >= 0; --i)
#define all(C) begin(C), end(C)

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef long double ld;
typedef complex<double> cd;

#define FILE_NAME "a"

const int MAXN = 5e3 + 10;

int n;
int a, b, c, d;
vi g[MAXN];

bool read() {
	if  (scanf("%d", &n) < 1) {
		return 0;
	}
	forn(i, n) {
		g[i].clear();
	}
	scanf("%d%d%d%d", &a, &b, &c, &d);
	--a;
	--b;
	--c;
	--d;
	for (int i = 1; i < n; ++i) {
		int p;
		scanf("%d", &p);
		--p;
		// printf("%d ---> %d\n", p + 1, i + 1);
		g[p].pb(i);
	}
	return 1;
}

void get(int v, vi& vs) {
	if  (g[v].empty()) {
		vs.pb(v);
		return;
	}

	for (int to : g[v]) {
		// printf("%d -> %d\n", v + 1, to + 1);
		get(to, vs);
	}
}

int cnt[MAXN];
int A, B, C, D;
bool dp[2][MAXN];

bool in(const vi& vs, int x) {
	int pos = lower_bound(all(vs), x) - vs.begin();
	return pos < sz(vs) && vs[pos] == x;
}

bool solve() {
	memset (cnt, 0, sizeof cnt);
	const int r = 0;

	int all = 0;
	A = B = C = D = -1;
	for (int to : g[r]) {
		vi vs;
		get(to, vs);

		sort(all(vs));

		if  (in(vs, a)) {
			A = sz(vs);
		} else if  (in(vs, b)) {
			B = sz(vs);
		} else if  (in(vs, c)) {
			C = sz(vs);
		} else if  (in(vs, d)) {
			D = sz(vs);
		}

		++cnt[sz(vs)];
		all += sz(vs);

		// printf("sz=%d\n", sz(vs));
	}
	assert(A != -1 && B != -1 && C != -1 && D != -1);

	--cnt[A];
	--cnt[B];

	memset (dp, 0, sizeof dp);
	int id = 0;
	dp[id][0] = 1;
	for (int w = 1; w < n; ++w) {
		if  (!cnt[w]) {
			continue;
		}
		memset (dp[id ^ 1], 0, sizeof dp[id ^ 1]);
		for (int take = (w == C) ? 1 : 0; take <= cnt[w]; ++take) {
			forn(have, n + 1) {
				if  (!dp[id][have]) {
					continue;
				}
				if  (have + take * w < MAXN) {
					dp[id ^ 1][have + take * w] = 1;
				}
			}
		}

		id ^= 1;
	}

	if  (all & 1) {
		return 0;
	}

	int between = (all - 2) / 2;
	bool ok = 0;
	forn(x, n + 1) {
		if  (dp[id][x] && x <= between && between <= x + A + B - 2) {
			int rr = all - A - B - x;
			forn(ww, x) {
				int left = ww + B;
				int right = ww + B + rr - 1;
				if  (left <= between && between <= right) {
					return 1;
				}
			}
		}
	}
	return 0;
}

int main() {
#ifdef LOCAL
	freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif

	while (read()) {
		puts(solve() ? "YES" : "NO");
	}

#ifdef LOCAL
	cerr.precision(5);
	cerr << "Time: " << fixed << (double) clock() / CLOCKS_PER_SEC << endl;
#endif
	return 0;
}