#include <bits/stdc++.h>
#define fi freopen("inp.txt", "r", stdin)
#define fo freopen("out.txt", "w", stdout)

using namespace std;

const int N = 3030;

int n;
int a[N], b[N], c[N];
int dp[N][2];

int main() {
    ios_base::sync_with_stdio(0);
    //fi, fo;
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) cin >> b[i];
    for(int i = 1; i <= n; i++) cin >> c[i];
    dp[1][0] = a[1], dp[1][1] = b[1];
    for(int i = 2; i <= n; i++) {
        dp[i][0] = max(a[i] + dp[i - 1][1], b[i] + dp[i - 1][0]);
        dp[i][1] = max(b[i] + dp[i - 1][1], c[i] + dp[i - 1][0]);
    }
    cout << dp[n][0];
    return 0;
}