#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 2e5+10, MOD = 998244353;

int s(ll x) {
    if (!x) return 0;
    return x%10 + s(x/10);
}
void solve(){
    ll n; cin >> n;
    ll bound = sqrt(n)+10;
    const int MAGIC = 2000;

    ll ans = 2e18;
    for (ll x = bound; x >= bound-MAGIC && x >= 0; x--) {
        if (x*x+s(x)*x == n) ans = min(ans, x);
    }
    if (ans == 2e18) cout << -1 << '\n';
    else cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    //cin >> T;
    while (T--) solve();
}