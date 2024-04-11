#include <cstdio>
#include <cassert>
#include <cmath>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <istream>
#include <ostream>
#include <deque>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <vector>
#include <algorithm>
#include <functional>
#include <string>
#include <utility>

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define endl '\n'
#define MOD 1000000007
#define MOD9 1000000009
#define INF 2000000000
#define INF2 1000000000
#define INFLL 9000000000000000000LL
#define INFLL2 4500000000000000000LL
#define EPS 1e-7
#define debug puts("ganteng")
#define FOR(i, a, b) for (int i=a; i<b; i++)
#define FORR(i, n) FOR(i, 0, n)
#define REV(i, a, b) for (int i=a-1; i>=b; i--)
#define REVV(i, n) REV(i, n, 0)
#define ALL(x) x.begin(), x.end()
#define UNIK(x) unique(ALL(x)) - x.begin()
#define MAX(a, b) a = max(a, b)
#define MIN(a, b) a = min(a, b)
#define sqr(x) (((LL)x) * ((LL)x))
#define SYNC ios_base::sync_with_stdio(0), cin.tie(0)
#define TLE using
#define RTE namespace
#define WA std

TLE RTE WA;

typedef long long LL;
typedef pair <int, int> pii;
typedef pair <int, pii> pipii;

typedef vector <int> vi;
typedef vector <pii> vii;
typedef pair <LL, LL> pll;
typedef vector <LL> vl;
typedef vector <pll> vll;

//////// End of Template ////////

pii p[3];

bool f (pii x, pii y, pii z) {
	return (x.fi == y.fi && (z.se <= min(x.se, y.se) || z.se >= max(x.se, y.se)) ||
			x.se == y.se && (z.fi <= min(x.fi, y.fi) || z.fi >= max(x.fi, y.fi)));
}

int main () {
	FORR (i, 3) scanf ("%d %d", &p[i].fi, &p[i].se);
	
	if (p[0].fi == p[1].fi && p[1].fi == p[2].fi || p[0].se == p[1].se && p[1].se == p[2].se) printf ("1\n");
	else if (f(p[0], p[1], p[2]) || f(p[0], p[2], p[1]) || f(p[1], p[2], p[0])) printf ("2\n");
	else printf ("3\n");
    return 0;
}