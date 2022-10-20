#include <bits/stdc++.h>

using namespace std;

const int N = 55;

int n;
char s[N][N];
int dp[N][N][N][N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> (s[i] + 1);
    }
    for (int lenX = 1; lenX <= n; lenX++) {
        for (int x = 1; x + lenX - 1 <= n; x++) {
            int xx = x + lenX - 1;

            for (int lenY = 1; lenY <= n; lenY++) {
                for (int y = 1; y + lenY - 1 <= n; y++) {
                    int yy = y + lenY - 1;

                    if (lenX == 1 && lenY == 1) {
                        dp[x][y][xx][yy] = (s[x][y] == '#');
                        continue;
                    }
                    dp[x][y][xx][yy] = max(lenX, lenY);

                    for (int mid = x; mid < xx; mid++) {
                        int cost = dp[x][y][mid][yy] + dp[mid + 1][y][xx][yy];
                        dp[x][y][xx][yy] = min(dp[x][y][xx][yy], cost);
                    }
                    for (int mid = y; mid < yy; mid++) {
                        int cost = dp[x][y][xx][mid] + dp[x][mid + 1][xx][yy];
                        dp[x][y][xx][yy] = min(dp[x][y][xx][yy], cost);
                    }
                }
            }
        }
    }
    cout << dp[1][1][n][n] << endl;
    return 0;
}