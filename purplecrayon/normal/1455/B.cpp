#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 1e5+10, MOD = 1e9+7;

void solve() {
    ll x; cin >> x;
    ll ans = 0;
    while (ans * (ans + 1) < 2 * x) ans++;
    ans += ans * (ans + 1) / 2 == x + 1;
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}