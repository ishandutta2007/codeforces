#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 2e5+10, MOD = 1e9+7;

void solve() {
    // there must be an even number of middle stones
    // at least one thing has to have size > 1 (or everything is == 0)
    // _ 3 0 _
    int n; cin >> n;
    vector<int> a(n); for (auto& x : a) cin >> x;
    bool z = 1, big = 0;
    for (int i = 1; i < n-1; i++) {
        if (a[i]) z = 0;
        if (a[i] > 1) big = 1;
    }
    if (z) {
        cout << 0 << '\n';
        return;
    }
    if (!big || (n == 3 && a[1] % 2)) {
        cout << -1 << '\n';
        return;
    }
    ll ans = 0;
    for (int i = 1; i < n-1; i++) ans += (a[i] + 1) / 2;
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    cin >> T;
    while (T--) solve();
}