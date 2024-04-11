#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 2e3+10, MOD = 1e9+7;

void solve() {
    int n; cin >> n;
    vector<int> a(n); for (auto& x : a) cin >> x;

    map<int, int> mp;
    for (auto x : a) mp[x]++;
    int cc = 0;
    for (auto& [_, k] : mp) k = cc++;
    for (auto& x : a) x = mp[x];

    vector<vector<int>> loc(n);
    for (int i = 0; i < n; i++) loc[a[i]].push_back(i);

    ar<int, 4> ans; ans.fill(-MOD);
    for (int i = 0; i < n; i++) if (sz(loc[i])) {
        // r - l + 1 -> good
        // loc[r] - loc[l] + 1 -> all
        // 2 * (r - l + 1) - (loc[r] - loc[l] + 1)
        // 2 * r - 2 * l + 1 - loc[r] + loc[l]
        //
        // (2 * r - loc[r]) - (2 * l - loc[l]) + 1
        //
        // r - l - loc[r] + loc[l] 
        // (r - loc[r]) - (l - loc[l])
        pair<int, int> mx = {-MOD, -MOD};
        for (int r = 0; r < sz(loc[i]); r++) {
            mx = max(mx, {-2 * r + loc[i][r] + 1, loc[i][r]});
            ans = max(ans, {2 * r - loc[i][r] + mx.first, i, mx.second, loc[i][r]});
        }
    }
    for (auto& [x, k] : mp) if (ans[1] == k) {
        ans[1] = x;
        break;
    }

    cout << ans[1] << ' ' << ans[2]+1 << ' ' << ans[3]+1 << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}