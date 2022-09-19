#include <bits/stdc++.h>

using namespace std;
const int c=10002;
int n, q, dp[c], cnt;
vector<pair<int, int> > sz[c];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> q;
    for (int i=1; i<=q; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        sz[a].push_back({b, c});
    }
    dp[0]=c;
    for (int i=1; i<=n; i++) {
        for (auto x:sz[i]) {
            int veg=x.first, ert=x.second;
            for (int j=n-ert; j>=0; j--) {
                if (dp[j]>=i) {
                    dp[j+ert]=max(dp[j+ert], min(dp[j], veg));
                }
            }
        }
    }
    for (int i=1; i<=n; i++) {
        if (dp[i]) {
            cnt++;
        }
    }
    cout << cnt << " ";
    for (int i=1; i<=n; i++) {
        if (dp[i]) {
            cout << i << " ";
        }
    }
    cout << "\n";
    return 0;
}