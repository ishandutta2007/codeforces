#include <bits/stdc++.h>

using namespace std;
const int c=2005, sok=1e9;
int len, s, n, dp[c], spec[c], ert[c];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> len >> s >> n;
    for (int i=1; i<=s; i++) {
        int l, r;
        cin >> l >> r;
        for (int i=l; i<r; i++) spec[i]=1;
    }

    for (int i=1; i<=n; i++) {
        int a, b;
        cin >> a >> b;
        if (!ert[a] || ert[a]>b) {
            ert[a]=b;
        }
    }
    for (int i=1; i<=len; i++) {
        dp[i]=sok;
        if (!spec[i-1]) dp[i]=dp[i-1];
        else {
            for (int j=i-1; j>=0; j--) {
                if (ert[j]) {
                    dp[i]=min(dp[i], dp[j]+ert[j]*(i-j));
                }
            }
        }
    }

    cout << (dp[len]==sok ? -1 : dp[len]) << "\n";
    return 0;
}