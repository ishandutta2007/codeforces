#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define ld long double
// 217
// 44

using namespace std;

const int MAXN = 500;

int dp[MAXN + 1][MAXN + 1][2];
int best[MAXN + 1];

char str[MAXN + 1];

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, j, n;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> str + 1;
    for(i = 1; i <= n; i++) {
        for(j = i + 1; j <= n; j++) {
            dp[i][j][0] = dp[i][j][1] = n + 1;
        }
    }
    for(i = 1; i <= n; i++) {
        dp[i][i][0] = dp[i][i][1] = 1;
    }
    for(int len = 1; len < n; len++) {
        for(int l = 1; l + len <= n; l++) {
            int r = l + len;
            for(i = l; i < r; i++) {
                for(int a = 0; a < 2; a++) {
                    char ch1;
                    if(a == 0) {
                        ch1 = str[l];
                    }
                    else {
                        ch1 = str[i];
                    }
                    for(int b = 0; b < 2; b++) {
                        char ch2;
                        if(b == 0) {
                            ch2 = str[i + 1];
                        }
                        else {
                            ch2 = str[r];
                        }
                        dp[l][r][a] = min(dp[l][r][a], dp[l][i][a] + dp[i + 1][r][b] - (ch1 == ch2));
                        dp[l][r][b] = min(dp[l][r][b], dp[l][i][a] + dp[i + 1][r][b] - (ch1 == ch2));
                    }
                }
            }
        }
    }
    cout << min(dp[1][n][0], dp[1][n][1]);
    //cin.close();
    //cout.close();
    return 0;
}