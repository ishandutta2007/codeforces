#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 2e5+10, MOD = 1e9+7;

void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n); for (auto& x : a) cin >> x;
    map<int, int> mp;
    for (auto& x : a) mp[x]++;

    vector<pair<int, int>> freq;
    for (auto& x : mp) freq.emplace_back(x.second, x.first);
    sort(freq.begin(), freq.end());

    int m = sz(freq);
    vector<int> prv(m, -1);
    for (int i = 1; i < m; i++) {
        if (freq[i-1].first == freq[i].first) prv[i] = prv[i-1];
        else prv[i] = i-1;
    }

    map<int, int> loc;
    vector<int> last(n, -1);
    for (int i = 0; i < m; i++) {
        loc[freq[i].second] = i;
        last[freq[i].first] = i;
    }

    vector<vector<int>> bad(m);
    for (int i = 0; i < m; i++) bad[i].push_back(i);
    for (int i = 0; i < k; i++) {
        int x, y; cin >> x >> y; x = loc[x], y = loc[y];
        bad[x].push_back(y);
        bad[y].push_back(x);
    }

    vector<bool> can(m, true);

    ll ans = 0;
    for (int i = m-1; i >= 0; i--) {
        auto [c_x, x] = freq[i];

        for (int y : bad[i]) can[y] = false;
        for (int j = last[c_x]; j >= 0; ) {
            if (!can[j]) { 
                j--;
                continue;
            }
            auto [c_y, y] = freq[j];
            ll cost = ((long long) c_x + c_y) * (x + y);
            ans = max(ans, cost);
            j = prv[j];
        }
        for (int y : bad[i]) can[y] = true;
    }
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    cin >> T;
    while (T--) solve();
}