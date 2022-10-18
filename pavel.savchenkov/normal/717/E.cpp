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

const int MAXN = 2e5 + 10;

vi g[MAXN];
int c[MAXN];
int n;

bool read() {
	if  (scanf("%d", &n) < 1) {
		return false;
	}
	forn(i, n) {
		g[i].clear();
	}
	forn(i, n) {
		scanf("%d", &c[i]);
		if  (c[i] == -1) c[i] = 0;
	}
	forn(i, n - 1) {
		int a, b;
		scanf("%d%d", &a, &b);
		--a;
		--b;
		g[a].pb(b);
		g[b].pb(a);
	}
	return true;
}

vi ans;

void push(int v) {
	ans.pb(v);
	c[v] ^= 1;
}

bool dp[MAXN];

void dfs0(int v, int p) {
	dp[v] = c[v] == 1;
	for (int to : g[v]) {
		if (to == p) {
			continue;
		}
		dp[v] &= dp[to];
	}
}

void dfs(int v, int p) {
	push(v);

	if  (dp[v]) {
		assert(v == 0);
		return;
	}

	for (int to : g[v]) {
		if  (to == p) {
			continue;
		}
		if  (dp[to]) {
			continue;
		}
		dfs(to, v);
		push(v);
		if  (c[to] == 0) {
			push(to);
			push(v);
		}
	}
}

void solve() {
	dfs0(0, -1);
	ans.clear();
	c[0] ^= 1;
	dfs(0, -1);

	if  (c[0] == 0) {
		push(g[0][0]);
		push(0);
		push(g[0][0]);
	}

	forn(i, n) {
		assert(c[i] == 1);
	}
	
	for (int v : ans) {
		printf("%d ", v + 1);
	}
	puts("");
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