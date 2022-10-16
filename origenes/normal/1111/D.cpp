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

const ll MOD = 1e9 + 7;
const int maxn = 112345;

ll fac[maxn << 1], inv[maxn << 1], ifac[maxn << 1], dp[maxn >> 1], dp2[maxn >> 1], cnt[55], ans[55][55];
char s[maxn];

inline int idx(char ch) {
    return islower(ch) ? ch - 'a' + 1 : ch - 'A' + 27;
}

int main() {
    scanf("%s", s + 1);
    fac[0] = fac[1] = 1;
    inv[0] = inv[1] = 1;
    ifac[0] = ifac[1] = 1;
    FOR(i, 2, 2e5 + 123) {
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = (MOD - MOD / i) * inv[MOD % i] % MOD;
        ifac[i] = ifac[i - 1] * inv[i] % MOD;
    }
    int n = strlen(s + 1), m;
    FOR(i, 1, n) cnt[idx(s[i])]++;
    dp[0] = 1;
    n >>= 1;
    FOR(i, 1, 52) if (cnt[i]) ROF(j, n, cnt[i]) dp[j] = (dp[j] + dp[j - cnt[i]]) % MOD;
    ll fsqr = sqr(fac[n]) % MOD;
    FOR(i, 1, 52) fsqr = fsqr * ifac[cnt[i]] % MOD;
    FOR(i, 1, 52) FOR(j, 1, 52) {
            memcpy(dp2, dp, sizeof(dp));
            if (cnt[i]) FOR(k, cnt[i], n) dp2[k] = (dp2[k] - dp2[k - cnt[i]] + MOD) % MOD;
            if (i != j && cnt[j]) FOR(k, cnt[j], n) dp2[k] = (dp2[k] - dp2[k - cnt[j]] + MOD) % MOD;
            ans[i][j] = dp2[n];
        }
    scanf("%d", &m);
    while (m--) {
        int x, y;
        scanf("%d%d", &x, &y);
        printf("%lld\n", 2 * fsqr * ans[idx(s[x])][idx(s[y])] % MOD);
    }
}