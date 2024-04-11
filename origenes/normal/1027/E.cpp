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
#define mp make_pair
#define _1 first
#define _2 second

const int maxn = 512;
const int MOD = 998244353;

int n, K, ans, dp[2][maxn][maxn], s[maxn], tot[maxn];

inline void upd(int& a, int b) {
    (a += b) < MOD ? : a -= MOD;
}

int main() {
    scanf("%d%d", &n, &K);
    dp[0][0][0] = 1;
    int now = 1, p = 0;
    REP(i, n) {
        reset(dp[now], 0);
        REP(j, n + 1) REP(k, n + 1) {
                upd(dp[now][j + 1][max(j + 1, k)], dp[p][j][k]);
                upd(dp[now][1][max(1, k)], dp[p][j][k]);
            }
        now ^= 1;
        p ^= 1;
    }
    REP(i, n + 1) REP(j, n + 1) upd(s[i], dp[n & 1][j][i]);
    REP(i, n + 1) {
        upd(tot[i + 1], tot[i]);
        upd(tot[i + 1], s[i]);
    }
    FOR(i, 1, n) upd(ans, s[i] * ll(tot[min(n + 1, (K - 1) / i + 1)]) % MOD);
    ans = ans * ll((MOD + 1) / 2) % MOD;
    printf("%d\n", ans);
    return 0;
}