#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 5e3+10, MOD = 998244353;
const ll INF = 1e18+10;

void solve() {
    int n; cin >> n;
    vector<int> a(n); for (auto& x : a) cin >> x;
    ll ans = INF;
    for (int i = 0; i < n; i++) {
        ll cur = 0;
        ll p = 0;
        for (int j = i-1; j >= 0; j--) {
            ll add = p / a[j] + 1;
            cur += add;
            p = add * a[j];
        }
        p = 0;
        for (int j = i+1; j < n; j++) {
            ll add = p / a[j] + 1;
            cur += add;
            p = add * a[j];
        }
        ans = min(ans, cur);
    }
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}