#include <bits/stdc++.h>

using namespace std;
int w, n;
pair<int, int> dp[200005][2];
string s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n >> s;
        bool p=(s[0]=='1');
        dp[0][0]={p, 1};
        dp[0][1]={1-p, 1};
        for (int i=1; i<n; i++) {
            bool p=(s[i]=='1');
            int af=dp[i-1][0].first, as=dp[i-1][0].second, bf=dp[i-1][1].first, bs=dp[i-1][1].second;
            dp[i][0]={af+p, as};
            dp[i][1]={bf+1-p, bs};
            if (i%2==0) {
                if (bf<af || bf==af && bs+1<as) dp[i][0]={bf+p, bs+1};
                if (af<bf || af==bf && as+1<bs) dp[i][1]={af+1-p, as+1};
            }
        }
        bool s=(dp[n-1][1]<dp[n-1][0]);
        cout << dp[n-1][s].first << " " << dp[n-1][s].second << "\n";
    }
    return 0;
}