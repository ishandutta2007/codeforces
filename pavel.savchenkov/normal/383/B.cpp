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

using namespace std;

#define pb push_back
#define f first
#define s second
#define mp make_pair 
#define sz(A) ((int)(A).size())
#define forn(i, n) for (int i = 0; i < (int) n; i++)
#define ford(i, n) for (int i = ((int) n) - 1; i >= 0; i--)
#define foran(i, a, n) for (int i = (int) a; i < (int) n; i++)
#define y1 gftxdtrtfhyjfctrxujkvbhyjice
#define y0 ehfoiuvhefroerferjhfjkehfjke
#define left sdhfsjkshdjkfsdfgk
#define right yytrwtretywretwreytwreytwr
#define all(A) A.begin(), A.end()

template <typename T>
inline T sqr( T x ) {
	return x * x;
}

typedef long long ll;
typedef unsigned long long ull;
typedef pair <int,int> pii;
typedef pair <ll, ll> pll;
typedef vector <ll> vll;
typedef vector <int> vi;
typedef unsigned int uint;

const double EPS = 1e-9;
const int MAXN = int(1e5) + 10;

int n, m;
vi all_x;
vi row_y[MAXN];
pii pairs[MAXN];

int main() {           
	scanf("%d%d", &n, &m);	

	forn(i, m) {
		scanf("%d%d", &pairs[i].f, &pairs[i].s);
		all_x.pb(pairs[i].f);
	}

	all_x.pb(1);
	pairs[m++] = mp(1, n + 1);
	all_x.pb(n);
	pairs[m++] = mp(n, n + 1);

	sort(all(all_x));
	all_x.resize(unique(all(all_x)) - all_x.begin());

	forn(i, m) {
		int x = pairs[i].f;

		int pos = lower_bound(all(all_x), x) - all_x.begin();

		row_y[pos].pb(pairs[i].s);
	}

	forn(i, sz(all_x))
		sort(all(row_y[i]));

	vector <pii> bounds;
	if  (all_x[0] == 1) {
		bounds.pb(mp(1, row_y[0][0] - 1));
	} else {
		bounds.pb(mp(1, n));
	}

	forn(i, sz(all_x) - 1) {
		if  (all_x[i + 1] > all_x[i] + 1 && !bounds.empty()) {
			bounds[sz(bounds) - 1].s = n;
		}

		vector <pii> new_bounds;
		forn(j, sz(bounds)) {
			int l = bounds[j].f;
			int r = bounds[j].s;

			int pos = lower_bound(all(row_y[i + 1]), l) - row_y[i + 1].begin();

			int last = l - 1;
			for (int k = pos; k < sz(row_y[i + 1]) && row_y[i + 1][k] <= r; k++) {
				int y = row_y[i + 1][k];

				if  (last < y - 1)
					new_bounds.pb(mp(last + 1, y - 1));

				last = y;
			}

			if  (last < r) {
				pos = upper_bound(all(row_y[i + 1]), r) - row_y[i + 1].begin();
	
				new_bounds.pb(mp(last + 1, pos == sz(row_y[i + 1]) ? n : (row_y[i + 1][pos] - 1)));
			}
	  	}

		bounds.clear();

		int l = 1;
		int r = -1;
		forn(j, sz(new_bounds)) {
			int L = new_bounds[j].f;
			int R = new_bounds[j].s;

			if  (max(l, L) > min(r, R)) {
				if  (l <= r)
					bounds.pb(mp(l, r));
				l = L;
				r = R;
				continue;
			}

			l = min(l, L);
			r = max(r, R);	
		}

		if  (l <= r)
			bounds.pb(mp(l, r));		
	}

	printf("%d\n", (!bounds.empty() && bounds[sz(bounds) - 1].s == n) ? (2 * n - 2) : (-1));
	return 0;
}