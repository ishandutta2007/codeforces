#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define FOR(i, a, b) for (int (i) = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for (int (i) = (a); (i) >= (b); (i)--)
#define REP(i, n) FOR(i, 0, (n)-1)
#define sqr(x) ((x) * (x))
#define all(x) (x).begin(), (x).end()
#define reset(x, y) memset(x, y, sizeof(x))
#define uni(x) (x).erase(unique(all(x)), (x).end());
#define BUG(x) cerr << #x << " = " << (x) << endl
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define _1 first
#define _2 second

const ll MOD = 998244353;
const int maxn = 1123456;

ll inv(ll a) {
    ll p = MOD - 2, ret = 1;
    while (p) {
        if (p & 1) ret = ret * a % MOD;
        a = a * a % MOD;
        p >>= 1;
    }
    return ret;
}

ll fac[maxn], ifac[maxn], ans;
int n;

int main() {
    scanf("%d", &n);
    fac[0] = 1;
    FOR(i, 1, n) fac[i] = fac[i - 1] * i % MOD;
    ifac[n] = inv(fac[n]);
    ROF(i, n, 1) ifac[i - 1] = ifac[i] * i % MOD;
    FOR(i, 2, n - 1) ans = (ans + fac[n] * ifac[i] % MOD * (fac[i] - 1)) % MOD;
    ans = (ans + fac[n]) % MOD;
    if (ans < 0) ans += MOD;
    printf("%lld", ans);
}