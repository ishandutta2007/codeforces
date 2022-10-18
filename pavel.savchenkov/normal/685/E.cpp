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


const int MAXN = 1e3 + 10;
const int MAXM = 2e5 + 10;
const int INF = 2e9;

struct Query {
	int l, r, s, t;
	int id;

	bool read(int i) {
		id = i;
		if  (scanf("%d%d%d%d", &l, &r, &s, &t) < 4) {
			return false;
		}
		--l;
		--r;
		--s;
		--t;
		return true;
	}
};

int n, m, q;
int dist[MAXN][MAXN];
pii who_edge[MAXM];
vector<Query> qs[MAXM];
bool ans[MAXM];

bool read() {
	if  (scanf("%d%d%d", &n, &m, &q) < 3) {
		return false;
	}
	forn(i, m) {
		int v, u;
		scanf("%d%d", &v, &u);
		--v;
		--u;
		who_edge[i] = mp(v, u);
	}
	forn(i, q) {
		Query Q;
		assert(Q.read(i));
		qs[Q.l].pb(Q);
	}
	return true;
}

void solve() {
	forn(i, n) forn(j, n) dist[i][j] = INF * (i != j);

	memset (ans, false, sizeof ans);

	ford(T, m) {
		int v, u;
		tie(v, u) = who_edge[T];

		dist[v][u] = dist[u][v] = T;
		forn(c, n) {
			if  (c == v || c == u) {
				continue;
			}

			dist[v][c] = min(dist[v][c], dist[u][c]);

			dist[u][c] = min(dist[u][c], dist[v][c]);
		}

		for (const auto& q : qs[T]) {
			int l = q.l;
			int r = q.r;
			assert(l == T);
			int s = q.s;
			int t = q.t;

			ans[q.id] = (dist[s][t] <= r);
		}

		// printf("after T = %d\n", T + 1);
		// forn(i, n) forn(j, i) {
		// 	printf("dist[%d][%d] = %d\n", i + 1, j + 1, dist[i][j] + 1);
		// }
	}

	forn(i, q) {
		puts(ans[i] ? "Yes" : "No");
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