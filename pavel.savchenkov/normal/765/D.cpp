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

const int MAXN = 1e5 + 10;

int n;
int f[MAXN];

bool read() {
	if  (scanf("%d", &n) < 1) {
		return 0;
	}
	forn(i, n) {
		scanf("%d", &f[i]);
		--f[i];
	}
	return 1;
}

vi inv_f[MAXN];
int g[MAXN];
int h[MAXN];

bool solve() {
	forn(i, n) {
		inv_f[i].clear();
	}
	forn(i, n) {
		inv_f[f[i]].pb(i);
	}

	memset (g, -1, sizeof g);
	int m = 0;

	forn(i, n) {
		if (inv_f[i].empty()) {
			continue;
		}

		if  (f[i] != i) {
			return 0;
		}

		for (int j : inv_f[i]) {
			g[j] = m;
		}
		h[m] = i;
		++m;
	}

	forn(x, m) {
		assert(g[h[x]] == x);
	}

	forn(x, n) {
		assert(h[g[x]] == f[x]);
	}

	printf("%d\n", m);
	forn(i, n) {
		printf("%d ", g[i] + 1);
	}
	puts("");
	forn(i, m) {
		printf("%d ", h[i] + 1);
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
			puts("-1");
		}
	}

#ifdef LOCAL
	cerr.precision(5);
	cerr << "Time: " << fixed << (double) clock() / CLOCKS_PER_SEC << endl;
#endif
	return 0;
}