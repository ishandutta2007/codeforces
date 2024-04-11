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

const int maxn = 2123;
const ll MOD = 998244353;

ll dp[maxn][maxn];
int n, m, k;

int main() {
    scanf("%d%d%d", &n, &m, &k);
    dp[1][0] = m;
    FOR(i, 2, n) REP(j, k + 1) {
            if (j) dp[i][j] = dp[i - 1][j - 1] * (m - 1) % MOD;
            dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD;
        }
    printf("%lld", dp[n][k]);
}