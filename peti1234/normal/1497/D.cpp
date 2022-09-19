#include <bits/stdc++.h>

using namespace std;
const int c=5002;
long long w, n, t[c], s[c], dp[c], maxi;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        for (int i=1; i<=n; i++) {
            cin >> t[i];
        }
        for (int i=1; i<=n; i++) {
            cin >> s[i];
        }
        maxi=0;
        for (int i=1; i<=n; i++) {
            dp[i]=0;
        }
        for (int i=1; i<=n; i++) {
            for (int j=i-1; j>=1; j--) {
                if (t[i]!=t[j]) {
                    long long f=dp[i];
                    dp[i]=max(dp[i], dp[j]+abs(s[i]-s[j]));
                    dp[j]=max(dp[j], f+abs(s[j]-s[i]));
                }
            }
        }
        for (int i=1; i<=n; i++) {
            maxi=max(maxi, dp[i]);
        }
        cout << maxi << "\n";
    }
    return 0;
}