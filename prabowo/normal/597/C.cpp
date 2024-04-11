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

int n, k;
pii a[100002];

struct BIT {
    LL sum[100002];

    void update (int x, LL val) {
        for (int i=x; i<=n; i+=i&-i) sum[i] += val;
    }

    LL query (int x) {
        LL ret = 0;
        for (int i=x; i; i-=i&-i) ret += sum[i];
        return ret;
    }
} bit[11];

int main () {
    scanf("%d %d", &n, &k);
    FORR(i, n) scanf("%d", &a[i].fi), a[i].se = i + 1;

    sort (a, a + n);

    FORR(i, n) {
        bit[0].update(a[i].se, 1);
        FORR(j, k) bit[j+1].update(a[i].se, bit[j].query(a[i].se-1));
    }

    printf("%I64d\n", bit[k].query(n));

    return 0;
}