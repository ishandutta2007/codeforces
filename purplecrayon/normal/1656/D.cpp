#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 1e6+10, MOD = 998244353;

#ifdef LOCAL
#define __int128 ll
#endif

void solve() {
    ll n; cin >> n;
    ll x = n >> __builtin_ctzll(n);
    if (x == 1) { // power of 2 bad
        cout << -1 << '\n';
        return;
    }
    if ((__int128) x * (x + 1) / 2 <= n) {
        cout << x << '\n';
        return;
    } else {
        cout << 2 * (n / x) << '\n';
    }
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    cin >> T;
    while (T--) solve();
}