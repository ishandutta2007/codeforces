#include <bits/stdc++.h>

using namespace std;
long long n, k, ans, dp[105][105];
char t[105];
int main()
{
    cin >> n >> k;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
    }
    dp[0][0]=1;
    for (int i=1; i<=n+1; i++) {
        for (int j=i-1; j>=0; j--) {
            for (int db=0; db<=n; db++) {
                dp[i][db+1]=min(dp[i][db+1]+dp[j][db], k);
            }
            if (t[i]==t[j]) break;
        }
    }
    for (int i=n+1; i>=0; i--) {
        long long s=min(dp[n+1][i], k);
        ans+=s*(n-i+1);
        k-=s;
    }
    cout << (k ? -1 : ans) << "\n";
    return 0;
}