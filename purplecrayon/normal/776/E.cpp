#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 2e5+10, MOD = 1e9+7;

ll phi(ll n) {
    ll ans = n;
    for (ll x = 2; x*x <= n; x++) if (n % x == 0) {
        while (n % x == 0) n /= x;
        ans -= ans / x;
    }
    if (n > 1) ans -= ans / n;
    return ans;
}
int f(int n) { // phi(n)
    if (n == 1) return n;
    int ans = 0;
    for (int x = 1; x < n; x++) {
        int y = n - x;
        if (gcd(x, y) == 1) ans++;
    }
    return ans;
}
int g(int n) { // n
    int ans = 0;
    for (int d = 1; d*d <= n; d++) if (n % d == 0) {
        ans += f(d);
        if (d*d != n) ans += f(n/d);
    }
    assert(ans == n);
    return ans;
}
int F(int n, int k) {
    if (k == 1) return f(n);
    if (k % 2 == 0) return F(n, k-1);
    if (k % 2 == 1) return f(F(n, k-1));
}
void solve() {
    ll n, k; cin >> n >> k;

    k = (k - 1) / 2;
    ll x = phi(n);
    while (k--) {
        ll p = x;
        x = phi(x);
        if (x == p) break;
    }
    cout << x % MOD << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    // cin >> T;
    while (T--) solve();
}