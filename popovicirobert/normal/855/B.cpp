#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 220
// 44

using namespace std;

const int MAXN = (int) 1e5;

ll arr[4];
ll dp[MAXN + 1][4];

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, j, n;
    ios::sync_with_stdio(false);
    cin >> n >> arr[1] >> arr[2] >> arr[3];
    for(i = 0; i <= n; i++) {
        for(j = 1; j <= 3; j++) {
            dp[i][j] = -6e18;
        }
    }
    for(i = 1; i <= n; i++) {
        ll x;
        cin >> x;
        dp[i][1] = max(dp[i - 1][1], arr[1] * x);
        dp[i][2] = max(dp[i - 1][2], max(dp[i - 1][1] + arr[2] * x, x * (arr[2] + arr[1])));
        dp[i][3] = max(dp[i - 1][3], max(dp[i - 1][2] + arr[3] * x, max(dp[i - 1][1] + x * (arr[3] + arr[2]), x * (arr[3] + arr[2] + arr[1]))));
        //cout << dp[i][1] << " " << dp[i][2] << " " << dp[i][3] << "\n";
    }
    cout << dp[n][3];
    //cin.close();
    //cout.close();
    return 0;
}