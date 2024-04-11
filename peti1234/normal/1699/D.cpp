#include <bits/stdc++.h>

using namespace std;
const int c=5005;
int w, n, t[c], maxi[c][c], db[c], dp[c], ans;
vector<int> sz[c];
bool jo(int l, int r) {
    l++, r--;
    return ((r-l)%2 && 2*maxi[l][r]<=(r-l+1));
}
int main()
{
    cin >> w;
    while (w--) {
        cin >> n;
        for (int i=1; i<=n; i++) {
            sz[i].push_back(0);
        }
        for (int i=1; i<=n; i++) {
            cin >> t[i];
            sz[t[i]].push_back(i);
        }
        for (int i=1; i<=n; i++) {
            sz[i].push_back(n+1);
        }
        for (int i=1; i<=n; i++) {
            int ert=0;
            for (int j=i; j<=n; j++) {
                ert=max(ert, ++db[t[j]]);
                maxi[i][j]=ert;
            }
            for (int i=1; i<=n; i++) {
                db[i]=0;
            }
        }
        for (int ert=1; ert<=n; ert++) {
            for (int i=1; i<=n; i++) {
                dp[i]=-n;
            }
            int si=sz[ert].size();
            for (int i=1; i<si; i++) {
                for (int j=0; j<i; j++) {
                    if (jo(sz[ert][j], sz[ert][i])) {
                        dp[i]=max(dp[i], dp[j]+1);
                    }
                }
            }
            ans=max(ans, dp[si-1]);
        }
        //cout << "valasz: ";
        cout << ans-1 << "\n";


        for (int i=1; i<=n; i++) {
            sz[i].clear();
            for (int j=1; j<=n; j++) {
                maxi[i][j]=0;
            }
        }
        ans=0;
    }
    return 0;
}
/*
1
6
1 1 1 2 2 2
*/