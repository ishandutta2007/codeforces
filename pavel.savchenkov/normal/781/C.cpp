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

int n, m, k;
vi g[MAXN];

bool read() {
	if  (scanf("%d%d%d", &n, &m, &k) < 3) {
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

bool was[MAXN];

void dfs(int v, vi& order) {
	assert(!was[v]);
	was[v] = 1;
	order.pb(v);
	for (int to : g[v]) {
		if  (was[to]) {
			continue;
		}
		dfs(to, order);
		order.pb(v);
	}
}

void solve() {
	memset (was, 0, sizeof was);
	vi order;
	dfs(0, order);

	vvi ans(k);
	vi cnt(k, 0);
	forn(i, sz(order)) {
		++cnt[i % k];
	}

	int j = 0;
	for (int v : order) {
		while (j < k && !cnt[j]) {
			++j;
		}
		assert(j < k);
		--cnt[j];
		ans[j].pb(v);
	}

	forn(i, k) {
		if  (ans[i].empty()) {
			ans[i].pb(0);
		}
		printf("%d ", sz(ans[i]));
		for (int v : ans[i]) {
			printf("%d ", v + 1);
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