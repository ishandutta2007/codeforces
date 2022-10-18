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
vi g[MAXN];
int c[MAXN];

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
	forn(i, n) {
		scanf("%d", &c[i]);
	}
	return 1;
}

int mx1[MAXN];
int mx2[MAXN];

void dfs0(int v, int p) {
	mx1[v] = c[v];
	mx2[v] = -1;

	for (int to : g[v]) {
		if  (to == p) {
			continue;
		}

		dfs0(to, v);

		for (int val : {mx1[to], mx2[to]}) {
			if  (val == -1) {
				continue;
			}
			if  (val == mx1[v] || val == mx2[v]) {
				continue;
			}
			if  (val > mx1[v]) {
				mx2[v] = mx1[v];
				mx1[v] = val;
			} else if  (val > mx2[v]) {
				mx2[v] = val;
			}
		}
	}
}

int dfs(int v, int p, int C) {
	int bad_to = -1;
	vi cs;
	for (int to : g[v]) {
		if  (to == p) {
			continue;
		}
		if  (mx2[to] != -1) {
			if  (bad_to != -1) {
				return -1;
			}
			bad_to = to;
			continue;
		} else {
			cs.pb(mx1[to]);
		}
	}

	// printf("v=%d, bad_to=%d\n", v, bad_to);

	if  (bad_to == -1) {
		return v;
	}

	cs.pb(c[v]);
	if  (C != -1) {
		cs.pb(C);
	}

	sort(all(cs));
	cs.resize(unique(all(cs)) - cs.begin());

	if  (sz(cs) > 1) {
		return -1;
	}

	return dfs(bad_to, v, cs.front());
}

bool solve() {
	memset (mx1, -1, sizeof mx1);
	memset (mx2, -1, sizeof mx2);

	dfs0(0, -1);

	int res = dfs(0, -1, -1);
	if  (res == -1) {
		return 0;
	}
	printf("YES\n");
	printf("%d\n", res + 1);
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