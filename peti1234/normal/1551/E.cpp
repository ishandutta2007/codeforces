#include <bits/stdc++.h>

using namespace std;
const int c=2005;
int w, n, k, t[c], dp[c];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n >> k;
        for (int i=1; i<=n; i++) {
            cin >> t[i];
        }
        int ans=c;
        for (int i=1; i<=n; i++) {
            dp[i]=-c;
            if (t[i]<=i) {
                dp[i]=1;
            }
            for (int j=1; j<i; j++) {
                if (t[i]>t[j] && i-j>=t[i]-t[j]) {
                    dp[i]=max(dp[i], dp[j]+1);
                }
            }
            if (dp[i]>=k) {
                ans=min(ans, i-t[i]);
            }
        }
        cout << (ans==c ? -1 : ans) << "\n";
    }
    return 0;
}