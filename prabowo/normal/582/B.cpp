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
#define MOD9 1000000009
#define INF 2000000000
#define INFLL 9000000000000000000LL
#define EPS 1e-7
#define FOR(i, a, b) for (int i=a; i<b; i++)
#define FORR(i, n) FOR(i, 0, n)
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

int n, t;
int a[20002];
int cnt[303];
int dp[303][20002];

int f(int val, int x) {
    if (x == n * min(t, 2 * n)) return 0;
    if (dp[val][x] != -1) return dp[val][x];

    int &ret = dp[val][x] = f(val, x+1);

    if (val <= a[x]) MAX(ret, 1 + f(a[x], x+1));
    return ret;
}

int main () {
    scanf("%d %d", &n, &t);

    int maks = 0;
    FORR(i, n) {
        scanf("%d", &a[i]);
        FOR(j, 1, min(2 * n, t)) a[j*n+i] = a[i];
        cnt[a[i]]++;
        MAX(maks, cnt[a[i]]);
    }

    memset(dp, -1, sizeof dp);

    int ans = 0;
    FORR(i, 300+1) MAX(ans, cnt[i] * max(0, t - 2 * n) + f(i, 0));

    printf("%d\n", f(0, 0) + maks * max(0, t - 2 * n));

    return 0;
}