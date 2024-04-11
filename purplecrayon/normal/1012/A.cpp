#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 1e3+10, MOD = 1e9+7;

void solve() {
    int n; cin >> n;
    vector<int> a(2 * n); for (auto& x : a) cin >> x;
    sort(a.begin(), a.end());
    ll w = a[n-1] - a[0];
    ll h = a[2*n-1] - a[n];
    ll ans = w * h;
    for (int i = 1; i < n; i++) {
        ans = min(ans, (long long) (a[2*n-1] - a[0]) * (a[i+n-1] - a[i]));
    }
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}