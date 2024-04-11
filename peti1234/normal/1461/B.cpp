#include <bits/stdc++.h>

using namespace std;
const int c=502;
bool v[c][c];
int w, n, m, dp[c][c], sum;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> n >> m, sum=0;
        for (int i=0; i<=n+1; i++) {
            for (int j=0; j<=m+1; j++) {
                v[i][j]=0, dp[i][j]=0;
            }
        }
        for (int i=1; i<=n; i++) {
            string s; cin >> s;
            for (int j=1; j<=m; j++) {
                if (s[j-1]=='*') {
                    v[i][j]=1;
                }
            }
        }
        for (int i=n; i>=1; i--) {
            for (int j=1; j<=m; j++) {
                dp[i][j]=max(0, dp[i+1][j]-1);
                bool jo=1;
                while(jo) {
                    int s=dp[i][j];
                    for (int k=0; k<=s; k++) {
                        if (!v[i-k][j+s-k] || !v[i-k][j-s+k]) jo=0;
                    }
                    if (jo) dp[i][j]++;
                }
                sum+=dp[i][j];
            }
        }
        cout << sum << "\n";
    }
    return 0;
}