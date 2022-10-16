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

const int maxp = 55;
const int maxk = 11234;
const ll MOD = 1e9 + 7;

ll n, ans = 1, dp[maxk][maxp], inv[maxp];
int k;
map<ll, int> pfac;

ll pow_mod(ll b, ll k) {
    ll ret = 1;
    while (k) {
        if (k & 1) ret = ret * b % MOD;
        b = b * b % MOD;
        k >>= 1;
    }
    return ret;
}

int main() {
    inv[0] = inv[1] = 1;
    FOR(i, 2, 54) inv[i] = pow_mod(i, MOD - 2);
    scanf("%lld%d", &n, &k);
    for (ll i = 2; i * i <= n; i++) if (n % i == 0) {
            while (n % i == 0) n /= i, pfac[i]++;
        }
    if (n > 1) pfac[n]++;
    for (const auto &now : pfac) {
        reset(dp, 0);
        dp[0][now._2] = 1;
        REP(i, k) REP(j, now._2 + 1) {
                ll tmp = dp[i][j] * inv[j + 1] % MOD;
                REP(kk, j + 1) dp[i + 1][kk] = (dp[i + 1][kk] + tmp) % MOD;
            }
        ll cur = 0, tmp = 1;
        REP(i, now._2 + 1) {
            cur = (cur + tmp * dp[k][i]) % MOD;
            tmp = tmp * (now._1 % MOD) % MOD;
        }
        ans = ans * cur % MOD;
    }
    printf("%lld", ans);
}