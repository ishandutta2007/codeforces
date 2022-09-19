#include <bits/stdc++.h>

using namespace std;
const int c=5005;
int n, w, h, x[c], y[c], dp[c], ut[c], maxi;
vector<pair<int, int> > sz;
int main()
{
    cin >> n >> w >> h;
    for (int i=1; i<=n; i++) {
        cin >> x[i] >> y[i];
        sz.push_back({x[i], i});
    }
    sort(sz.begin(), sz.end());
    for (auto p:sz) {
        int id=p.second;
        if (x[id]<=w || y[id]<=h) continue;
        dp[id]=1;
        for (int i=1; i<=n; i++) {
            if (x[id]>x[i] && y[id]>y[i] && dp[i]+1>dp[id]) {
                ut[id]=i;
                dp[id]=dp[i]+1;
            }
        }
        if (dp[id]>dp[maxi]) {
            maxi=id;
        }
    }
    cout << dp[maxi] << "\n";
    vector<int> ans;
    int pos=maxi;
    while (pos) {
        ans.push_back(pos);
        pos=ut[pos];
    }
    reverse(ans.begin(), ans.end());
    for (auto x:ans) {
        cout << x << " ";
    }
    cout << "\n";
    return 0;
}