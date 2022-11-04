#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define ld long double
// 217
// 44

using namespace std;

const ll INF = 1e18;
const int MAXN = 100;

int arr[MAXN + 1];
char str[MAXN + 1];

ll dp[MAXN + 1][MAXN + 1][MAXN + 1][2];

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> str + 1;
    for(i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    for(int a = 1; a <= n; a++) {
        for(int b = a; b <= n; b++) {
            for(int c = 0; c <= n; c++) {
                dp[a][b][c][0] = dp[a][b][c][1] = -INF;
            }
        }
    }
    for(i = 1; i <= n; i++) {
        str[i] -= '0';
        dp[i][i][0][0] = dp[i][i][0][1] = arr[1];
        dp[i][i][1][str[i]] = 0;
    }
    for(int len = 1; len < n; len++) {
        for(int l = 1; l + len <= n; l++) {
            int r = l + len;
            for(int k = 0; k <= len + 1; k++) {
                if(k > 0) {
                    if(str[l] == 0) {
                        dp[l][r][k][0] = dp[l + 1][r][k - 1][0];
                    }
                    else {
                        dp[l][r][k][1] = dp[l + 1][r][k - 1][1];
                    }
                }
                for(i = l; i < r; i++) {
                    dp[l][r][k][0] = max(dp[l][r][k][0], dp[l][i][0][0] + dp[i + 1][r][k][0]);
                    dp[l][r][k][1] = max(dp[l][r][k][1], dp[l][i][0][1] + dp[i + 1][r][k][1]);
                }
                dp[l][r][0][0] = max(dp[l][r][0][0], dp[l][r][k][0] + arr[k]);
                dp[l][r][0][1] = max(dp[l][r][0][1], dp[l][r][k][1] + arr[k]);
            }
            ll mx = max(dp[l][r][0][0], dp[l][r][0][1]);
            dp[l][r][0][0] = dp[l][r][0][1] = mx;
            /*for(int k = 0; k <= len + 1; k++) {
                cerr << l << " " << r << " " << k << " " << dp[l][r][k][0] << " " << dp[l][r][k][1] << "\n";
            }
            cerr << "\n";*/
        }
    }
    cout << dp[1][n][0][0];
    //cin.close();
    //cout.close();
    return 0;
}