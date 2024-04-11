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

int n, k;
char s[100002];
LL inv[100002];
LL fak[100002];
LL p10[100002];
LL sum[100002];

LL pangkat (LL x, LL y) {
    if (y == 0) return 1;
    return (y & 1) ? x * pangkat(x * x % MOD, y >> 1) % MOD : pangkat (x * x % MOD, y >> 1);
}

int main () {
    scanf("%d %d", &n, &k);
    gets(s); gets(s);

    inv[0] = 1; for (int i=1; i<=n; i++) inv[i] = inv[i-1] * pangkat(i, MOD-2) % MOD;
    fak[0] = 1; for (int i=1; i<=n; i++) fak[i] = fak[i-1] * i % MOD;
    p10[0] = 1; for (int i=1; i<=n; i++) p10[i] = p10[i-1] * 10 % MOD;
    for (int i=0; i<=n; i++) sum[i] = (sum[i-1] + p10[i] * fak[n-i-2] % MOD * inv[k-1] % MOD * inv[n-k-i-1]) % MOD;

    LL ans = 0;
    FOR (i, 0, n) {
        int batas = n - max(i+1, k) - 1;
        LL base = s[i] - '0';
        ans += base * sum[batas];
        if (i >= k) ans += base * fak[i] * inv[k] % MOD * inv[i-k] % MOD * p10[n-i-1];
        ans %= MOD;
        //cout << ans << endl;
    }

    printf("%I64d\n", ans);

    return 0;
}