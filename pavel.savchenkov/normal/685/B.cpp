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

#define pb push_back
#define fst first
#define snd second
#define mp make_pair 
#define sz(C) ((int) (C).size())
#define forn(i, n) for (int i = 0; i < (int) n; ++i)
#define ford(i, n) for (int i = ((int) n) - 1; i >= 0; --i)
#define y1 gftxdtrtfhyjfctrxujkvbhyjice
#define y0 ehfoiuvhefroerferjhfjkehfjke
#define left sdhfsjkshdjkfsdfgkqqweqweh
#define right yytrwtretywretwreytwreytwr
#define next jskdfksdhfjkdsjksdjkgf
#define prev koeuigrihjdkjdfj
#define hash kjfdkljkdhgjdkfhgurehg
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


const int MAXN = 3e5 + 10;

int sz[MAXN];
int ans[MAXN];
vi g[MAXN];
int par[MAXN];
int n, q;

bool read() {
	if  (scanf("%d%d", &n, &q) < 2) {
		return false;
	}
	forn(i, n - 1) {
		int p;
		scanf("%d", &p);
		--p;

		int a = i + 1;
		par[a] = p;
		g[p].pb(a);
	}
	return true;
}

void dfs(int v) {
	sz[v] = 1;
	int max_to = -1;
	for (int to : g[v]) {
		dfs(to);
		sz[v] += sz[to];
		if  (max_to == -1 || sz[to] > sz[max_to]) {
			max_to = to;
		}
	}

	if  (max_to == -1) {
		ans[v] = v;
		return;
	}

	int u = ans[max_to];
	while ((sz[v] - sz[u]) * 2 > sz[v]) {
		u = par[u];
	}

	ans[v] = u;
}

void solve() {
	dfs(0);

	forn(i, q) {
		int v;
		scanf("%d", &v);
		--v;
		printf("%d\n", ans[v] + 1);
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