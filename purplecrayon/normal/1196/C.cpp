#include "bits/stdc++.h"
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 1e5+10, MOD = 1e9+7;

void solve(){
    int n; cin >> n;

    ll mnx = -MOD, mxx = MOD, mny = -MOD, mxy = MOD;
    while (n--) {
        ll x, y; cin >> x >> y;

        { int c; cin >> c; if (!c) mnx = max(mnx, x); }
        { int c; cin >> c; if (!c) mxy = min(mxy, y); }
        { int c; cin >> c; if (!c) mxx = min(mxx, x); }
        { int c; cin >> c; if (!c) mny = max(mny, y); }
    }
    if (mnx <= mxx && mny <= mxy) {
        cout << 1 << ' ' << max(ll(-1e5), mnx) << ' ' << max(ll(-1e5), mny) << '\n';
    } else cout << 0 << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    cin >> T;
    while (T--) solve();
}