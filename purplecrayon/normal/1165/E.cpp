#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 1e6+10, MOD = 998244353;

void solve() {
    int n; cin >> n;
    vector<ll> a(n); for (auto& x : a) cin >> x;
    vector<ll> b(n); for (auto& x : b) cin >> x;
    for (int i = 0; i < n; i++) {
        ll cnt = (long long) (i + 1) * (n - i);
        a[i] *= cnt;
    }
    sort(a.begin(), a.end());
    sort(b.rbegin(), b.rend());
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ll x = a[i] % MOD;
        ll y = b[i] % MOD;
        ans += x * y % MOD;
        ans %= MOD;
    }
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    // cin >> T;
    while (T--) solve();
}