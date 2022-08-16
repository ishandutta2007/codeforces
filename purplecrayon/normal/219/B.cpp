#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 2e5+10, MOD = 1e9+7;
const ll INF = 1e18 + 100;

#ifdef LOCAL
#define __int128 ll
#endif

void solve() {
    ll p, d; cin >> p >> d;
    ll ans = p;
    ll cur = 0;
    ll po10 = 1;
    for (int cnt = 0; cur <= p; cnt++) {
        // cur + use * po10 <= p
        // use * po10 <= p - cur
        // use <= (p - cur) / po10
        // use = floor_div(p - cur, po10);
        ll use = (p - cur) / po10;
        if (use * po10 + cur >= p - d) {
            ans = use * po10 + cur;
        }
        if ((__int128) cur * 10 + 9 > p) break;
        cur *= 10, cur += 9;
        po10 *= 10;
    }
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    // cin >> T;
    while (T--) solve();
}