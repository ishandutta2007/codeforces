#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 2e5+10, MOD = 998244353;

void solve() {
    int n; cin >> n;
    multiset<ll> s;
    while (n--) {
        int x; cin >> x;
        s.insert(x);
    }
    ll ans = 0;
    while (sz(s) > 1) {
        if (sz(s) % 2 == 0) s.insert(0);
        ll x = *s.begin(); s.erase(s.begin());
        ll y = *s.begin(); s.erase(s.begin());
        ll z = *s.begin(); s.erase(s.begin());
        s.insert(x + y + z);
        ans += x + y + z;
    }
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    // cin >> T;
    while (T--) solve();
}