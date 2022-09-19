#include <bits/stdc++.h>

using namespace std;
const int c=10000002, f=200002, kk=22;
int sqf[c], ki[c];
int w, n, k, t[f], el[f];
pair<int, int> dp[f][kk];
int main()
{
    for (int i=1; i<c; i++) {
        sqf[i]=i;
    }
    for (int i=2; i*i<c; i++) {
        int ert=i*i;
        for (int j=ert; j<c; j+=ert) {
            while (sqf[j]%ert==0) {
                sqf[j]/=ert;
            }
        }
    }
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n >> k;
        for (int i=1; i<=n; i++) {
            cin >> t[i];
            t[i]=sqf[t[i]];
            el[i]=ki[t[i]];
            ki[t[i]]=i;
        }
        for (int i=0; i<=n; i++) {
            for (int j=0; j<=k; j++) {
                dp[i][j]={f, f};
            }
        }
        dp[1][0]={1, -1};
        for (int i=2; i<=n; i++) {
            for (int j=0; j<=k; j++) {
                pair<int, int> s=dp[i-1][j];
                int fi=s.first, se=-s.second;
                if (el[i]<se) {
                    dp[i][j]=min(dp[i][j], s);
                } else {
                    dp[i][j]=min(dp[i][j], {fi+1, -i});
                    dp[i][j+1]=min(dp[i][j+1], s);
                }
            }
        }
        int mini=f;
        for (int i=0; i<=k; i++) {
            mini=min(mini, dp[n][i].first);
        }
        cout << mini << "\n";
        for (int i=1; i<=n; i++) {
            ki[t[i]]=0, el[i]=0;
        }
    }
    return 0;
}
/*
1
5 0
18 6 2 4 1
*/