#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 1e5+10, MOD = 1e9+7;

void solve() {
    int n; cin >> n;
    vector<int> a(n); for (auto& x : a) cin >> x;
    vector<int> loc(n); for (int i = 0; i < n; i++) loc[a[i]] = i;

    ll ans = 1;
    int l = loc[0], r = loc[0];
    for (int i = 1; i < n; i++) {
        if (l <= loc[i] && loc[i] <= r) {
            ans *= r - l + 1 - i;
            ans %= MOD;
        } else {
            l = min(l, loc[i]), r = max(r, loc[i]);
        }
    }
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}