#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 1e6+10, MOD = 1e9+7;
const int HALF = (MOD + 1) / 2;

void solve() {
    int a, b; cin >> a >> b;
    ll ans = 0;
    for (ll k = 1; k <= a; k++) {
        ans += (k * b % MOD + 1) * b % MOD * (b - 1) % MOD * HALF % MOD;
        ans %= MOD;
    }
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}