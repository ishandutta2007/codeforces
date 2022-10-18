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

const int MAXN = 2e5 + 10;

int n;
set<int> g[MAXN];

bool read() {
	if  (scanf("%d", &n) < 1) {
		return 0;
	}
	forn(i, n) {
		g[i].clear();
	}
	forn(i, n - 1) {
		int a, b;
		scanf("%d%d", &a, &b);
		--a;
		--b;
		g[a].insert(b);
		g[b].insert(a);
	}
	return 1;
}

bool alive[MAXN];

void rem(int v, int p) {
	// printf("rem v=%d, p=%d\n", v + 1, p + 1);

	alive[v] = 0;
	g[p].erase(v);
	g[v].erase(p);

	vi sons(all(g[v]));
	for (int to : sons) {
		rem(to, v);
	}
}

int dfs(int v, int p) {
	assert(alive[v]);

	// printf("v=%d, p=%d\n", v + 1, p + 1);

	vii sons;
	for (int to : g[v]) {
		if  (to == p) {
			continue;
		}
		int len = dfs(to, v);
		if  (len != -1) {
			++len;
		}
		sons.pb(mp(len, to));
	}

	if  (sons.empty()) {
		return 0; 
	}

	sort(all(sons));

	forn(i, sz(sons) - 1) {
		if  (sons[i].fst == -1) {
			continue;
		}
		if  (sons[i].fst == sons[i + 1].fst) {
			rem(sons[i].snd, v);
		}
	}

	assert(!sons.empty());

	if  (sons.front().fst == -1) {
		return -1;
	}

	if  (sons.front().fst == sons.back().fst) {
		return sons.front().fst + 1;
	}

	return -1;
}

int solve() {
	forn(i, n) {
		alive[i] = 1;
	}

	int root = -1;
	forn(v, n) {
		if  (root == -1 || sz(g[root]) < sz(g[v])) {
			root = v;
		}
	}

	dfs(root, -1);

	root = -1;
	forn(v, n) {
		if  (alive[v]) {
			if  (root == -1 || sz(g[root]) < sz(g[v])) {
				root = v;
			}
		}
	}

	assert(root != -1);

	dfs(root, -1);

	int cnt_alive = 0;
	forn(v, n) {
		if  (alive[v]) {
			if  (sz(g[v]) > 2) {
				return -1;
			}
			++cnt_alive;
		}
	}
	assert(cnt_alive);
	int len = cnt_alive - 1;
	while (len % 2 == 0 && len > 0) {
		len /= 2;
	}
	return len;
}

int main() {
#ifdef LOCAL
	freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif

	while (read()) {
		printf("%d\n", solve());
	}

#ifdef LOCAL
	cerr.precision(5);
	cerr << "Time: " << fixed << (double) clock() / CLOCKS_PER_SEC << endl;
#endif
	return 0;
}