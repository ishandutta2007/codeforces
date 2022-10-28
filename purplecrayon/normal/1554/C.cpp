#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 2e5+10, MOD = 1e9+7;

void solve(){
    ll n, m; cin >> m >> n;

    //0..n, xor everything with m
    auto get = [&](ll l, ll r) {
        r = min(r, n);
        return max(0ll, r-l+1);
    };

    ll x=0, y=0;
    for (int b = 31; b >= 0; b--) {
        ll range = 1ll<<b;
        ll cnt_one = get(x, x+range-1);
        ll cnt_two = get(x+range, x+range+range-1);
        if ((m>>b)&1) swap(cnt_one, cnt_two), x ^= 1ll<<b;
        if (cnt_one == range) {
            x ^= 1ll<<b;
            y ^= 1ll<<b;
        }
    }
    assert(y == (m^x));
    cout << y << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    cin >> T;
    while (T--) solve();
}