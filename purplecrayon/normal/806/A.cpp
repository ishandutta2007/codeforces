#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 2e5+10, MOD = 1e9+7;

int ceil_div(int x, int y){ return (x+y-1)/y; }
void solve(){
    ll x, y, p, q; cin >> x >> y >> p >> q;

    auto v = [&](ll m) {
        ll a = ll(m)*p;
        ll b = ll(m)*q;
        return a >= x && b >= y && a-x <= b-y;
    };

    int lo = -1, hi = MOD, mid = (lo+hi)/2;
    if (!v(hi)){ cout << -1 << '\n'; return; }
    while (lo < mid && mid < hi) {
        if (v(mid)) hi = mid;
        else lo = mid;
        mid = (lo+hi)/2;
    }

    cout << hi*q-y << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    cin >> T;
    while (T--) solve();
}