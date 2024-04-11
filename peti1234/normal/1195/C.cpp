#include <bits/stdc++.h>

using namespace std;
const int c=100005;
long long n, t[c][2], dp[c][2];
int main()
{
    cin >> n;
    for (int i=0; i<2; i++) {
        for (int j=1; j<=n; j++) {
            cin >> t[j][i];
        }
    }
    for (int i=1; i<=n; i++) {
        for (int j=0; j<2; j++) {
            dp[i][j]=max(dp[i-1][j], dp[i-1][1-j]+t[i][j]);
        }
    }
    cout << max(dp[n][0], dp[n][1]) << "\n";
    return 0;
}