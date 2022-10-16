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

const int maxn = 1234;
const ll MOD = 998244353;

int n, a[maxn];
ll dp[maxn], C[maxn][maxn];

int main() {
    REP(i, maxn) {
        C[i][0] = C[i][i] = 1;
        FOR(j, 1, i - 1) C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
    }
    scanf("%d", &n);
    REP(i, n) scanf("%d", &a[i]);
    dp[n] = 1;
    ROF(i, n - 1, 0) {
        if (a[i] <= 0) continue;
        FOR(j, i + a[i] + 1, n) dp[i] = (dp[i] + dp[j] * C[j - i - 1][a[i]]) % MOD;
    }
    ll ans = 0;
    REP(i, n) ans = (ans + dp[i]) % MOD;
    printf("%lld\n", ans);
    return 0;
}