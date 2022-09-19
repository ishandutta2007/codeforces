#include <bits/stdc++.h>

using namespace std;
const int c=10002;
int dp[c][c], n, m;
string a, b;
bool v[c];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> a >> b;
    n=a.size(), m=b.size();
    for (int i=0; i<=n; i++) for (int j=0; j<=m; j++) dp[i][j]=c;
    dp[0][0]=0;
    for (int i=0; i<n; i++) v[i+1]=(a[i]!='.');
    for (int i=1; i<=n; i++) {
        int db=0, p=i-1;
        if (v[i]) {
            db=1;
            for (int j=i+1; j<=n; j++) {
                if (v[j]) db++;
                else db--;
                if (!db) { p=j; break;}
            }
        }
        for (int j=0; j<=m; j++) {
            dp[i][j]=min(dp[i][j], dp[i-1][j]+1);
            if (j>0 && a[i-1]==b[j-1]) dp[i][j]=min(dp[i][j], dp[i-1][j-1]);
            dp[p][j]=min(dp[p][j], dp[i-1][j]);
        }
    }
    cout << dp[n][m] << "\n";
    return 0;
}