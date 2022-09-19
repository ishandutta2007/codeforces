#include <bits/stdc++.h>

using namespace std;
const int c=5005;
int w, n, lcp[c][c], dp[c][c], maxi;
string s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        cin >> s;
        for (int i=n; i>=1; i--) {
            for (int j=n; j>=1; j--) {
                if (s[i-1]==s[j-1]) {
                    lcp[i][j]=lcp[i+1][j+1]+1;
                }
            }
        }
        for (int i=1; i<=n; i++) {
            dp[i][i]=1;
            for (int j=1; j<i; j++) {
                int k=lcp[i][j];
                if (i+k<=n && s[i+k-1]>s[j+k-1]) {
                    dp[i][i+k]=max(dp[i][i+k], dp[j][n]+1);
                }
            }
            for (int j=i+1; j<=n; j++) {
                dp[i][j]=max(dp[i][j], dp[i][j-1]+1);
            }
            maxi=max(maxi, dp[i][n]);
        }

        cout << maxi << "\n";

        for (int i=1; i<=n; i++) {
            for (int j=1; j<=n; j++) {
                lcp[i][j]=0, dp[i][j]=0;
            }
        }
        maxi=0;
    }
    return 0;
}