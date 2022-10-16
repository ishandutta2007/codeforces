#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define FOR(i, a, b) for (int (i) = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for (int (i) = (a); (i) >= (b); (i)--)
#define REP(i, n) FOR(i, 0, (n)-1)
#define all(x) (x).begin(), (x).end()
#define reset(x, y) memset(x, y, sizeof(x))
#define uni(x) (x).erase(unique(all(x)), (x).end());
#define BUG(x) cerr << #x << " = " << (x) << endl
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define _1 first
#define _2 second

const int maxa = 1e6;
const int MOD = 1e9 + 7;

int vis[maxa + 123];
ll fac[maxa + 123], ifac[maxa + 123];

ll pow_mod(ll a, ll k) {
    ll ret = 1;
    while (k) {
        if (k & 1) ret = ret * a % MOD;
        a = a * a % MOD;
        k >>= 1;
    }
    return ret;
}

ll C(ll n, ll m) {
    return fac[n] * ifac[n - m] % MOD * ifac[m] % MOD;
}

ll inv(ll a) {
    return pow_mod(a, MOD - 2);
}

int main() {
    FOR(i, 2, maxa) if (!vis[i]) {
            vis[i] = i;
            for (ll j = ll(i) * i; j <= maxa; j += i) vis[j] = i;
        }
    fac[0] = 1;
    FOR(i, 1, maxa + 100) fac[i] = fac[i - 1] * i % MOD;
    REP(i, maxa + 101) ifac[i] = inv(fac[i]);
    int q, x, y;
    scanf("%d", &q);
    while (q--) {
        scanf("%d%d", &x, &y);
        map<int, int> cnt;
        while (vis[x]) {
            cnt[vis[x]]++;
            x /= vis[x];
        }
        ll ans = 1;
        for (auto it : cnt)
            ans = ans * C(y + it._2 - 1, it._2) % MOD;
        ans = ans * pow_mod(2, y - 1) % MOD;
        printf("%lld\n", ans);
    }
    return 0;
}