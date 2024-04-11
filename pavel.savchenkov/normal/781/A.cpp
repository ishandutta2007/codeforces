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
vi g[MAXN];

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
		g[a].pb(b);
		g[b].pb(a);
	}
	return 1;
}

int c[MAXN];

void dfs(int v, int p) {
	int ptr = 0;

	auto norm = [&]() {
		while (1) {
			if  (ptr == c[v]) {
				++ptr;
				continue;
			}
			if  (p != -1 && ptr == c[p]) {
				++ptr;
				continue;
			}
			break;
		}
	};

	norm();

	for (int to : g[v]) {
		if  (to == p) {
			continue;
		}
		c[to] = ptr;

		dfs(to, v);

		++ptr;
		norm();
	}
}

void solve() {
	int root = 0;
	forn(v, n) {
		if  (sz(g[v]) > sz(g[root])) {
			root = v;
		}
	}
	c[root] = 0;
	dfs(root, -1);

	set<int> s;
	forn(v, n) {
		s.insert(c[v]);
	}
	printf("%d\n", sz(s));
	forn(v, n) {
		printf("%d ", c[v] + 1);
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