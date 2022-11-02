#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; i ++)
#define pii pair<int, int>
using namespace std;
const int INF = INT_MAX / 10;
int dp[31][31][51];
int main() 
{
    for (int r = 1; r <= 30; r ++) 
        for (int c = 1; c <= 30; c ++) 
            for (int k = 0; k <= 50; k ++) 
            {
                dp[r][c][k] = INF;
                if (r * c < k) dp[r][c][k] = INF;
                else if (k == 0) dp[r][c][k] = 0;
                else if (r * c == k) dp[r][c][k] = 0;
                else 
                {
                    for (int R = 1; R < r; R ++) 
                        for (int K = 0; K <= k; K ++)
                            dp[r][c][k] = min(dp[r][c][k], dp[R][c][K] + dp[r - R][c][k - K] + c * c);
                    for (int C = 1; C < c; C ++) 
                        for (int K = 0; K <= k; K ++)
                            dp[r][c][k] = min(dp[r][c][k], dp[r][C][K] + dp[r][c - C][k - K] + r * r);
                }
            }
    int T, n, m, k;
    scanf("%d", &T);
    FOR(tt, T) 
    {
        scanf("%d %d %d", &n, &m, &k);
        printf("%d\n", dp[n][m][k]);
    }
    return 0;
}