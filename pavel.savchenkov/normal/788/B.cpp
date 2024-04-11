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

const int MAXN = 1e6 + 10;

int n, m;
vi g[MAXN];

bool read() {
	if  (scanf("%d%d", &n, &m) < 2) {
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
		if  (a != b) {
			g[b].pb(a);
		}
	}
	return 1;
}

bool was[MAXN];

void dfs(int v) {
	assert(!was[v]);
	was[v] = 1;
	for (int to : g[v]) {
		if  (!was[to]) {
			dfs(to);
		}
	}
}

ll solve() {
	memset (was, 0, sizeof was);
	forn(v, n) {
		if  (!g[v].empty()) {
			dfs(v);
			break;
		}
	}
	forn(v, n) {
		if  (!was[v] && !g[v].empty()) {
			return 0;
		}
	}
	
	int leafs = 0;
	ll ans = 0;
	forn(v, n) {
		int deg = sz(g[v]);
		for (int to : g[v]) {
			deg -= (to == v);
			leafs += (to == v);
		}
		ans += deg * 1ll * (deg - 1) / 2;
	}
	ans += (m - leafs) * 1ll * leafs;
	ans += leafs * 1ll * (leafs - 1) / 2;
	return ans;
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