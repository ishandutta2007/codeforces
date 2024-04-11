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

const int maxs = 5123;
const ll MOD = 998244353;

ll fac[maxs << 1], ifac[maxs << 1];

ll pow_mod(ll x, ll k) {
    ll ret = 1;
    while (k) {
        if (k & 1) ret = ret * x % MOD;
        x = x * x % MOD;
        k >>= 1;
    }
    return ret;
}

ll inv(ll a) {
    return pow_mod(a, MOD - 2);
}

ll C(int n, int m) {
    if (n == m) return 1;
    if (m > n || m < 0) return 0;
    return fac[n] * ifac[m] % MOD * ifac[n - m] % MOD;
}

ll cal(int s, int p, int m) {
    ll ret = 0;
    REP(i, p + 1) {
        int sig = i & 1 ? -1 : 1;
        ll now = C(p, i) * C(s + p - 1 - (m + 1) * i, p - 1) % MOD;
        ret = (ret + sig * now) % MOD;
    }
    if (ret < 0) ret += MOD;
    return ret;
}

int p, s, r;
ll ans;

int main() {
    fac[0] = ifac[0] = 1;
    FOR(i, 1, maxs * 2 - 10) {
        fac[i] = fac[i - 1] * i % MOD;
        ifac[i] = inv(fac[i]);
    }
    scanf("%d%d%d", &p, &s, &r);
    FOR(i, r, s) FOR(j, 1, p) {
            ll now = C(p - 1, j - 1) * inv(j) % MOD * cal(s - j * i, p - j, i - 1) % MOD;
            ans = (ans + now) % MOD;
        }
    printf("%lld", ans * inv(C(s - r + p - 1, p - 1)) % MOD);
}