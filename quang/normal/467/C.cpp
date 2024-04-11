#include <bits/stdc++.h>
#define fi freopen("inp.txt", "r", stdin)
#define fo freopen("out.txt", "w", stdout)

using namespace std;

const int N = 5050;

int n, m, k;
long long s[N];
long long dp[N][N];

int main() {
    ios_base::sync_with_stdio(0);
   // fi, fo;
    cin >> n >> m >> k;
    s[0] = 0;
    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        s[i] = s[i - 1] + x;
    }
    for(int i = 1; i <= k; i++) {
        for(int j = 1; j <= n; j++) {
            dp[i][j] = max(dp[i][j], dp[i][j - 1]);
            if(j >= m) dp[i][j] = max(dp[i][j], dp[i - 1][j - m] + s[j] - s[j - m]);
        }
    }
    cout << dp[k][n];
    return 0;
}