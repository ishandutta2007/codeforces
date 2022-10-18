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

vi g[MAXN];
int cnt[MAXN];
ll ans;
int n, k;

bool read() {
	if  (scanf("%d %d", &n, &k) < 2) {
		return false;
	}
	forn(i, n) {
		g[i].clear();
	}
	memset (cnt, 0, sizeof cnt);
	forn(i, 2 * k) {
		int u;
		scanf("%d", &u);
		--u;
		++cnt[u];
	}
	forn(i, n - 1) {
		int a, b;
		scanf("%d %d", &a, &b);
		--a;
		--b;
		g[a].pb(b);
		g[b].pb(a);
	}
	return true;
}

void lift(int v, int p) {
	if  (cnt[v] > 2 * k - cnt[v]) {
		cnt[v] = 2 * k - cnt[v];
		k = cnt[v];
	}
	ans += cnt[v];
	cnt[p] += cnt[v];
}

void dfs(int v, int p) {
	for (int to : g[v]) {
		if  (to != p) {
			dfs(to, v);
			lift(to, v);
		}
	}
}

ll solve() {
	ans = 0;
	dfs(n - 1, -1);
	return ans;
}

int main() {
#ifdef LOCAL
	freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif

	while (read()) {
		cout << solve() << endl;
	}

#ifdef LOCAL
	cerr.precision(5);
	cerr << "Time: " << fixed << (double) clock() / CLOCKS_PER_SEC << endl;
#endif
	return 0;
}