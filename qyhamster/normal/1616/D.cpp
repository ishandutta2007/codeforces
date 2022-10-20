#include <bits/stdc++.h>
#define pii pair<long long, long long>
#define int long long
using namespace std;
const int maxn = 1e5 + 10;
const double eps = 1e-10;
int a[maxn], dp[maxn][3];
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        for(int i = 1; i <= n; i++) cin >> a[i];
        int x;
        cin >> x;
        for(int i = 1; i <= n; i++) a[i] -= x;
        a[0] = 0;
        for(int i = 0; i <= n; i++) dp[i][0] = dp[i][1] = dp[i][2] = -1e9;
        dp[0][0] = 0;
        if(a[1] >= 0) {
            dp[1][0] = 1;
            dp[1][2] = 0;
        }
        else {
            dp[1][0] = 0;
            dp[1][1] = 1;
        }
        for(int i = 2; i <= n; i++) {
            if(a[i] >= 0) {
                if(a[i-1] >= 0) {
                    dp[i][0] = max(dp[i-1][2], max(dp[i-1][0], dp[i-1][1])) + 1;
                    dp[i][2] = max(dp[i-1][2], max(dp[i-1][0], dp[i-1][1]));
                }
                else {
                    if(a[i]+a[i-1] >= 0) dp[i][1] = dp[i-1][1] + 1;
                    dp[i][0] = dp[i-1][0] + 1;
                    dp[i][2] = max(dp[i-1][2], max(dp[i-1][0], dp[i-1][1]));
                }
            }
            else {
                if(a[i-1] >= 0) {
                    dp[i][0] = max(dp[i-1][2], max(dp[i-1][0], dp[i-1][1]));
                    dp[i][1] = dp[i-1][2] + 1;
                    if(a[i] + a[i-1] >= 0) dp[i][1] = max(dp[i][1], dp[i-1][0] + 1);
                    if(a[i] + a[i-1] + a[i-2] >= 0) dp[i][1] = max(dp[i][1], dp[i-1][1] + 1);
                }
                else {
                    dp[i][0] = max(dp[i-1][2], max(dp[i-1][0], dp[i-1][1]));
                    dp[i][1] = dp[i-1][0] + 1;
                }
            }
        }
        cout << max(max(dp[n][0], dp[n][1]), dp[n][2]) << endl;
    }
    return 0;
}