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
typedef vector<vector <int> > vvi;
typedef vector<pii> vii;
typedef long double ld;
typedef complex<double> cd;
typedef vector<cd> vcd;

#define FILE_NAME "a"

const int MAXN = 4e5 + 10;

vi g[MAXN];
int n;

bool read() {
	if  (scanf("%d", &n) < 1) {
		return false;
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
	return true;
}

int ans[MAXN];
int dp[MAXN];
int sz[MAXN];

void dfs0(int v, int p) {
	sz[v] = 1;
	dp[v] = 0;
	for (int to : g[v]) {
		if  (to == p) {
			continue;
		}
		dfs0(to, v);
		sz[v] += sz[to];
		dp[v] = max(dp[v], dp[to]);
		if  (2 * sz[to] <= n) {
			dp[v] = max(dp[v], sz[to]);
		}
	}
}

void dfs(int v, int p, int dp_up) {
	// printf("v=%d, dp_up=%d\n", v, dp_up);

	if  (2 * (n - sz[v]) > n) {
		int rest = n - sz[v];
		int nsz = max(rest - dp_up, dp_up);
		if  (2 * nsz <= n) {
			ans[v] = 1;
		}
	} else {
		int mx_to = -1;
		for (int to : g[v]) {
			if  (to == p) {
				continue;
			}
			if  (mx_to == -1 || sz[mx_to] < sz[to]) {
				mx_to = to;
			}
		}
		if  (mx_to == -1 || 2 * sz[mx_to] <= n) {
			ans[v] = 1;
		} else {
			int nsz = max(sz[mx_to] - dp[mx_to], dp[mx_to]);
			if  (2 * nsz <= n) {
				ans[v] = 1;
			}
		}
	}

	vi sons;
	for (int to : g[v]) {
		if  (to != p) {
			sons.pb(to);
		}
	}

	vi dp_sons;
	for (int to : sons) {
		if  (2 * sz[to] <= n) {
			dp_sons.pb(sz[to]);
		} else {
			dp_sons.pb(dp[to]);
		}
	}

	int mx1 = 0;
	int mx2 = 0;
	for (int d : dp_sons) {
		if  (d > mx1) {
			mx2 = mx1;
			mx1 = d;
		} else if  (d > mx2) {
			mx2 = d;
		}
	}

	forn(i, sz(sons)) {
		int to = sons[i];
		int d = dp_sons[i];

		int mx = (d == mx1) ? mx2 : mx1;

		if  (2 * (n - sz[to]) <= n) {
			mx = max(mx, n - sz[to]);
		}	
		mx = max(mx, dp_up);

		dfs(to, v, mx);
	}
}

void solve() {
	dfs0(0, -1);

	memset (ans, 0, sizeof ans);
	dfs(0, -1, 0);

	forn(i, n) {
		printf("%d ", ans[i]);
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