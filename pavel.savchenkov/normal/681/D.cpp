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

int p[MAXN];
int n, m;
vi g[MAXN];
int a[MAXN];
vi who_want[MAXN];
bool alive[MAXN];

bool read() {
	if  (scanf("%d%d", &n, &m) < 2) {
		return false;
	}
	memset (p, -1, sizeof p);
	forn(i, m) {
		int a, b;
		scanf("%d%d", &a, &b);
		--a;
		--b;
		p[b] = a;
		g[a].pb(b);
	}
	forn(i, n) {
		scanf("%d", &a[i]);
		--a[i];
		who_want[a[i]].pb(i);
	}
	return true;
}

void solve() {
	set<int> roots;
	vi ans;

	memset (alive, true, sizeof alive);

	forn(i, n) {
		if  (p[i] == -1) {
			roots.insert(i);
		}
	}

	while (!roots.empty()) {
		int v = *roots.begin();
		roots.erase(roots.begin());

		if  (!alive[v]) {
			continue;
		}

		for (int u : who_want[v]) {
			for (int z = u; z != v && alive[z]; z = p[z]) {
				alive[z] = false;
				if  (!who_want[z].empty()) {
					puts("-1");
					exit(0);
				}
				for (int to : g[z]) {
					if  (alive[to]) {
						roots.insert(to);
					}
				}
			}
		}

		ans.pb(v);

		for (int to : g[v]) {
			if  (alive[to]) {
				roots.insert(to);
			}
		}
	}

	reverse(all(ans));

	printf("%d\n", sz(ans));
	for (int v : ans) {
		printf("%d\n", v + 1);
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
	printf("Time: %.2f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}