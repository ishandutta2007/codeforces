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

typedef pair<ll, ll> pll;

const int maxn = 25;
const ll MOD = 998244353;

int k, n, a[maxn];
pll dp[maxn][1 << 10][2][2];
bool vis[maxn][1 << 10][2][2];
ll pw[maxn];

int cnt_true(int x) {
    int ret = 0;
    while (x) ret += x & 1, x >>= 1;
    return ret;
}

pll operator + (const pll &lhs, const pll& rhs) {
    return mp((lhs._1 + rhs._1) % MOD, (lhs._2 + rhs._2) % MOD);
}

pll dfs(int pos, int mask, bool f1, bool f2) {
    auto &ans = dp[pos][mask][f1][f2];
    if (vis[pos][mask][f1][f2]) return ans;
    vis[pos][mask][f1][f2] = true;
    ans = mp(0LL, 0LL);
    int now = cnt_true(mask);
    if (now == k) {
        assert(f2);
        if (f1) {
            REP(d, 10) if (mask & (1 << d)) {
                    pll tmp = pos == n ? mp(1LL, 0LL) : dfs(pos + 1, mask, true, true);
                    ans = ans + tmp;
                    ans._2 = (ans._2 + tmp._1 * pw[n - pos] % MOD * d % MOD) % MOD;
                }
        } else {
            REP(d, a[pos]) if (mask & (1 << d)) {
                    pll tmp = pos == n ? mp(1LL, 0LL) : dfs(pos + 1, mask, true, true);
                    ans = ans + tmp;
                    ans._2 = (ans._2 + tmp._1 * pw[n - pos] % MOD * d % MOD) % MOD;
                }
            if (mask & (1 << a[pos])) {
                pll tmp = pos == n ? mp(1LL, 0LL) : dfs(pos + 1, mask, false, true);
                ans = ans + tmp;
                ans._2 = (ans._2 + tmp._1 * pw[n - pos] % MOD * a[pos] % MOD) % MOD;
            }
        }
    } else {
        if (f2) {
            if (f1) {
                REP(d, 10) {
                    pll tmp = pos == n ? mp(1LL, 0LL) : dfs(pos + 1, mask | (1 << d), true, true);
                    ans = ans + tmp;
                    ans._2 = (ans._2 + tmp._1 * pw[n - pos] % MOD * d % MOD) % MOD;
                }
            } else {
                REP(d, a[pos]) {
                    pll tmp = pos == n ? mp(1LL, 0LL) : dfs(pos + 1, mask | (1 << d), true, true);
                    ans = ans + tmp;
                    ans._2 = (ans._2 + tmp._1 * pw[n - pos] % MOD * d % MOD) % MOD;
                }
                pll tmp = pos == n ? mp(1LL, 0LL) : dfs(pos + 1, mask | (1 << a[pos]), false, true);
                ans = ans + tmp;
                ans._2 = (ans._2 + tmp._1 * pw[n - pos] % MOD * a[pos] % MOD) % MOD;
            }
        } else {
            assert(!mask);
            if (f1) {
                if (pos != n) ans = ans + dfs(pos + 1, 0, true, false);
                FOR(d, 1, 9) {
                    pll tmp = pos == n ? mp(1LL, 0LL) : dfs(pos + 1, 1 << d, true, true);
                    ans = ans + tmp;
                    ans._2 = (ans._2 + tmp._1 * pw[n - pos] % MOD * d % MOD) % MOD;
                }
            } else {
                if (pos != n) ans = ans + dfs(pos + 1, 0, true, false);
                FOR(d, 1, a[pos] - 1) {
                    pll tmp = pos == n ? mp(1LL, 0LL) : dfs(pos + 1, 1 << d, true, true);
                    ans = ans + tmp;
                    ans._2 = (ans._2 + tmp._1 * pw[n - pos] % MOD * d % MOD) % MOD;
                }
                pll tmp = pos == n ? mp(1LL, 0LL) : dfs(pos + 1, 1 << a[pos], false, true);
                ans = ans + tmp;
                ans._2 = (ans._2 + tmp._1 * pw[n - pos] % MOD * a[pos] % MOD) % MOD;
            }
        }
    }
    return ans;
}

int conv(ll x) {
    reset(a, 0);
    vector<int> v;
    while (x) {
        v.pb(x % 10);
        x /= 10;
    }
    reverse(all(v));
    int len = v.size();
    REP(i, len) a[i + 1] = v[i];
    return len;
}

ll solve(ll x) {
    n = conv(x);
    if (!n) return 0;
    reset(vis, false);
    return dfs(1, 0, false, false)._2;
}

ll l, r;

int main() {
    scanf("%lld%lld%d", &l, &r, &k);
    pw[0] = 1;
    FOR(i, 1, 20) pw[i] = pw[i - 1] * 10 % MOD;
    l--;
    printf("%lld\n", ((solve(r) - solve(l)) % MOD + MOD) % MOD);
    return 0;
}