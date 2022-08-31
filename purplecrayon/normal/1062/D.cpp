#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 3e5+10, MOD = 1e9+7;

void solve() {
    int n; cin >> n;
    ll ans = 0;
    for (int a = 2; a <= n; a++) {
        for (int b = 2*a; b <= n; b += a) {
            ans += b / a;
        }
    }
    cout << 4 * ans << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}