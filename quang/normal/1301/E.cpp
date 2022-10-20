#include <bits/stdc++.h>

using namespace std;

const int N = 510;
const int Q = 300010;

int n, m, q;
char a[N][N];
int res[Q];
int maxColor[N][N];
int dp[N][N];
int maxSquare[N][N];

struct Query {
    int r1, c1, r2, c2;
} queries[Q];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++) {
        cin >> (a[i] + 1);
    }
    for (int i = 1; i <= q; i++) {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        queries[i] = {r1, c1, r2, c2};
    }
    for (int i = n; i >= 1; i--) {
        for (int j = m; j >= 1; j--) {
            if (i == n || j == m) maxColor[i][j] = 1;
            else {
                int now = min(maxColor[i][j + 1], min(maxColor[i + 1][j], maxColor[i + 1][j + 1]));
                if (a[i][j] == a[i + 1][j] && a[i][j] == a[i][j + 1] && a[i][j] == a[i + 1][j + 1]) maxColor[i][j] = now + 1;
                else maxColor[i][j] = 1;
            }
        }
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (a[i][j] != 'R') continue;
            int ii = i + maxColor[i][j];
            int jj = j + maxColor[i][j];
            if (ii > n || jj > m) continue;
            if (a[ii][j] != 'Y' || maxColor[ii][j] < maxColor[i][j]) continue;
            if (a[i][jj] != 'G' || maxColor[i][jj] < maxColor[i][j]) continue;
            if (a[ii][jj] != 'B' || maxColor[ii][jj] < maxColor[i][j]) continue;
            maxSquare[ii - 1][jj - 1] = max(maxSquare[ii - 1][jj - 1], maxColor[i][j]);
        }
    }
    for (int i = 1; i <= n; i++) {
        memset(dp, 0, sizeof dp);
        for (int j = 1; j <= m; j++) {
            if (maxSquare[i][j] == 0) continue;
            int l = j - maxSquare[i][j] + 1;
            int r = j + maxSquare[i][j];
            while (l <= r) {
                dp[l][r] = (r - l + 1) / 2;
                l++;
                r--;
            }
        }
        for (int len = 2; len <= m; len++) {
            for (int l = 1; l + len - 1 <= m; l++) {
                int r = l + len - 1;
                dp[l][r] = max(dp[l][r], dp[l + 1][r]);
                dp[l][r] = max(dp[l][r], dp[l][r - 1]);
            }
        }

        for (int j = 1; j <= q; j++) {
            int len = dp[queries[j].c1][queries[j].c2];
            int now = len;
            now = min(now, i - queries[j].r1 + 1);
            now = min(now, queries[j].r2 - i);
            res[j] = max(res[j], now);
        }
    }
    for (int i = 1; i <= q; i++) {
        cout << res[i] * res[i] * 4 << '\n';
    }
    return 0;
}