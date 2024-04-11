#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 2e5+10, MOD = 1e9+7;

void solve() {
    int n, m; cin >> n >> m;
    vector<int> a(n); for (auto& x : a) cin >> x;
    int ans = 0;
    while (m--) {
        int l, r; cin >> l >> r, --l, --r;
        int cur = 0;
        for (int i = l; i <= r; i++) cur += a[i];
        ans += max(0, cur);
    }
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}