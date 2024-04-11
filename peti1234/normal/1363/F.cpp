#include <bits/stdc++.h>

using namespace std;
const int c=2002;
int w, n, a[c][32], b[c][32], dp[c][c];
string s, t;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> n >> s >> t;
        for (int i=1; i<=n; i++) for (int j=0; j<27; j++) a[i][j]=0, b[i][j]=0;
        for (int i=0; i<n; i++) a[i+1][s[i]-'a']++, b[i+1][t[i]-'a']++;
        for (int i=1; i<=n; i++) for (int j=0; j<27; j++) a[i][j]+=a[i-1][j], b[i][j]+=b[i-1][j];
        for (int i=1; i<=n; i++) for (int j=i; j<=n; j++) {
            dp[i][j]=c;
            int p=t[j-1]-'a';
            if (i<j && a[n][p]-a[i][p]>b[n][p]-b[j][p]) dp[i][j]=dp[i][j-1];
            if (t[j-1]==s[i-1]) dp[i][j]=min(dp[i][j], dp[i-1][j-1]);
            dp[i][j]=min(dp[i][j], dp[i-1][j]+1);
        }
        for (int i=0; i<27; i++) if (a[n][i]!=b[n][i]) dp[n][n]=-1;
        cout << dp[n][n] << "\n";
    }
    return 0;
}