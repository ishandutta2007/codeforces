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

const int maxn = 1123456;
const int MOD = 1e9 + 7;

ll fac[maxn], ifac[maxn];
int n, m, _a, _b;

ll C(int n, int m) {
    if (m < 0 || m > n) return 0;
    return fac[n] * ifac[m] % MOD * ifac[n - m] % MOD;
}

ll pow_mod(ll a, ll k) {
    ll ret = 1;
    while (k) {
        if (k & 1) ret = ret * a % MOD;
        a = a * a % MOD;
        k >>= 1;
    }
    return ret;
}

ll get(int n, int m) {
    ll ret;
    if (m + 1 > n) ret = pow_mod(n, MOD - 2);
    else ret = pow_mod(n, n - m - 1);
    return ret * m % MOD;
}

int main() {
    scanf("%d%d%d%d", &n, &m, &_a, &_b);
    fac[0] = fac[1] = ifac[0] = ifac[1] = 1;
    FOR(i, 2, max(n, m)) {
        fac[i] = fac[i - 1] * i % MOD;
        ifac[i] = pow_mod(fac[i], MOD - 2);
    }
//    REP(i, max(n, m) + 1) assert(fac[i] * ifac[i] % MOD == 1);
    ll ans = 0;
    FOR(i, 1, n - 1) {
        ll now = fac[n - 2] * ifac[n - i - 1] % MOD * C(m - 1, i - 1) % MOD * pow_mod(m, n - i - 1) % MOD * (i + 1) % MOD;
        if (i == n - 1) now = now * pow_mod(n, MOD - 2);
        else now = now * pow_mod(n, n - i - 2);
        ans = (ans + now) % MOD;
//        BUG(now);
    }
    printf("%lld", ans);
}