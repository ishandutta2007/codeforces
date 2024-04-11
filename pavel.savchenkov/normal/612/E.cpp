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
typedef pair <int,int> pii;
typedef pair <ll, ll> pll;
typedef vector <ll> vll;
typedef vector <int> vi;
typedef vector <vector <int> > vvi;
typedef vector <pii> vii;
typedef long double ld;
typedef complex<double> cd;
typedef vector<cd> vcd;

#define FILE_NAME "a"

const ld EPS = 1e-9;
const int MAXN = 1e6 + 10;

vvi cycles;
int n;
int p[MAXN];
int q[MAXN];

bool read() {
	if  (scanf("%d", &n) < 1) {
		return false;
	}
	forn(i, n) {
		scanf("%d", &p[i]);
		--p[i];
	}
	cycles.clear();
	return true;
}

void place_cycle(const vi& cycle) {
	forn(i, sz(cycle)) {
		q[cycle[i]] = cycle[(i + 1) % sz(cycle)];
	}
}

bool solve() {
	vi used(n, 0);
	forn(i, n) {
		if  (!used[i]) {
			vi cycle;
			int j = i;
			while (!used[j]) {
				used[j] = true;
				cycle.pb(j);
				j = p[j];
			}
			cycles.pb(cycle);
			// puts("cycle:");
			// for (int v : cycle) {
			// 	printf("%d ", v + 1);
			// }
			// puts("");
		}
	}

	vi perm(sz(cycles));
	forn(i, sz(cycles)) perm[i] = i;
	sort(all(perm), [](int i, int j) { return sz(cycles[i]) < sz(cycles[j]); });

	forn(i, sz(cycles)) {
		int id = perm[i];
		// if  (sz(cycles[id]) == 1) {
		// 	q[cycles[id][0]] = cycles[id][0];
		// 	continue;
		// }
		if  (sz(cycles[id]) & 1) {
			vi new_cycle(sz(cycles[id]));
			int pos = 0;
			forn(it, sz(cycles[id])) {
				new_cycle[pos] = cycles[id][it];
				pos = (pos + 2) % sz(cycles[id]);
			}
			place_cycle(new_cycle);
		} else {
			if  (i + 1 == sz(cycles)) {
				return false;
			}
			int id2 = perm[i + 1];
			if  (sz(cycles[id2]) != sz(cycles[id])) {
				return false;
			}
			vi new_cycle(sz(cycles[id]) + sz(cycles[id2]));
			forn(it, sz(new_cycle)) {
				if  (it & 1) {
					new_cycle[it] = cycles[id][it / 2];
				} else {
					new_cycle[it] = cycles[id2][it / 2];
				}
			}
			place_cycle(new_cycle);
			++i;
		}
	}

	forn(i, n) assert(p[i] == q[q[i]]);

	forn(i, n) {
		printf("%d ", q[i] + 1);
	}
	puts("");
	return true;
}

int main() {
#ifdef DEBUG
	freopen(FILE_NAME ".in", "r", stdin);
//	freopen(FILE_NAME ".out", "w", stdout);
#endif
	
	while (read()) {
		if  (!solve()) {
			puts("-1");
		}
	}
	return 0;
}