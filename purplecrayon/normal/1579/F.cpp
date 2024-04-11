#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 1e6+10, MOD = 1e9+7;

void solve() {
    int n, d; cin >> n >> d;
    vector<int> a(n); for (auto& c : a) cin >> c;

    vector<bool> vis(n);
    vector<vector<int>> group;
    for (int i = 0; i < n; i++) if (!vis[i]) {
        int c = i;
        group.emplace_back();
        while (!vis[c]) {
            vis[c] = 1;
            group.back().push_back(a[c]);
            c = (c + d) % n;
        }
    }
    int ans = 0;
    for (auto& v : group) {
        if (*min_element(v.begin(), v.end()) == 1) {
            cout << -1 << '\n';
            return;
        }
        int m = sz(v);
        vector<int> d(m, MOD);
        for (int rep = 0; rep < 2; rep++) {
            for (int i = 0; i < m; i++) {
                if (v[i] == 0) d[i] = 0;
                if (i) d[i] = min(d[i], d[i-1]+1);
            }
            d[0] = min(d[0], d[m-1]+1);
        }
        ans = max(ans, *max_element(d.begin(), d.end()));
    }
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    cin >> T;
    while (T--) solve();
}