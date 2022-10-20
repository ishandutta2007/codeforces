#include <bits/stdc++.h>
#define fi freopen("inp.txt", "r", stdin)
#define fo freopen("out.txt", "w", stdout)

using namespace std;

const int N = 2020;

int n, k;
long long dp[2][N];

int main() {
    ios_base::sync_with_stdio(0);
    //fi, fo;
    cin >> n >> k;
    for(int i = 1; i <= n; i++) dp[0][i] = 1;
    for(int t = 1; t < k; t++) {
        memset(dp[1], 0, sizeof(dp[1]));
        for(int i = 1; i <= n; i++)
            for(int j = i; j <= n; j += i)
                dp[1][j] = (dp[1][j] + dp[0][i]) % 1000000007;
        memcpy(dp[0], dp[1], sizeof(dp[0]));
    }
    long long res = 0;
    for(int i = 1; i <= n; i++)
        res = (res + dp[0][i]) % 1000000007 ;
    cout << res;
    return 0;
}