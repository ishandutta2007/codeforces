#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 3.5e4+10, MOD = 1e9+7;
const int dx[4]={1, 0, -1, 0}, dy[4]={0, 1, 0, -1};

void solve(){
    ll x, y; cin >> x >> y;
    ll ans = 0;
    for (ll i = 1; i*i < x; i++) {
        ll c = min(y, x/i-1);
        ans += max<ll>(0, c-i);
    }
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    cin >> T;
    while (T--) solve();
}