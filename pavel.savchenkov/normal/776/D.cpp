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

const int MAXN = 5e5 + 10;

int n, m;
int r[MAXN];
vi cover[MAXN];

bool read() {
	if  (scanf("%d%d", &n, &m) < 2) {
		return 0;
	}
	forn(i, n) {
		scanf("%d", &r[i]);
	}
	forn(i, m) {
		int cnt;
		scanf("%d", &cnt);
		cover[i].resize(cnt);
		forn(j, cnt) {
			scanf("%d", &cover[i][j]);
			--cover[i][j];
		}
	}
	return 1;
}

int who[MAXN][2];
vi g[MAXN];
vi gt[MAXN];

void addE(int v, int to) {
	g[v].pb(to);
	gt[to].pb(v);
}

void add_cond(int x1, int x2) {
	addE(x1 ^ 1, x2);
	addE(x2 ^ 1, x1);
}

bool was[MAXN];

void dfs0(int v, vi& order) {
	assert(!was[v]);
	was[v] = 1;
	for (int to : g[v]) {
		if  (!was[to]) {
			dfs0(to, order);
		}
	}
	order.pb(v);
}

int comp[MAXN];

void dfs1(int v) {
	assert(!was[v]);
	was[v] = 1;
	for (int to : gt[v]) {
		if  (!was[to]) {
			comp[to] = comp[v];
			dfs1(to);
		}
	}
}

bool solve() {
	forn(i, 2 * m) {
		g[i].clear();
		gt[i].clear();
	}

	memset (who, -1, sizeof who);
	forn(i, m) {
		for (int j : cover[i]) {
			if  (who[j][0] == -1) {
				who[j][0] = i;
			} else {
				assert(who[j][1] == -1);
				who[j][1] = i;
			}
		}
	}

	forn(it, n) {
		int i = who[it][0];
		int j = who[it][1];
		assert(j != -1);
		if  (r[it] == 1) {
			add_cond(2 * i + 1, 2 * j);
			add_cond(2 * i, 2 * j + 1);
		} else {
			add_cond(2 * i, 2 * j);
			add_cond(2 * i + 1, 2 * j + 1);
		}
	}

	memset (was, 0, sizeof was);
	vi order;
	forn(v, 2 * m) {
		if  (!was[v]) {
			dfs0(v, order);
		}
	}
	reverse(all(order));

	memset (was, 0, sizeof was);
	int comps = 0;
	for (int v : order) {
		if  (!was[v]) {
			comp[v] = comps++;
			dfs1(v);
		}
	}

	forn(i, m) {
		if  (comp[2 * i] == comp[2 * i + 1]) {
			return 0;
		}
	}
	return 1;
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