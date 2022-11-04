#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
// 217
// 44

using namespace std;

const int MAXN = 2005;

int v[MAXN + 1];

int sl[MAXN + 1][3], sr[MAXN + 1][3];

int dp[MAXN + 1][MAXN + 1];

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, j, n;
    ios::sync_with_stdio(false);
    cin >> n;
    for(i = 1; i <= n; i++) {
        cin >> v[i];
    }
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= 2; j++)
            sl[i][j] = sl[i - 1][j];
        sl[i][v[i]]++;
    }
    for(i = n; i >= 1; i--) {
        for(j = 1; j <= 2; j++)
            sr[i][j] = sr[i + 1][j];
        sr[i][v[i]]++;
    }
    for(i = 1; i < n; i++) {
        dp[i][i + 1] = sl[i][2] + sr[i + 1][1];
    }
    for(int len = 2; len <= n; len++) {
        for(i = 1; i + len <= n; i++) {
            dp[i][i + len] = max(dp[i][i + len - 1], sl[i + len - 1][2] + sr[i + len][1]);
        }
    }
    int ans = 0;
    for(i = 0; i <= n; i++) {
        ans = max(ans, sl[i][1] + sr[i + 1][2]);
    }
    for(i = 1; i <= n; i++) {
        for(j = i + 1; j <= n; j++) {
            ans = max(ans, dp[i][j] + sl[i - 1][1] + sr[j + 1][2] - sl[i - 1][2] - sr[j + 1][1]);
        }
    }
    cout << ans;
    //cin.close();
    //cout.close();
    return 0;
}