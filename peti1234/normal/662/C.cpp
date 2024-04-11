#include <bits/stdc++.h>

using namespace std;
const int c=20;
int n, m, mini, dp[c+1][1<<c];
string s[c];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    mini=n*m;
    for (int i=0; i<n; i++) {
        cin >> s[i];
    }
    for (int j=0; j<m; j++) {
        int ert=0;
        for (int i=0; i<n; i++) {
            if (s[i][j]=='1') {
                ert+=(1<<i);
            }
        }
        dp[0][ert]++;
    }
    for (int i=1; i<=n; i++) {
        for (int mask=0; mask<(1<<n); mask++) {
            for (int k=0; k<n; k++) {
                dp[i][mask]+=dp[i-1][mask^(1<<k)];
            }
            if (i>1) {
                dp[i][mask]-=(n-i+2)*dp[i-2][mask];
            }
            dp[i][mask]/=i;
        }
    }
    for (int mask=0; mask<(1<<n); mask++) {
        int ert=0;
        for (int i=0; i<=n; i++) {
            ert+=dp[i][mask]*min(i, n-i);
        }
        mini=min(mini, ert);
    }
    cout << mini << "\n";
    return 0;
}