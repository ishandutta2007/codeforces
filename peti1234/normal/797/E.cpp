#include <bits/stdc++.h>

using namespace std;
const int c=100005, k=305;
int n, t[c], dp[c][k];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
    }
    for (int i=n; i>=1; i--) {
        for (int j=1; j<k; j++) {
            int kov=i+t[i]+j;
            dp[i][j]=(kov>n ? 1 : dp[kov][j]+1);
        }
    }
    int q;
    cin >> q;
    while (q--) {
        int pos, ert;
        cin >> pos >> ert;
        if (ert<k) {
            cout << dp[pos][ert] << "\n";
        } else {
            int cnt=0;
            while (pos<=n) {
                cnt++;
                pos=pos+t[pos]+ert;
            }
            cout << cnt << "\n";
        }
    }
    return 0;
}