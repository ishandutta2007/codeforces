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

int n, m;
vector<vii> g;
int s;

bool read() {
	if  (scanf("%d%d", &n, &m) < 2) {
		return 0;
	}
	g.clear();
	g.resize(n);
	forn(i, m) {
		int a, b, w;
		scanf("%d%d%d", &a, &b, &w);
		--a;
		--b;
		g[a].pb(mp(b, w));
	}
	scanf("%d", &s);
	--s;
	return 1;
}

void dfs0(int v, vi& used, const vector<vii>& g, vi& top) {
	assert(!used[v]);
	used[v] = 1;
	for (const auto& e : g[v]) {
		const int to = e.fst;
		if  (!used[to]) {
			dfs0(to, used, g, top);
		}
	}
	top.pb(v);
}

void dfs1(int v, vi& comp, const vector<vii>& g) {
	assert(comp[v] != -1);
	for (const auto& e : g[v]) {
		const int to = e.fst;
		if  (comp[to] == -1) {
			comp[to] = comp[v];
			dfs1(to, comp, g);
		}
	}
}

ll sum(int l, int r) {
	if  (l > r) {
		return 0;
	}
	const int a1 = l;
	const int an = r;
	const int n = r - l + 1;
	return (a1 + an) * 1ll * n / 2;
}

ll sum_sum(int k) {
	static vll mem{};
	if  (mem.empty()) {
		mem.pb(0);
	}
	while (k >= sz(mem)) {
		const int s = sz(mem);
		mem.pb(sum(1, s));
		mem.back() += mem[sz(mem) - 2];
	}
	return mem[k];
}

const int MAX = 1e8 + 10;

// int mem_k[MAX];

// void precalc() {
// 	for (int i = 1; i < MAX; ++i) {
// 		mem_k[i] = mem_k[i - 1];
// 		while (sum(1, mem_k[i] + 1) <= i) {
// 			++mem_k[i];
// 		}
// 	}
// }

ll cost_all(int x) {
	int L = sqrt(x * 2) - 5;
	int R = sqrt(x * 2) + 5;
	while (L != R - 1) {
		int M = (L + R) >> 1;
		if  (x - sum(1, M) >= 0) {
			L = M;
		} else {
			R = M;
		}
	}
	const int k = L;
	return x + x * 1ll * k - sum_sum(k);
}

int cost1(int x) {
	return x;
}

ll solve() {
	vector<vii> gt(n);
	forn(v, n) {
		for (const auto& e : g[v]) {
			gt[e.fst].pb(mp(v, e.snd));
		}
	}

	vi top;
	vi used(n);
	forn(v, n) {
		if  (!used[v]) {
			dfs0(v, used, g, top);
		}
	}

	assert(sz(top) == n);
	reverse(all(top));

	int comps = 0;
	vi comp(n, -1);
	for (int v : top) {
		if  (comp[v] == -1) {
			comp[v] = comps++;
			dfs1(v, comp, gt);
		}
	}

	vll cost_comp(comps);
	forn(v, n) {
		for (const auto& e : g[v]) {
			const int to = e.fst;
			if  (comp[v] == comp[to]) {
				cost_comp[comp[v]] += cost_all(e.snd);
			}
		}
	}

	// eprintf("comps = %d, costs:\n", comps);
	// forn(v, comps) {
	// 	eprintf("%lld ", cost_comp[v]);
	// }
	// eprintf("\n");

	vector<vii> g_comps(comps);
	forn(v, n) {
		for (const auto& e : g[v]) {
			const int to = e.fst;
			if  (comp[v] != comp[to]) {
				g_comps[comp[v]].pb(mp(comp[to], cost1(e.snd)));
			}
		}
	}

	top.clear();
	used.assign(comps, 0);
	forn(v, comps) {
		if  (!used[v]) {
			dfs0(v, used, g_comps, top);
		}
	}
	// reverse(all(top));

	vll dp(comps);
	for (int v : top) {
		dp[v] = cost_comp[v];
		for (const auto& e : g_comps[v]) {
			const int to = e.fst;
			dp[v] = max(dp[v], cost_comp[v] + e.snd + dp[to]);
		}
	}

	return dp[comp[s]];
}

int main() {
#ifdef LOCAL
	freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif

	// precalc();

	// eprintf("%lld\n", cost_all(9));

	while (read()) {
		printf("%lld\n", solve());
	}

#ifdef LOCAL
	cerr.precision(5);
	cerr << "Time: " << fixed << (double) clock() / CLOCKS_PER_SEC << endl;
#endif
	return 0;
}