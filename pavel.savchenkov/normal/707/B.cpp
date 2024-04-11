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

const int MAXN = 1e5 + 10;
const int INF = 2e9;

vii g[MAXN];
int n, m, k;
bool can[MAXN];

int main() {
#ifdef LOCAL
	freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif

	scanf("%d%d%d", &n, &m, &k);
	forn(i, m) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		--a;
		--b;
		g[a].pb(mp(b, c));
		g[b].pb(mp(a, c));
	}
	memset (can, true, sizeof can);
	forn(i, k) {
		int id;
		scanf("%d", &id);
		--id;
		can[id] = false;
	}

	int ans = INF;
	forn(i, n) for (auto e : g[i]) {
		int to = e.fst;
		if  (can[i] && !can[to]) {
			ans = min(ans, e.snd);
		}
	}

	if  (ans == INF) ans = -1;
	cout << ans << endl;
	

#ifdef LOCAL
	cerr.precision(5);
	cerr << "Time: " << fixed << (double) clock() / CLOCKS_PER_SEC << endl;
#endif
	return 0;
}