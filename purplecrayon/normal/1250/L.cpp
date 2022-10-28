#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 3e5+10, MOD = 998244353;

void solve() {
    int n, m; cin >> n >> m;
    vector<int> a(n); for (auto& x : a) cin >> x;
    a.insert(a.begin(), 0), a.push_back(m);
    n += 2;

    vector<ll> pre(n), suf(n + 1);
    for (int i = 1; i < n; i++) {
        if (i % 2 == 1) {
            // initially lit
            pre[i] = a[i] - a[i-1];
        }
        pre[i] += pre[i-1];
    }
    for (int i = n-1; i > 0; i--) {
        if (i % 2 == 0) {
            // initially lit (considering flipping)
            suf[i] = a[i] - a[i-1];
        }
        suf[i] += suf[i+1];
    }
    ll ans = pre[n-1];
    for (int i = 1; i < n-1; i++) {
        // insert right before
        if (a[i] != a[i-1]+1) {
            ll bef =  pre[i] + suf[i+1] - 1;
            ans = max(ans, bef);
        }

        // insert right after
        if (a[i] != a[i+1]-1) {
            ll after =  pre[i] + suf[i+1] - 1;
            ans = max(ans, after);
        }
    }
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}