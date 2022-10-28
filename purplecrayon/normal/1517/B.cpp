#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 1e5+10, MOD = 1e9+7;

void solve(){
    int n, m; cin >> n >> m;
    vector<multiset<ll>> a(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int c; cin >> c;
            a[i].insert(c);
        }
    }
    vector<vector<int>> ans(n, vector<int>(m, -1));
    for (int i = 0; i < m; i++) {
        pair<ll, int> mn{MOD, -1};
        for (int j = 0; j < n; j++) mn = min(mn, {*a[j].begin(), j});
        for (int j = 0; j < n; j++) {
            auto c = prev(a[j].end());
            if (j == mn.second) c = a[j].begin();
            ans[j][i] = *c;
            a[j].erase(c);
        }
    }
    for (auto& r : ans) { for (auto& c : r) cout << c << ' '; cout << '\n'; }
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    cin >> T;
    while (T--) solve();
}