#include <bits/stdc++.h>

using namespace std;
const int c=200002, k=256, l=-1e9;
int n, m, q, dp[c][k], t[c], ert;
vector<pair<int, int> > sz;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> q;
    sz.push_back({0, 0});
    for (int i=1; i<=n; i++) {
        int a, b; cin >> a >> b;
        sz.push_back({a, i});
        sz.push_back({b+1, -i});
    }
    sort(sz.begin(), sz.end());
    for (int i=1; i<=2*n; i++) {
        int x=sz[i].first, y=sz[i].second;
        if (y>0) {
            for (int j=0; j<8; j++) {
                if (!t[y] && (ert&(1<<j))==0) {
                    t[y]=(1<<j);
                    ert+=t[y];
                }
            }
        } else {
            ert-=t[-y];
        }
    }
    for (int i=1; i<k; i++) {
        dp[0][i]=l;
    }
    for (int i=1; i<=2*n; i++) {
        int x=sz[i].first-sz[i-1].first, y=sz[i].second, p=t[abs(y)];
        for (int j=0; j<k; j++) {
            int f=__builtin_popcount(j);
            dp[i][j]=dp[i-1][j];
            if (f%2) {
                dp[i][j]+=x;
            }
        }
        for (int j=0; j<k; j++) {
            if (y<0) {
                if ((j&p)==0) dp[i][j]=max(dp[i][j], dp[i][j+p]);
                else dp[i][j]=l;
            } else {
                if (j&p) dp[i][j]=max(dp[i][j], dp[i][j-p]);
            }
        }
    }
    cout << dp[2*n][0] << "\n";
    return 0;
}