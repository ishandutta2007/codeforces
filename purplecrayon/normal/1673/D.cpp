#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 3e6+10, MOD = 1e9+7;

void solve() {
    ll b, q, y; cin >> b >> q >> y;
    ll c, r, z; cin >> c >> r >> z;
    ll last_b = b + (y - 1) * q;
    ll last_c = c + (z - 1) * r;
    if (c < b || last_c > last_b || r % q || (c - b) % q) {
        cout << 0 << '\n';
        return;
    }
    if (c - r < b || last_c + r > last_b) {
        // either 0 or -1
        cout << -1 << '\n';
        return;
    }
    int ans = 0;

    auto get = [&](int d) {
        if (std::lcm(d, q) != r) return;
        ll extra = r / d;
        extra %= MOD;
        ans += extra * extra % MOD;
        ans %= MOD;
    };

    for (int d = 1; d * d <= r; d++) if (r % d == 0) {
        get(d);
        if (d * d != r) get(r / d);
    }

    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}