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

pii point [100002];

LL dot (pii x, pii y, pii z) {
    return (LL) (x.fi - y.fi) * (z.fi - y.fi) + (LL) (x.se - y.se) * (z.se - y.se);
}

LL cross (pii x, pii y, pii z) {
    return (LL) (y.fi - x.fi) * (z.se - y.se) - (LL) (y.se - x.se) * (z.fi - y.fi);
}

int main () {
    int n;
    pii p;
    scanf ("%d %d %d", &n, &p.fi, &p.se);

    FORR(i, n) scanf ("%d %d", &point[i].fi, &point[i].se);

    LL maks = 0;
    LL mini = INFLL;

    FORR(i, n) MAX(maks, sqr (point[i].fi - p.fi) + sqr(point[i].se - p.se)),
               MIN(mini, sqr (point[i].fi - p.fi) + sqr(point[i].se - p.se));

    point[n++] = point[0];

    double a = sqrt (mini);
    FORR(i, n - 1) {
        if (dot(p, point[i], point[i + 1]) > 0 && dot(p, point[i + 1], point[i]) > 0) {
            MIN(a, (double) abs(cross(p, point[i], point[i + 1]) / hypot(point[i].fi - point[i + 1].fi, point[i].se - point[i + 1].se)));
        }
    }

    // cout << sqrt(maks) << " " << a << endl;

    printf("%.18lf\n", acos(-1) * maks - acos(-1) * a * a);

    return 0;
}