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

#ifdef LOCAL
#define eprintf(args...) fprintf(stderr, args), fflush(stderr)
#else
#define eprintf(...) ;
#endif

#define FILE_NAME "a"

const int MAXN = 2e5 + 10;

int n;
vi g[MAXN];
int a[MAXN];

bool read() {
	if  (scanf("%d", &n) < 1) {
		return 0;
	}
	forn(i, n) {
		scanf("%d", &a[i]);
	}
	forn(i, n) {
		g[i].clear();
	}
	forn(i, n - 1) {
		int v, u;
		scanf("%d%d", &v, &u);
		--v;
		--u;
		g[v].pb(u);
		g[u].pb(v);
	}
	return 1;
}

vi divs[MAXN];

void precalc() {
	for (int i = 1; i < MAXN; ++i) {
		for (int j = i; j < MAXN; j += i) {
			divs[j].pb(i);
		}
	}

	// int mx = 0;
	// forn(i, MAXN) {
	// 	mx = max(mx, sz(divs[i]));
	// }
	// eprintf("mx = %d\n", mx);
}

int ans[MAXN];
int cnt[MAXN];

void dfs(int v, int p, int dep) {
	for (int d : divs[a[v]]) {
		++cnt[d];
	}

	if  (v) {
		for (int d : divs[a[v]]) {
			if  (cnt[d] >= dep - 1) {
				ans[v] = max(ans[v], d);
			}
		}
		for (int d : divs[a[p]]) {
			// eprintf("d = %d, cnt = %d, dep = %d\n", d, cnt[d], dep);
			if  (cnt[d] >= dep - 1) {
				ans[v] = max(ans[v], d);
			}
		}
	} else {
		ans[v] = a[v];
	}

	for (int to : g[v]) {
		if  (to == p) {
			continue;
		}
		dfs(to, v, dep + 1);
	}

	for (int d : divs[a[v]]) {
		--cnt[d];
	}
}

void solve() {
	memset (cnt, 0, sizeof cnt);
	dfs(0, -1, 1);

	forn(v, n) {
		printf("%d ", ans[v]);
	}
	puts("");
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