#include "bits/stdc++.h"
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 1e5+10, MOD = 1e9+7;

void solve(){
    int n; cin >> n;
    vector<ll> a(n);
    for (auto& it : a) cin >> it;
    ll mx = -1;
    for (auto& it : a) mx = max(mx, it);

    ll ans=0;
    for (auto it : a) ans += mx-it;
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    //cin >> T;
    while (T--) solve();
}