#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 2e5+10, MOD = 1e9+7;

void solve(){
    ll n; cin >> n;

    auto cnt_mult = [&](ll x) {
        return n/x;
    };

    ll x = 1, ans = 0;
    for (int i = 2; x <= n; x = lcm(x, i++)) {
        ll cur_cnt = cnt_mult(x)-cnt_mult(lcm(x, i));
        ans += cur_cnt%MOD*i%MOD;
        ans %= MOD;
    }
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    cin >> T;
    while (T--) solve();
}