#include <bits/stdc++.h>

using namespace std;
const int c=2002;
int n, h, l, r, t[c], dp[c][c], maxi;
int main()
{
    cin >> n >> h >> l >> r;
    for (int i=1; i<h; i++) dp[0][i]=-c;
    for (int i=1; i<=n; i++) {
        int x; cin >> x;
        for (int j=0; j<h; j++) {
            int a=(j-x+h)%h, b=(a+1)%h;
            dp[i][j]=max(dp[i-1][a], dp[i-1][b]);
            if (l<=j && j<=r) dp[i][j]++;
        }
    }
    for (int i=0; i<h; i++) maxi=max(maxi, dp[n][i]);
    cout << maxi << "\n";
    return 0;
}