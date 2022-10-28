#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 2e5+10, MOD = 1e9+7;

void solve(){
    ll a, b; cin >> a >> b;
    if (a > b) swap(a, b);
    ll x = min({b-a, b/2, a}), ans = x;
    a -= x, b -= 2*x;
    x = min(a, b)/3;
    a -= 3*x, b -= 3*x, ans += 2*x;
    while (max(a, b) >= 2 && min(a, b) >= 1) {
        if (a > b) swap(a, b);
        ans++;
        a--, b -= 2;
    }
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    cin >> T;
    while (T--) solve();
}