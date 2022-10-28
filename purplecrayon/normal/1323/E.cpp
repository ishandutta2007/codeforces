#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 1e6+10, MOD = 998244353;

void solve() {
    int n, m; cin >> n >> m;
    vector<ll> a(n); for (auto& x : a) cin >> x;
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b, --a, --b;
        adj[b].push_back(a);
    }
    map<vector<int>, ll> mp;
    for (int i = 0; i < n; i++) if (sz(adj[i])) {
        sort(adj[i].begin(), adj[i].end());
        mp[adj[i]] += a[i];
    }
    ll ans = 0;
    for (auto& [_, x] : mp) ans = gcd<ll>(ans, x);
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}