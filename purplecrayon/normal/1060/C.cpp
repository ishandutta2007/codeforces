#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 3e5+10, MOD = 1e9+7;

void solve() {
    int n, m; cin >> n >> m;
    vector<int> a(n), b(m);
    for (auto& x : a) cin >> x;
    for (auto& x : b) cin >> x;
    ll x; cin >> x;


    vector<pair<ll, int>> v;
    for (int l = 0; l < n; l++) {
        ll sum = 0;
        for (int r = l; r < n; r++) {
            sum += a[r];
            v.push_back({sum, r - l + 1});
        }
    }
    sort(v.begin(), v.end());
    for (int i = 1; i < sz(v); i++) {
        v[i].second = max(v[i].second, v[i-1].second);
    }

    int ans = 0;
    for (int l = 0; l < m; l++) {
        ll sum = 0;
        for (int r = l; r < m; r++) {
            sum += b[r];
            ll can = x / sum;
            int i = upper_bound(v.begin(), v.end(), pair<ll, int>{can, MOD}) - v.begin() - 1;
            if (0 <= i && i < sz(v)) {
                ans = max(ans, (r - l + 1) * v[i].second);
            }
        }
    }
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    // cin >> T;
    while (T--) solve();
}