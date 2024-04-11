#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 1e6+10, MOD = 998244353;

void solve() {
    int n, m, k; cin >> n >> m >> k;
    vector<int> a(n), b(m);
    for (auto& x : a) cin >> x;
    for (auto& x : b) cin >> x;

    vector<int> sum_a(n), sum_b(m);
    for (int i = 0; i < n; i++) sum_a[i] = a[i] + (i ? sum_a[i-1] : 0);
    for (int i = 0; i < m; i++) sum_b[i] = b[i] + (i ? sum_b[i-1] : 0);
    auto get = [&](int x) {
        int y = k / x;
        ll one = 0, two = 0;
        for (int i = 0; i + x <= n; i++) if (sum_a[i + x - 1] - (i ? sum_a[i-1] : 0) == x) one++;
        for (int i = 0; i + y <= m; i++) if (sum_b[i + y - 1] - (i ? sum_b[i-1] : 0) == y) two++;
        return one * two;
    };

    ll ans = 0;
    for (int x = 1; x * x <= k; x++) if (k % x == 0) {
        ans += get(x);
        if (x * x < k) ans += get(k / x);
    }
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}