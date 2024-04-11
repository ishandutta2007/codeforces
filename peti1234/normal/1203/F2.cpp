#include <bits/stdc++.h>

using namespace std;
const int c=105;
int n, ert, dp[c][c], cnt, maxi;
vector<pair<int, int> > nagy, kis;
int main()
{
    cin >> n >> ert;
    for (int i=1; i<=n; i++) {
        int x, y;
        cin >> x >> y;
        x=max(x, -y);
        if (y>=0) nagy.push_back({x, y});
        else kis.push_back({x+y, y});
    }
    sort(nagy.begin(), nagy.end());
    for (auto x:nagy) {
        if (ert>=x.first) cnt++, ert+=x.second;
    }
    sort(kis.rbegin(), kis.rend());
    for (int i=0; i<=n; i++) for (int j=0; j<=n; j++)  dp[i][j]=-1;
    dp[0][0]=ert;
    for (int i=1; i<=kis.size(); i++) {
        int s=kis[i-1].first-kis[i-1].second, k=kis[i-1].second;
        for (int j=0; j<=n; j++) {
            dp[i][j]=max(dp[i][j], dp[i-1][j]);
            if (dp[i-1][j]>=s) {
                dp[i][j+1]=max(dp[i][j+1], dp[i-1][j]+k);
            }
            if (dp[i][j]>=0) maxi=max(maxi, j);
        }
    }
    //cout << (cnt+maxi==n ? "YES" : "NO") << "\n";
    cout << cnt+maxi << "\n";
    return 0;
}