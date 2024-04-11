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
#define image(c) sort(all(c)), c.resize(unique(all(c)) - c.begin())

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

const int MAXN = 3e5 + 10;

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
		g[b].pb(a);
	}
	return 1;
}

ull mrand() {
	return (rand() * 1ull * RAND_MAX) ^ rand();
}

struct DSU {
	vi par;

	DSU(int n = 0) {
		par.assign(n, -1);
	}

	int get(int x) {
		return par[x] < 0 ? x : par[x] = get(par[x]);
	}

	bool unite(int x, int y) {
		x = get(x);
		y = get(y);

		if  (x == y) {
			return 0;
		}

		if  (-par[x] < -par[y]) {
			swap(x, y);
		}

		par[x] += par[y];
		par[y] = x;
		return 1;
	}
};

ull coef[MAXN];
ull nei[MAXN];
bool alive[MAXN];
int x[MAXN];

bool solve() {
	forn(v, n) {
		image(g[v]);
	}

	forn(v, n) {
		coef[v] = mrand();
 	}

 	forn(v, n) {
 		nei[v] = 0;
 		for (int to : g[v]) {
 			nei[v] += coef[to];
 		}
 	}

 	DSU dsu(n);
 	forn(v, n) {
 		for (int to : g[v]) {
 			ull my = nei[v] - coef[to];
 			ull his = nei[to] - coef[v];
 			if  (my == his) {
 				dsu.unite(v, to);
 			}
 		}
 	}

 	forn(v, n) {
 		alive[v] = dsu.get(v) == v;
 	}

 	// forn(v, n) {
 	// 	printf("v=%d, alive=%d\n", v + 1, alive[v]);
 	// }

 	forn(v, n) {
 		vi ng;
 		for (int to : g[v]) {
 			if  (alive[to]) {
 				ng.pb(to);
 			}
 		}
 		g[v].swap(ng);
 	}

 	vi used(n, 0);
 	memset (x, -1, sizeof x);
 	int ptr = 1;
 	forn(v, n) {
 		if  (!alive[v] || sz(g[v]) > 1 || used[v]) {
 			continue;
 		}
 		int u = v;
 		vi vs;
 		while (1) {
 			// printf("v=%d, u=%d\n", v + 1, u + 1);
 			vi cands;
 			for (int to : g[u]) {
 				if  (!vs.empty() && to == vs.back()) {
 					continue;
 				}
 				cands.pb(to);
 			}
 			vs.pb(u);
 			if  (sz(cands) > 1) {
 				return 0;
 			}
 			if  (cands.empty()) {
 				break;
 			}
 			u = cands.front();
 		}

 		assert(sz(vs) >= 1);
 		assert(sz(g[vs.front()]) <= 1);
  		assert(sz(g[vs.back()]) <= 1);
  		for (int i = 1; i + 1 < sz(vs); ++i) {
  			assert(sz(g[vs[i]]) == 2);
  		}

  		for (int u : vs) {
  			x[u] = ptr++;
  			// printf("x = %d\n", x[u]);
  			used[u] = 1;
  		}
  		ptr += 2;
 	}

 	forn(v, n) {
 		if  (alive[v] && !used[v]) {
 			return 0;
 		}
 	}

 	forn(v, n) {
 		x[v] = x[dsu.get(v)];
 	}

 	puts("YES");
 	forn(v, n) {
 		printf("%d ", x[v]);
 	}
 	puts("");
 	return 1;
}

int main() {
#ifdef LOCAL
	freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif

	while (read()) {
		if  (!solve()) {
			puts("NO");
		}
	}

#ifdef LOCAL
	cerr.precision(5);
	cerr << "Time: " << fixed << (double) clock() / CLOCKS_PER_SEC << endl;
#endif
	return 0;
}