#include <bits/stdc++.h>

using namespace std;
int n, dp[502][502], db[502];
int main()
{
    cin >> n;
    for (int i=1; i<=n; i++) cin >> dp[i][i], db[i]=n+1;
    for (int j=1; j<n; j++) for (int i=1; i+j<=n; i++) for (int k=i; k<i+j; k++) if (dp[i][k] && dp[i][k]==dp[k+1][i+j]) dp[i][i+j]=dp[i][k]+1;
    for (int i=1; i<=n; i++) for (int j=1; j<=i; j++) if (dp[j][i]) db[i]=min(db[i], db[j-1]+1);
    cout << db[n] << "\n";
    return 0;
}