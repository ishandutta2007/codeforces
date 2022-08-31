#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 2e5+10, MOD = 1e9+7;

void solve() {
    int n; cin >> n;
    vector<int> a(n); for (auto& x : a) cin >> x;
    ll ans = 0;
    for (int l = 0; l < n; l++) {
        int z = 0;
        for (int r = l; r < n; r++) {
            z += a[r] == 0;
            ans += (r - l + 1) + z;
        }
    }
    cout << ans << '\n';
    // n + cnt_zeroes
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    cin >> T;
    while (T--) solve();
}