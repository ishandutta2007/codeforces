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
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef long double ld;
typedef complex<double> cd;

#define FILE_NAME "a"

const int MAXN = 1e5 + 10;

int n, m, k;
bool good[MAXN];
vi g[MAXN];

bool read() {
	if  (scanf("%d%d%d", &n, &m, &k) < 3) {
		return 0;
	}
	memset (good, 0, sizeof good);
	forn(i, k) {
		int c;
		scanf("%d", &c);
		--c;
		good[c] = 1;
	}
	forn(i, n) {
		g[i].clear();
	}
	forn(i, m) {
		int v, u;
		scanf("%d%d", &v, &u);
		--v;
		--u;
		g[v].pb(u);
		g[u].pb(v);
	}
	return 1;
}

bool was[MAXN];
int nodes;
int edges;
bool was_good;

void dfs(int v) {
	assert(!was[v]);
	was[v] = 1;
	was_good |= good[v];
	++nodes;
	edges += sz(g[v]);
	for (int to : g[v]) {
		if  (!was[to]) {
			dfs(to);
		}
	}
}

ll solve() {
	int mx_good = 0;
	vi other;
	memset (was, 0, sizeof was);
	ll ans = 0;
	forn(v, n) {
		if  (!was[v]) {
			nodes = 0;
			edges = 0;
			was_good = 0;
			dfs(v);
			edges /= 2;
			ans += nodes * 1ll * (nodes - 1) / 2 - edges;
			if  (was_good) {
				mx_good = max(mx_good, nodes);
			} else {
				other.pb(nodes);
			}
		}
	}	

	assert(mx_good > 0);
	for (int s : other) {
		ans += s * 1ll * mx_good;
		mx_good += s;
	}
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