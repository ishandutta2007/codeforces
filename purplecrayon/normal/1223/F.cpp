#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 2e5+10, MOD = 1e9+7;

void solve() {
    int n; cin >> n;
    vector<int> a(n); for (auto& x : a) cin >> x;

    vector<map<int, int>> mp(n + 1);
    vector<int> root(n + 1); root[n] = n;
    vector<int> par(n + 1, -1), depth(n + 1);

    ll ans = 0;
    for (int i = n-1; i >= 0; i--) {
        if (mp[root[i+1]].count(a[i])) {
            par[i] = mp[root[i+1]][a[i]]+1;
            root[i] = root[par[i]];
        } else {
            par[i] = -1;
            root[i] = i;
        }
        mp[root[i]][a[i]] = i;

        if (par[i] != -1)
            depth[i] = depth[par[i]] + 1;

        ans += depth[i];
    }
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}