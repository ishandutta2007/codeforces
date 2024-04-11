#include <bits/stdc++.h>

using namespace std;
const int c=100002, k=1000;
int dp[c], maxi[c], x[c], y[c], t[c], w, n, ans;
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0);
    cin >> w >> n, x[0]=1, y[0]=1;
    for (int i=1; i<=max(n, k); i++) dp[i]=-c;
    for (int i=1; i<=n; i++) cin >> t[i] >> x[i] >> y[i];
    for (int i=0; i<=n; i++) {
        if (i>=k) dp[i]=max(dp[i], maxi[i-k]+1);
        for (int j=i+1; j<=min(n, i+k); j++) {
            if (abs(x[j]-x[i])+abs(y[j]-y[i])<=t[j]-t[i]) dp[j]=max(dp[j], dp[i]+1);
        }
        if (i) maxi[i]=max(maxi[i-1], dp[i]);
        ans=max(ans, dp[i]);
    }
    cout << ans << "\n";
    return 0;
}