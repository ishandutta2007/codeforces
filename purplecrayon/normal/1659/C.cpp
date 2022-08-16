#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 1e5+10, MOD = 998244353;

void solve() {
    int n, A, B; cin >> n >> A >> B;
    vector<ll> a(n); for (auto& x : a) cin >> x;
    ll base = 0;
    for (int i = 0; i < n; i++) base += a[i] * B;
    ll ans = base;
    for (int i = 0; i < n; i++) {
        ll p = a[i] - (i ? a[i-1] : 0);
        base -= p * B * (n - i - 1);
        base += A * p;
        ans = min(ans, base);
    }
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}