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


int n;
vi a;

bool read() {
	if  (scanf("%d", &n) < 1) {
		return 0;
	}
	a.resize(n);
	forn(i, n) {
		scanf("%d", &a[i]);
	}
	return 1;
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

void solve() {
	vi c;
	for (int x : a) {
		c.pb(x);
	}
	sort(all(c));
	assert(unique(all(c)) - c.begin() == n);
	for (int& x : a) {
		x = lower_bound(all(c), x) - c.begin();
	}

	vi pos(n);
	forn(i, n) {
		pos[a[i]] = i;
	}

	DSU dsu(n);
	forn(i, n) {
		dsu.unite(pos[i], i);
	}

	vvi res(n);
	forn(i, n) {
		res[dsu.get(i)].pb(i);
	}

	int k = 0;
	forn(i, n) {
		k += !res[i].empty();
	}

	printf("%d\n", k);
	forn(i, n) {
		if  (res[i].empty()) {
			continue;
		}
		printf("%d ", sz(res[i]));
		for (int x : res[i]) {
			printf("%d ", x + 1);
		}
		puts("");
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