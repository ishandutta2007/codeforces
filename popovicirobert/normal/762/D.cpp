#include <bits/stdc++.h>
#define MAXN 100000
#define INF 1000000000000000LL

using namespace std;


long long mat[4][MAXN + 1];
long long dp[4][MAXN + 1];

int main() {
  //  fstream cin("A.in");
   // ofstream cout("A.out");
    int i, j, n;
    ios::sync_with_stdio(false);
    cin >> n;
    for(i = 1; i <= 3; i++)
        for(j = 1; j <= n; j++)
           cin >> mat[i][j];
    dp[1][1] = mat[1][1];
    dp[2][1] = mat[2][1] + dp[1][1];
    dp[3][1] = mat[3][1] + dp[2][1];
    dp[2][0] = dp[3][0] = -INF;
    for(i = 2; i <= n; i++) {
        dp[1][i] = dp[2][i] = dp[3][i] = -INF;
        dp[1][i] = max(dp[1][i - 1] + mat[1][i], max(dp[2][i - 1] + mat[1][i] + mat[2][i], max(dp[3][i - 1] + mat[1][i] + mat[2][i] + mat[3][i], dp[3][i - 2] + mat[3][i - 1] + mat[3][i] + mat[2][i] + mat[1][i] + mat[1][i - 1] + mat[2][i - 1])));
        dp[2][i] = max(dp[2][i - 1] + mat[2][i], max(dp[1][i - 1] + mat[1][i] + mat[2][i], dp[3][i - 1] + mat[3][i] + mat[2][i]));
        dp[3][i] = max(dp[3][i - 1] + mat[3][i], max(dp[2][i - 1] + mat[2][i] + mat[3][i], max(dp[1][i - 1] + mat[1][i] + mat[2][i] + mat[3][i], dp[1][i - 2] + mat[1][i - 1] + mat[1][i] + mat[2][i] + mat[3][i] + mat[2][i - 1] + mat[3][i - 1])));
    }
    cout << dp[3][n];
   // cin.close();
  //  cout.close();
    return 0;
}