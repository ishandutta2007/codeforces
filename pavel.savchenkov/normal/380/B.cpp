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

const double EPS = 1e-9;
const int MAXN = 7000 + 10;
const int MAXVAL = int(1e7) + 10;

struct query {
	int l, r, x;

	query( int l, int r, int x ) : l(l), r(r), x(x) {}
};

inline bool pow2( int x ) {
	return (x & (x - 1)) == 0;
}

int n, m;
vector <query> query_level[MAXN];
int timer;
int last_seen[MAXVAL];
int cnt_pow2[MAXVAL];

inline int get_left( int pos, int lev ) {
	int cnt_less = (pos - 1) + cnt_pow2[pos];

	return cnt_less + 1;
}

inline int get_right( int pos, int lev ) {
	int cnt_less = (pos - 1) + cnt_pow2[pos];

	if  (pow2(pos))
		return cnt_less + 2;
	else
		return cnt_less + 1;
}
 
int main() {
    memset (last_seen, -1, sizeof last_seen);
    timer = 0;

    int cnt = 0;
    for (int x = 1; x < MAXVAL; x++) {
    	cnt_pow2[x] = cnt;
    	cnt += pow2(x);
    }

	scanf("%d%d", &n, &m);
	
	while (m --> 0) {
		int type;
		scanf("%d\n", &type);

		if  (type == 1) {
			int t, l, r, x;
			scanf("%d%d%d%d", &t, &l, &r, &x);
			query_level[t].pb(query(l, r, x));
		} else {
			int lev, pos;
			scanf("%d%d", &lev, &pos);

			int l = pos;
			int r = pos;
			int ans = 0;

			for (int level = lev; level <= n; level++) {
				forn(i, sz(query_level[level])) {
					int L = query_level[level][i].l;
					int R = query_level[level][i].r;
					int x = query_level[level][i].x;

					if  (max(l, L) <= min(r, R)) {
						if  (last_seen[x] < timer) {
							ans++;
						}
						last_seen[x] = timer;
					}
				}

				l = get_left(l, level);
				r = get_right(r, level);
			}

			printf("%d\n", ans);
			timer++;
		}
	}

	return 0;
}