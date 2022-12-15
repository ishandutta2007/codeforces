#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i = a; i <= b; i++)
#define FORD(i,a,b) for (int i = a; i >= b; i--)
#define REP(i,a) for (int i = 0; i < a; i++)
#define reset(a,b) memset(a,b,sizeof(a))
#define BUG(x) cout << #x << " = " << x << endl
#define mod 1000000007
#define eps 0.00000001
#define sqr(x) (x) * (x)
#define pb push_back

int n;
long long dp[4][2222][2222], x, y, xx, yy, lis[2222][2222], ans[2222][2222];

int main() {
    ios::sync_with_stdio(0);
    cin >> n;
    REP (i, n) REP (j, n) cin >> lis[i][j];
    REP (i, n) REP (j, n) {
        if (i && j) {
            dp[0][i][j] = dp[0][i - 1][j - 1] + lis[i - 1][j - 1];
            dp[1][i][n - 1 - j] = dp[1][i - 1][n - j] + lis[i - 1][n - j];
            dp[2][n - 1 - i][j] = dp[2][n - i][j - 1] + lis[n - i][j - 1];
            dp[3][n - 1 - i][n - 1 - j] = dp[3][n - i][n - j] + lis[n - i][n - j];
        }
    }
    xx = 1;
    REP (i, n) REP (j, n) {
        long long tmp = lis[i][j];
        REP (k, 4) tmp += dp[k][i][j];
        ans[i][j] = tmp;
        if ((i + j) & 1) {
            if (tmp > ans[x][y]) {
                x = i;
                y = j;
            }
        } 
        else {
            if (tmp > ans[xx][yy]) {
                xx = i;
                yy = j;
            }
        }
    }
    cout << ans[x][y] + ans[xx][yy] << endl << x + 1 << ' ' << y + 1 << ' ' << xx + 1 << ' ' << yy + 1;
}