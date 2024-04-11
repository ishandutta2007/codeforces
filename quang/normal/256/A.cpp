#include <bits/stdc++.h>
#define fi freopen("inp.txt", "r", stdin)
#define fo freopen("out.txt", "w", stdout)

using namespace std;

const int N = 4001;

int n, ans = 0;
int b[N], dp[N][N];

int main() {
    ios_base::sync_with_stdio(0);
    //fi, fo;
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> b[i];
    for(int i = 1; i <= n; i++)
    for(int j = 0, k = 0; j < i; j++) {
        dp[i][j] = dp[j][k] + 1;
        if(b[i] == b[j]) k = j;
        ans = max(ans, dp[i][j]);
    }
    cout << ans;
    return 0;
}