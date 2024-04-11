#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 3e5+10, MOD = 998244353;

void solve() {
    int n; cin >> n;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        ans += x;
    }
    int mx = -1;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        ans += x;
        mx = max(mx, x);
    }
    cout << ans - mx << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}