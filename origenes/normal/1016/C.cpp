#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define FOR(i, a, b) for (int (i) = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for (int (i) = (a); (i) >= (b); (i)--)
#define REP(i, n) FOR(i, 0, (n)-1)
#define all(x) (x).begin(), (x).end()
#define uni(x) (x).erase(unique(all(x)), (x).end());
#define BUG(x) cerr << #x << " = " << (x) << endl
#define pb push_back
#define mp make_pair
#define _1 first
#define _2 second

const int maxn = 312345;

int n;
ll ans = -1, mat[2][maxn], dp[2][maxn], suff[2][maxn], cs[2][maxn], invs[2][maxn];

void init() {
    memset(dp, -1, sizeof(dp));
    dp[0][1] = 0;
    REP(row, 2) {
        suff[row][n] = mat[row][n];
        ROF(col, n - 1, 0) suff[row][col] = suff[row][col + 1] + mat[row][col];
    }
    REP(row, 2) ROF(col, n - 1, 0) cs[row][col] = cs[row][col + 1] + suff[row][col + 1];
    REP(row, 2) {
        invs[row][n] = mat[row][n] * (2 * n - 1);
        ROF(col, n - 1, 0) invs[row][col] = invs[row][col + 1] - suff[row][col + 1] + mat[row][col] * (2 * n - 1);
    }
}

int main() {
    scanf("%d", &n);
    FOR(i, 1, n) scanf("%lld", &mat[0][i]);
    FOR(i, 1, n) scanf("%lld", &mat[1][i]);
    init();
    FOR(col, 1, n - 1) REP(row, 2) {
            if (dp[row][col] < 0) continue;
            dp[row ^ 1][col + 1] = max(dp[row ^ 1][col + 1], dp[row][col] + mat[row ^ 1][col] * (2 * col - 1) + mat[row ^ 1][col + 1] * 2 * col);
            ans = max(ans, dp[row][col] + suff[row][col + 1] * (2 * col - 1) + cs[row][col + 1] + invs[row ^ 1][col]);
        }
    if (dp[0][n] < 0) {
        ans = max(ans, dp[1][n] + invs[0][n]);
    } else {
        ans = max(ans, dp[0][n] + invs[1][n]);
    }
    printf("%lld\n", ans);
    return 0;
}