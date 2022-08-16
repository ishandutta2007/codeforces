#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 3e5+10, MOD = 998244353;
const ll INF = 1e12+10;

void solve() {
    int n, x; cin >> n >> x;
    vector<ll> a(n); for (auto& x : a) cin >> x;
    ll mx = INF, mn = -INF;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if ((max(mx, a[i]) - min(mn, a[i]) + 1) / 2 > x) {
            ans++;
            mx = a[i];
            mn = a[i];
        } else {
            mx = max(mx, a[i]);
            mn = min(mn, a[i]);
        }
    }
    cout << ans-1 << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}