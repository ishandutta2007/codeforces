#include <bits/stdc++.h>

using namespace std;
const int c=200005, sok=1e9;
int n, ans[c], dp[c], opt[c], ert, pos;
vector<pair<int, int> > sz;
int dif(int a, int b) {
    return sz[a].first-sz[b].first;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    sz.push_back({0, 0});
    for (int i=1; i<=n; i++) {
        int x;
        cin >> x;
        sz.push_back({x, i});
    }
    sort(sz.begin(), sz.end());
    if (n<=5) {
        cout << dif(n, 1) << " " << 1 << "\n";
        for (int i=1; i<=n; i++) {
            cout << 1 << " ";
        }
        cout << "\n";
        return 0;
    }
    dp[1]=sok, dp[2]=sok;
    for (int i=3; i<=5; i++) {
        dp[i]=dif(i, 1);
        opt[i]=i;
    }
    for (int i=6; i<=n; i++) {
        dp[i]=sok;
        for (int j=3; j<=5; j++) {
            int s=dp[i-j]+dif(i, i-j+1);
            if (s<dp[i]) {
                dp[i]=s;
                opt[i]=j;
            }
        }
    }
    pos=n;
    while (pos>0) {
        int s=pos-opt[pos];
        ert++;
        while (pos>s) {
            ans[sz[pos].second]=ert;
            pos--;
        }
    }
    cout << dp[n] << " " << ert << "\n";
    for (int i=1; i<=n; i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";
    return 0;
}