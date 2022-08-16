
#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 2e5+10, MOD = 1e9+7;

void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n); for (auto& x : a) cin >> x;
    map<int, int> mp;
    for (int x : a) mp[x]++;

    vector<int> b; b.reserve(n);
    for (auto& [x, cnt] : mp) if (cnt >= k) b.push_back(x);

    if (!sz(b)) {
        cout << -1 << '\n';
        return;
    }
    pair<int, pair<int, int>> ans{-1, {-1, -1}};
    for (int i = 0; i < sz(b); i++) {
        int j = i;
        while (j < sz(b)-1 && b[j+1] == b[j]+1) j++;
        ans = max(ans, {j - i + 1, {b[i], b[j]}});
        i = j;
    }
    cout << ans.second.first << ' ' << ans.second.second << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}