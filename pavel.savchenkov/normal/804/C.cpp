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
vvi g;
vector<set<int>> who;

bool read() {
	if  (scanf("%d%d", &n, &m) < 2) {
		return 0;
	}
	who.clear();
	who.resize(n);
	forn(i, n) {
		int s;
		scanf("%d", &s);
		forn(j, s) {
			int t;
			scanf("%d", &t);
			--t;
			who[i].insert(t);
		}
	}
	g.clear();
	g.resize(n);
	forn(i, n - 1) {
		int a, b;
		scanf("%d%d", &a, &b);
		--a;
		--b;
		g[a].pb(b);
		g[b].pb(a);
	}
	return 1;
}

vi color;
set<pii> by_deg;
vi alive;
vi deg;

void go() {
	assert(!by_deg.empty());

	int v = by_deg.begin()->snd;
	by_deg.erase(by_deg.begin());

	assert(deg[v] <= 1);
	alive[v] = 0;

	// eprintf("v = %d\n", v + 1);

	int par = -1;
	for (int to : g[v]) {
		if  (alive[to]) {
			assert(par == -1);
			par = to;
			by_deg.erase(mp(deg[to], to));
			--deg[to];
			by_deg.insert(mp(deg[to], to));
		}
	}
	set<int> have;
	if  (par != -1) {
		go();
		for (int t : who[par]) {
			if  (who[v].count(t)) {
				have.insert(color[t]);
			}
		}
	}

	int ptr = 0;
	for (int t : who[v]) {
		if  (par != -1 && who[par].count(t)) {
			continue;
		}
		while (have.count(ptr)) {
			++ptr;
		}
		color[t] = ptr;
		++ptr;
	}
}

void solve() {
	color.assign(m, -1);
	alive.assign(n, 1);
	by_deg.clear();
	deg.resize(n);
	forn(v, n) {
		deg[v] = sz(g[v]);
		by_deg.insert(mp(deg[v], v));
	}

	go();

	forn(i, m) {
		if  (color[i] == -1) {
			color[i] = 0;
		}
	}

	set<int> colors;
	forn(i, m) {
		colors.insert(color[i]);
	}
	printf("%d\n", sz(colors));
	forn(i, m) {
		printf("%d ", color[i] + 1);
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