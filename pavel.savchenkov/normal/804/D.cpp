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

const int MAXN = 1e5 + 10;

int n, m, q;
vi g[MAXN];

bool read() {
	if  (scanf("%d%d%d", &n, &m, &q) < 3) {
		return 0;
	}
	forn(i, n) {
		g[i].clear();
	}
	forn(i, m) {
		int a, b;
		scanf("%d%d", &a, &b);
		--a;
		--b;
		g[a].pb(b);
		g[b].pb(a);
	}
	return 1;
}

int comp[MAXN];
vi who[MAXN];
vll pref[MAXN];
int most_far[MAXN];
bool was[MAXN];
int comps;
int depth[MAXN];

void dfs0(int v, int p) {
	was[v] = 1;
	depth[v] = 0;
	for (int to : g[v]) {
		if  (to == p) {
			continue;
		}
		comp[to] = comp[v];
		dfs0(to, v);
		depth[v] = max(depth[v], depth[to] + 1);
	}
}

void dfs1(int v, int p, int up) {
	int mx1 = -1;
	int mx2 = -1;
	for (int to : g[v]) {
		if (to == p) {
			continue;
		}
		int cur = depth[to] + 1;
		if  (cur > mx1) {
			mx2 = mx1;
			mx1 = cur;
		} else if  (cur > mx2) {
			mx2 = cur;
		}
	}

	most_far[v] = max(up, depth[v]);
	who[comp[v]].pb(most_far[v]);

	for (int to : g[v]) {
		if  (to == p) {
			continue;
		}
		int cur = mx1;
		if  (depth[to] + 1 == mx1) {
			cur = mx2;
		}
		dfs1(to, v, max(up + 1, cur + 1));
	}
}

void precalc(int root) {
	comp[root] = comps++;

	dfs0(root, -1);
	
	dfs1(root, -1, 0);

	int c = comp[root];
	sort(all(who[c]));
	pref[c].resize(sz(who[c]) + 1, 0);
	forn(i, sz(who[c])) {
		pref[c][i + 1] = pref[c][i] + who[c][i];
	}
}

void precalc() {
	forn(i, n) {
		who[i].clear();
		pref[i].clear();
	}
	memset (was, 0, sizeof was);
	comps = 0;

	forn(v, n) {
		if  (!was[v]) {
			precalc(v);
		}
	}
}

map<pii, ld> mem_ans;

ld ask(int v, int u) {
	v = comp[v];
	u = comp[u];
	if  (v == u) {
		return -1;
	}

	if  (sz(who[v]) > sz(who[u])) {
		swap(v, u);
	}
	
	pii C(v, u);
	if  (mem_ans.count(C)) {
		return mem_ans[C];
	}

	ll sum = 0;
	ll cnt = sz(who[v]) * 1ll * sz(who[u]);
	int have = max(who[v].back(), who[u].back());
	for (const auto& left : who[v]) {
		// left + right + 1 > have
		// right > have - left - 1
		int pos = upper_bound(all(who[u]), have - left - 1) - who[u].begin();

		sum += pos * 1ll * have;

		sum += pref[u].back() - pref[u][pos];
		sum += (sz(who[u]) - pos) * 1ll * (left + 1);
	}

	ld ans = ld(sum) / cnt;
	return (mem_ans[C] = ans);
}

void solve() {
	precalc();

	forn(it, q) {
		int a, b;
		scanf("%d%d", &a, &b);
		--a;
		--b;
		printf("%.10f\n", (double) ask(a, b));
	}
}

int main() {
#ifdef LOCAL
	freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif

	while (read()) {
		solve();
	}

#ifdef LOCAL
	cerr.precision(5);
	cerr << "Time: " << fixed << (double) clock() / CLOCKS_PER_SEC << endl;
#endif
	return 0;
}