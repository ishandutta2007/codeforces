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
#define MOD 1000000007
#define INF 2000000000
#define INFLL 9000000000000000000LL
#define EPS 1e-7
#define FOR(i, a, b) for (int i=a; i<b; i++)
#define ALL(x) x.begin(), x.end()
#define UNIK(x) unique(ALL(x) - x.begin())
#define MAX(a, b) a = max(a, b)
#define MIN(a, b) a = min(a, b)
#define SYNC ios_base::sync_with_stdio(0)
#define kita using
#define emang namespace
#define ganteng std

kita emang ganteng;

typedef long long LL;
typedef pair <int, int> pii;
typedef pair <int, pii> pipii;
typedef vector <int> vi;
typedef vector <pii> vii;
typedef pair <LL, LL> pll;
typedef vector <LL> vl;
typedef vector <pll> vll;

//////// End of Template ////////

int n;

LL f(LL x, int y) {
    if (y == 0) return 1;
    return (y & 1) ? x * f(x * x % MOD, y >> 1) % MOD : f(x * x % MOD, y >> 1);
}

int main () {
    scanf("%d", &n);
    LL ans = 1;
    FOR (i, 1, n+2) ans *= f(i, MOD-2), ans %= MOD;
    ans *= ans;
    ans %= MOD;

    FOR (i, 1, 2*n+3) ans *= i, ans %= MOD;

    ans--;
    if (ans < 0) ans += MOD;

    printf("%I64d\n", ans);
    return 0;
}