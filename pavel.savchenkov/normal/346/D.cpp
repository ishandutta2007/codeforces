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
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef long double ld;
typedef complex<double> cd;

#define FILE_NAME "a"

const int MAXN = 1e6 + 10;
const int INF = 1e9;

int n, m;
vi gt[MAXN];
vi g[MAXN];
int s, t;

bool read() {
	if  (scanf("%d%d", &n, &m) < 2) {
		return 0;
	}
	forn(i, n) {
		g[i].clear();
		gt[i].clear();
	}
	forn(i, m) {
		int a, b;
		scanf("%d%d", &a, &b);
		--a;
		--b;
		g[a].pb(b);
		gt[b].pb(a);
	}
	scanf("%d%d", &s, &t);
	--s;
	--t;
	return 1;
}

int dp[MAXN];
set<pii> sons[MAXN];

int solve() {
	forn(v, n) {
		dp[v] = INF;
	}
	forn(v, n) {
		sons[v].clear();
		for (int to : g[v]) {
			sons[v].insert(mp(dp[to], to));
		}		
	}

	vii q;
	q.pb(mp(t, 0));
	forn(it, sz(q)) {
		int ndp, v;
		tie(v, ndp) = q[it];

		if  (dp[v] <= ndp) {
			continue;
		}

		for (int from : gt[v]) {
			sons[from].erase(mp(dp[v], v));
			sons[from].insert(mp(ndp, v));

			int ndp_from = min(sons[from].rbegin()->fst, sons[from].begin()->fst + 1);
			if  (ndp_from < dp[from]) {
				q.pb(mp(from, ndp_from));
			}
		}

		dp[v] = ndp;
	}

	return dp[s] >= INF ? -1 : dp[s];
}

int main() {
#ifdef LOCAL
	freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif

	while (read()) {
		printf("%d\n", solve());
	}

#ifdef LOCAL
	cerr.precision(5);
	cerr << "Time: " << fixed << (double) clock() / CLOCKS_PER_SEC << endl;
#endif
	return 0;
}
//