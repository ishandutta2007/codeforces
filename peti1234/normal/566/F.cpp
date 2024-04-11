#include <bits/stdc++.h>

using namespace std;
const int c=1000002;
int n, dp[c], ans;
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0);
    cin >> n;
    for (int i=1; i<=n; i++) {
        int x; cin >> x;
        dp[x]++, ans=max(ans, dp[x]);
        for (int j=2*x; j<c; j+=x) {
            dp[j]=max(dp[j], dp[x]);
        }
    }
    cout << ans << "\n";
    return 0;
}