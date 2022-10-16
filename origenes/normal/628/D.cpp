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

const int maxn = 2123;
const int MOD = 1e9 + 7;

int m, d;
ll dp[maxn][maxn][2];

inline void upd(ll &a, ll b) {
    (a += b) >= MOD ? a -= MOD : 0;
}

ll solve(const char *a, int n) {
    reset(dp, 0);
    dp[0][0][1] = 1;
    REP(i, n) REP(j, m) REP(f, 2) REP(dig, f ? a[i] + 1 : 10) {
                    if ((i & 1) && dig != d) continue;
                    if (((i & 1) ^ 1) && dig == d) continue;
                    if (!i && !dig) continue;
                    upd(dp[i + 1][(j * 10 + dig) % m][f && (dig == a[i])], dp[i][j][f]);
                }
    return (dp[n][0][0] + dp[n][0][1]) % MOD;
}

bool check(const char * a, int n) {
    int cur = 0;
    REP(i, n) {
        if ((i & 1) && a[i] != d) return false;
        if (((i & 1) ^ 1) && a[i] == d) return false;
        cur = (cur * 10 + a[i]) % m;
    }
    return !cur;
}

char a[maxn], b[maxn];

int main() {
    scanf("%d%d", &m, &d);
    scanf("%s%s", a, b);
    int n = strlen(a);
    REP(i, n) {
        a[i] -= '0';
        b[i] -= '0';
    }
    ll ans = solve(b, n) - solve(a, n) + check(a, n);
    printf("%lld\n", (ans % MOD + MOD) % MOD);
    return 0;
}