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

int n, M;

void add(int& x, int y) {
	x = (x + y) % M;
}

int mul(int x, int y) {
	return x * 1ll * y % M;
}

vii g[MAXN];

bool read() {
	if  (scanf("%d%d", &n, &M) < 1) {
		return false;
	}
	forn(i, n) {
		g[i].clear();
	}
	forn(i, n - 1) {
		int a, b, w;
		scanf("%d%d%d", &a, &b, &w);
		w %= M;
		g[a].pb(mp(b, w));
		g[b].pb(mp(a, w));
	}
	return true;
}

bool was[MAXN];
int sz[MAXN];
map<int, int> cnt;
int pow10[MAXN];
int inv_pow10[MAXN];

int mpow(int a, int p) {
	int res = 1;
	for (; p > 0; p >>= 1, a = mul(a, a)) {
		if  (p & 1) {
			res = mul(res, a);
		}
	}
	return res;
}

int P;

int inv(int x) {
	int y = mpow(x, P - 1);
	assert(mul(x, y) == 1);
	return y;
}

void precalc() {
	P = 1;
	int N = M;
	for (int x = 2; x * x <= N; ++x) {
		if  (N % x == 0) {
			int deg = 0;
			int c = 1;
			while (N % x == 0) {
				N /= x;
				++deg;
				c *= x;
			}
			P *= c - c / x;
		}
	}
	if  (N > 1) {
		P *= N - 1;
	}

	pow10[0] = 1;
	for (int i = 1; i < MAXN; ++i) {
		pow10[i] = mul(pow10[i - 1], 10);
	}
	forn(i, MAXN) {
		inv_pow10[i] = inv(pow10[i]);
	}
}

void dfs_sz(int v, int p) {
	sz[v] = 1;
	// printf("V=%d\n", v);
	for (auto e : g[v]) {
		int to = e.fst;
		if  (to == p || was[to]) {
			continue;
		}
		dfs_sz(to, v);
		sz[v] += sz[to];
	}
}

int dfs_root(int v, int p, int S) {
	int mx_to = -1;
	for (auto e : g[v]) {
		int to = e.fst;
		if  (to == p || was[to]) {
			continue;
		}
		if  (mx_to == -1 || sz[to] > sz[mx_to]) {
			mx_to = to;
		}
	}
	if  (mx_to == -1 || sz[mx_to] * 2 <= S) {
		return v;
	}
	return dfs_root(mx_to, v, S);
}

int get_root(int v) {
	dfs_sz(v, -1);
	return dfs_root(v, -1, sz[v]);
}

void dfs0(int v, int p, int coef, int cur, int p10) {
	cnt[cur] += coef;

	for (auto e : g[v]) {
		int to = e.fst;
		if  (to == p || was[to]) {
			continue;
		}
		int w = e.snd;
		int ncur = cur;
		add(ncur, mul(pow10[p10], w));
		dfs0(to, v, coef, ncur, p10 + 1);
	}
}

void dfs1(int v, int p, int cur, int depth, ll& ans) {
	// x * pow10[depth] == -cur
	int need = (-cur % M + M) % M;
	need = mul(need, inv_pow10[depth]);

	// printf("v=%d, need=%d\n", v, need);

	// printf("and += %d\n", cnt[need]);

	ans += cnt[need];
	
	if  (cur == 0) {
		// printf("++ans at v=%d\n", v);
		++ans;
	}

	for (auto e : g[v]) {
		int to = e.fst;
		if  (to == p || was[to]) {
			continue;
		}
		int w = e.snd;
		int ncur = mul(cur, 10);
		add(ncur, w);
		dfs1(to, v, ncur, depth + 1, ans);
	}
}

ll solve(int r) {
	r = get_root(r);

	cnt.clear();
	for (auto e : g[r]) {
		int to = e.fst;
		if  (was[to]) {
			continue;
		}
		int w = e.snd;
		dfs0(to, r, +1, w, 1);
	}

	ll ans = cnt[0];
	// printf("cnt[0] = %d\n", cnt[0]);
	for (auto e : g[r]) {
		int to = e.fst;
		if  (was[to]) {
			continue;
		}
		int w = e.snd;
		dfs0(to, r, -1, w, 1);
		// for (auto it : cnt) printf("%d -> %d\n", it.fst, it.snd);
		dfs1(to, r, w, 1, ans);
		dfs0(to, r, +1, w, 1);
	}

	// printf("r = %d, cur_ans = %lld\n", r, ans);

	was[r] = true;
	for (auto e : g[r]) {
		int to = e.fst;
		if  (was[to]) {
			continue;
		}
		ans += solve(to);
	}

	return ans;
}

ll solve() {
	if  (M == 1) {
		return n * 1ll * (n - 1);
	}
	precalc();
	memset (was, 0, sizeof was);
	return solve(0);
}

int main() {
#ifdef LOCAL
	freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif

	while (read()) {
		cout << solve() << endl;
	}

#ifdef LOCAL
	cerr.precision(5);
	cerr << "Time: " << fixed << (double) clock() / CLOCKS_PER_SEC << endl;
#endif
	return 0;
}