#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 2e5+10, MOD = 1e9+7;
const ll INF = 1e18 + 10;

void solve() {
    int n; ll l, r; int x; cin >> n >> l >> r >> x;
    vector<ll> a(n); for (auto& c : a) cin >> c;
    int ans = 0;
    for (int m = 1; m < (1 << n); m++) if (__builtin_popcount(m) > 1) {
        ll sum = 0;
        ll mn = INF, mx = -INF;
        for (int i = 0; i < n; i++) {
            if ((m >> i) & 1) {
                sum += a[i];
                mn = min(mn, a[i]);
                mx = max(mx, a[i]);
            }
        }
        if (l <= sum && sum <= r && mx - mn >= x) {
            ans++;
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