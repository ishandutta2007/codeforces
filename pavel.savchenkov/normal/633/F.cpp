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

using namespace std;

#define pb push_back
#define fst first
#define snd second
#define mp make_pair 
#define sz(C) ((int) (C).size())
#define forn(i, n) for (int i = 0; i < (int) n; ++i)
#define ford(i, n) for (int i = ((int) n) - 1; i >= 0; --i)
#define y1 gftxdtrtfhyjfctrxujkvbhyjice
#define y0 ehfoiuvhefroerferjhfjkehfjke
#define left sdhfsjkshdjkfsdfgkqqweqweh
#define right yytrwtretywretwreytwreytwr
#define next jskdfksdhfjkdsjksdjkgf
#define prev koeuigrihjdkjdfj
#define hash kjfdkljkdhgjdkfhgurehg
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

const int MAXN = 2e5 + 10;
const ll INF = 1e18;

vi g[MAXN];
int n;
int a[MAXN];

bool read() {
	if  (scanf("%d", &n) < 1) {
		return false;
	}
	forn(i, n) {
		scanf("%d", &a[i]);
	}
	forn(i, n) {
		g[i].clear();
	}
	forn(i, n - 1) {
		int v, u;
		scanf("%d%d", &v, &u);
		--v;
		--u;
		g[v].pb(u);
		g[u].pb(v);
	}
	return true;
}

ll dp[MAXN][2];

void dfs0(int v, int p) {
	for (int to : g[v]) {
		if  (to == p) {
			continue;
		}
		dfs0(to, v);
	}

	dp[v][0] = dp[v][1] = a[v];

	for (int to : g[v]) {
		if  (to == p) {
			continue;
		}
		dp[v][1] = max(dp[v][1], a[v] + dp[to][1]);
		dp[v][0] = max(dp[v][0], max(dp[to][0], dp[to][1]));
	}

	ll mx1 = -INF;
	ll mx2 = -INF;
	for (int to : g[v]) {
		if  (to == p) {
			continue;
		}
		ll cur = dp[to][1];
		if  (cur > mx1) {
			mx2 = mx1;
			mx1 = cur;
		} else if  (cur > mx2) {
			mx2 = cur;
		}
	}

	dp[v][0] = max(dp[v][0], mx1 + mx2 + a[v]);
}

ll ans;

struct cmp_alone {
	bool operator()(int i, int j) const {
		ll I = max(dp[i][0], dp[i][1]);
		ll J = max(dp[j][0], dp[j][1]);
		if  (I != J) return I > J;
		return i < j;
	}
};

struct cmp_cont {
	bool operator()(int i, int j) const {
		ll I = dp[i][1];
		ll J = dp[j][1];
		if  (I != J) return I > J;
		return i < j;
	}
};

int ptr;

void dfs(int v, int p, ll d0, ll d1) {
	ans = max(ans, max(dp[v][0], dp[v][1]) + max(d0, d1));

	set<int, cmp_alone> by_alone;
	set<int, cmp_cont> by_cont;
	for (int to : g[v]) {
		if  (to == p) {
			continue;
		}
		by_alone.insert(to);
		by_cont.insert(to);
	}
	dp[ptr][0] = d0;
	dp[ptr][1] = d1;
	by_alone.insert(ptr);
	by_cont.insert(ptr);
	++ptr;

	for (int to : g[v]) {
		if  (to == p) {
			continue;
		}
		by_cont.erase(to);
		by_alone.erase(to);


		ll nd0 = d0;
		int x = *by_alone.begin();
		nd0 = max(nd0, max(dp[x][0], dp[x][1]));
		x = *by_cont.begin();
		by_cont.erase(x);
		int y = -1;
		if  (!by_cont.empty()) {
			y = *by_cont.begin();
			nd0 = max(nd0, dp[x][1] + a[v] + dp[y][1]);
		}
		nd0 = max(nd0, dp[x][1] + a[v]);
		by_cont.insert(x);
		x = *by_cont.begin();
		ll nd1 = dp[x][1] + a[v];

		dfs(to, v, nd0, nd1);


		by_cont.insert(to);
		by_alone.insert(to);		
	}
}

ll solve() {
	dfs0(0, -1);
	ans = 0;
	ptr = n;
	dfs(0, -1, 0, 0);
	return ans;
}

int main() {
#ifdef DEBUG
	freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif

	while (read()) {
		cout << solve() << '\n';
	}

	return 0;
}