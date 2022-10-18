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


const int MAXN = 1e5 + 10;

map<ll, ll> cost;

vll gen_par(ll v) {
	vll res;
	while (v) {
		res.pb(v);
		v /= 2;
	}
	return res;
}

void add(ll v, ll u, int w) {
	vll pv = gen_par(v);
	vll pu = gen_par(u);

	bool found = false;
	forn(i, sz(pv)) forn(j, sz(pu)) {
		if  (pv[i] == pu[j] && !found) {
			found = true;
			forn(ii, i) {
				cost[pv[ii]] += w;
			}
			forn(jj, j) {
				cost[pu[jj]] += w;
			}
		}
	}
}

ll ask(ll v, ll u) {
	vll pv = gen_par(v);
	vll pu = gen_par(u);

	forn(i, sz(pv)) forn(j, sz(pu)) {
		if  (pv[i] == pu[j]) {
			ll ans = 0;
			forn(ii, i) {
				ans += cost[pv[ii]];
			}
			forn(jj, j) {
				ans += cost[pu[jj]];
			}
			return ans;
		}
	}

	assert(false);
	return -1;
}

void solve() {
	int q;
	scanf("%d", &q);
	forn(i, q) {
		int t;
		ll v, u;
		scanf("%d%lld%lld", &t, &v, &u);
		if  (t == 1) {
			int w;
			scanf("%d", &w);
			add(v, u, w);
		} else {
			printf("%lld\n", ask(v, u));
		}
	}
}

int main() {
#ifdef LOCAL
	freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif

	solve();

#ifdef LOCAL
	cerr.precision(5);
	cerr << "Time: " << fixed << (double) clock() / CLOCKS_PER_SEC << endl;
#endif
	return 0;
}