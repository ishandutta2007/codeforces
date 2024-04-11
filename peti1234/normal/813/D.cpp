#include <bits/stdc++.h>

using namespace std;
const int c=5005, cc=100005;
int n, t[c], dp[c][c], dp2[c][7], ans;
vector<int> el[cc];
int main()
{
    ios_base::sync_with_stdio(false);
    for (int i=0; i<cc; i++) {
        el[i].push_back(0);
    }
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
        int sa=el[t[i]-1].size(), sb=el[t[i]+1].size();
        el[t[i]].push_back(i);
        for (int j=0; j<i; j++) {
            int a=t[i]%7, b=t[j]%7;
            int ert=dp2[j][a];
            for (int k=1; k<=3; k++) {
                if (sa>=k) {
                    int x=el[t[i]-1][sa-k];
                    if (x!=j) ert=max({ert, dp[j][x], dp[x][j]});
                }
                if (sb>=k) {
                    int x=el[t[i]+1][sb-k];
                    if (x!=j) ert=max({ert, dp[j][x], dp[x][j]});
                }
            }
            ert++;
            //cout << i << " " << j << " " << ert << "\n";
            //int ert=max({dp2[j][a], dp[j][x], dp[x][j], dp[j][y], dp[y][j]})+1;
            dp[j][i]=ert;
            dp2[i][b]=max(dp2[i][b], ert);
            dp2[j][a]=max(dp2[j][a], ert);
            ans=max(ans, ert);
        }
    }
    cout << ans << "\n";
    return 0;
}