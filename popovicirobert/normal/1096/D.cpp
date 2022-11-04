#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define ld long double
// 217
// 44

using namespace std;

const ll INF = 1e18;
const int MAXN = (int) 1e5;

ll dp[MAXN + 1][5];
int a[MAXN + 1];

char str[MAXN + 1];

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, j, n;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n;
    cin >> str + 1;
    for(i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for(i = 1; i <= 4; i++) {
        dp[0][i] = INF;
    }
    for(i = 1; i <= n; i++) {
        if(str[i] == 'h') {
            dp[i][0] = dp[i - 1][0] + a[i];
            dp[i][1] = min(dp[i - 1][1], dp[i - 1][0]);
            dp[i][2] = dp[i - 1][2];
            dp[i][3] = dp[i - 1][3];
            dp[i][4] = dp[i - 1][4];
        }
        else if(str[i] == 'a') {
            dp[i][0] = dp[i - 1][0];
            dp[i][1] = dp[i - 1][1] + a[i];
            dp[i][2] = min(dp[i - 1][2], dp[i - 1][1]);
            dp[i][3] = dp[i - 1][3];
            dp[i][4] = dp[i - 1][4];
        }
        else if(str[i] == 'r') {
            dp[i][0] = dp[i - 1][0];
            dp[i][1] = dp[i - 1][1];
            dp[i][2] = dp[i - 1][2] + a[i];
            dp[i][3] = min(dp[i - 1][3], dp[i - 1][2]);
            dp[i][4] = dp[i - 1][4];
        }
        else if(str[i] == 'd') {
            dp[i][0] = dp[i - 1][0];
            dp[i][1] = dp[i - 1][1];
            dp[i][2] = dp[i - 1][2];
            dp[i][3] = dp[i - 1][3] + a[i];
            dp[i][4] = min(dp[i - 1][4], dp[i - 1][3]);
        }
        else {
            for(j = 0; j <= 4; j++) {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    ll ans = INF;
    for(i = 0; i < 4; i++) {
        ans = min(ans, dp[n][i]);
    }
    if(dp[n][4] >= INF) {
        ans = 0;
    }
    cout << ans;
    //cin.close();
    //cout.close();
    return 0;
}