#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 2e5+10, MOD = 1e9+7;

void solve() {
    int n, m; cin >> n >> m;
    vector<int> a(n); for (auto& x : a) cin >> x;
    int cur = m, ans = 0;
    for (int i = 0; i < n; i++) {
        ans += max(0, a[i] - cur);
        cur += max(0, a[i] - cur), cur -= a[i];
    }
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}