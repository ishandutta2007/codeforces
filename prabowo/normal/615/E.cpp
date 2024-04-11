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

int main () {
    LL n;
    scanf ("%I64d", &n);

    int l = 0;
    int r = 1000000000;
    int ans = 0;
    while (l < r) {
        LL mid = l + r >> 1;
        if (mid * (mid + 1) * 3 < n) {
            l = mid + 1;
        } else r = mid;
    }

    LL mid = l;
    pll pos = mp(mid << 1, 0);
    n -= mid * (mid - 1) * 3;

    if (n >= mid) n -= mid, pos = mp(pos.fi - mid, pos.se + 2 * mid); else pos = mp(pos.fi - n, pos.se + 2 * n), n = 0;
    if (n >= mid) n -= mid, pos = mp(pos.fi - 2 * mid, pos.se); else pos = mp(pos.fi - 2 * n, pos.se), n = 0;
    if (n >= mid) n -= mid, pos = mp(pos.fi - mid, pos.se - 2 * mid); else pos = mp(pos.fi - n, pos.se - 2 * n), n = 0;
    if (n >= mid) n -= mid, pos = mp(pos.fi + mid, pos.se - 2 * mid); else pos = mp(pos.fi + n, pos.se - 2 * n), n = 0;
    if (n >= mid) n -= mid, pos = mp(pos.fi + 2 * mid, pos.se  ); else pos = mp(pos.fi + 2 * n, pos.se), n = 0;
    if (n >= mid) n -= mid, pos = mp(pos.fi + mid, pos.se + 2 * mid); else pos = mp(pos.fi + n, pos.se + 2 * n), n = 0;

    printf ("%I64d %I64d\n", pos.fi, pos.se);

    return 0;
}