#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 2e5+10, MOD = 1e9+7;

ll get(ll x) {
    string s = to_string(x);
    string t(sz(s), '?');
    for (int i = 0; i < sz(s); i++) {
        t[i] = min(s[i], '1');
    }
    return stoll(t);
}
void solve(){
    ll n; cin >> n;
    int ans = 0;
    while (n > 0) {
        n -= get(n);
        ans++;
    }
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    cin >> T;
    while (T--) solve();
}