#include <bits/stdc++.h>

using namespace std;
const int cc=100005;
long long n, t[cc][4], s[cc], dp[cc][4], sok=1e15;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int j=1; j<=3; j++) {
        for (int i=1; i<=n; i++) {
            cin >> t[i][j];
            s[i]+=t[i][j];
            dp[i][j]=-sok;
        }
    }
    dp[0][2]=dp[0][3]=-sok;

    for (int i=0; i<n; i++) {
        long long a=dp[i][1], b=dp[i][2], c=dp[i][3], x=t[i+1][1], y=t[i+1][2], z=t[i+1][3];
        dp[i+1][1]=max({dp[i+1][1], a+x, b+y+x, c+z+y+x});
        dp[i+1][2]=max({dp[i+1][2], a+x+y, b+y, c+z+y});
        dp[i+1][3]=max({dp[i+1][3], a+x+y+z, b+y+z, c+z});
        dp[i+2][1]=max(dp[i+2][1], c+s[i+1]+s[i+2]);
        dp[i+2][3]=max(dp[i+2][3], a+s[i+1]+s[i+2]);
    }
    cout << dp[n][3] << "\n";
    return 0;
}