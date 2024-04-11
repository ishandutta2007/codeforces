#include <iostream>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <map>
#define mod 1000003
#define pi acos(-1)
using namespace std;

long long n, m, k, c[111], dp[111][111][111], cost[111][111], best[111][111][2];

long long findBest(int x, int y, int z) {
    if (best[x][y][0] == z) return dp[x][y][best[x][y][1]];
    else return dp[x][y][best[x][y][0]];
}

int main() {
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) cin >> c[i];
    for (int i = 0; i < n; i++) 
        for (int j = 1; j <= m; j++) cin >> cost[i][j];
    memset(dp, 25, sizeof(dp));
    long long old = dp[0][0][0];
    if (c[0]) {
        dp[0][1][c[0]] = 0;
        best[0][1][0] = c[0];
    }
    else {
        for (int i = 1; i <= m; i++) {
            dp[0][1][i] = cost[0][i];
            if (dp[0][1][i] < dp[0][1][best[0][1][0]]) {
                best[0][1][1] = best[0][1][0];
                best[0][1][0] = i;
            } else if (dp[0][1][i] < dp[0][1][best[0][1][1]]) {
                best[0][1][1] = i;
            }
        }
    }
    for (int i = 1; i < n; i++) for (int j = 1; j <= i + 1; j++) {
        if (c[i]) {
            dp[i][j][c[i]] = min(findBest(i-1, j-1, c[i]), dp[i-1][j][c[i]]);
            best[i][j][0] = c[i];
        } else {
            for (int kk = 1; kk <= m; kk++) {
                dp[i][j][kk] = cost[i][kk] + min(findBest(i-1, j-1, kk), dp[i-1][j][kk]);
                if (dp[i][j][kk] < dp[i][j][best[i][j][0]]) {
                    best[i][j][1] = best[i][j][0];
                    best[i][j][0] = kk;
                } else if (dp[i][j][kk] < dp[i][j][best[i][j][1]]) {
                    best[i][j][1] = kk;
                }
            }
        }
    }
    if (old == dp[n-1][k][best[n-1][k][0]]) cout << -1;
    else cout << dp[n-1][k][best[n-1][k][0]];
}