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

const ll INF = 1e18;

int n;
vvi g;
vi w;
vi p;
vi id;
vi par;

bool read() {
	if  (scanf("%d", &n) < 1) {
		return 0;
	}
	g.clear();
	g.resize(n);
	w.resize(n);
	p.resize(n);
	id.resize(n);
	par.resize(n);
	id[0] = -1;
	par[0] = -1;
	forn(i, n - 1) {
		int x, y, ww, pp;
		scanf("%d%d%d%d", &x, &y, &ww, &pp);
		--x;
		--y;
		g[x].pb(y);
		id[y] = i;
		w[y] = ww;
		p[y] = pp;
		par[y] = x;
	}
	return 1;
}

void NO() {
	puts("-1");
	exit(0);
}

vll dp;
vll sub;

void dfs0(int v) {
	dp[v] = 0;
	for (int to : g[v]) {
		dfs0(to);
		dp[v] += dp[to];
		sub[v] += sub[to];
	}
	if  (id[v] != -1) {
		ll x = w[v] - 1;
		x = min(x, p[v] - dp[v]);
		if  (x < 0) {
			NO();
		}
		dp[v] += w[v] - x;
		sub[v] += w[v];
	}

	// printf("v=%d, dp=%lld\n", v + 1, dp[v]);
}

ll dfs1(int v, ll L) {
	// printf("v=%d, L=%lld\n", v + 1, L);

	if  (v) {
		L = min(L, sub[v]);
	}

	ll sons = 0;
	for (int to : g[v]) {
		sons += dp[to];
	}

	if  (!v || sons + w[v] <= L) {
		if  (v) {
			L = min(L - w[v], 1ll * p[v]);
		}
		ll sum = 0;
		for (int to : g[v]) {
			sons -= dp[to];
			ll cur = dfs1(to, L - sons);
			sum += cur;
			L -= cur;
		}
		return sum + w[v];
	}

	ll sum = 0;
	for (int to : g[v]) {
		sum += dfs1(to, dp[to]);
	}

	ll x = w[v] - (L - sum);
	w[v] -= x;
	p[v] -= x;

	sum += w[v];

	return sum;
}

void solve() {
	dp.resize(n);
	sub.resize(n);

	dfs0(0);

	dfs1(0, INF);

	vi perm(n - 1);
	iota(all(perm), 1);
	sort(all(perm), [&](int i, int j) { return id[i] < id[j]; });

	printf("%d\n", n);
	for (int i : perm) {
		printf("%d %d %d %d\n", par[i] + 1, i + 1, w[i], p[i]);
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