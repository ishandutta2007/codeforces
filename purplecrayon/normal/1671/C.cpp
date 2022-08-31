#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 3e2+10, MOD = 998244353;

void solve() {
    int n, x; cin >> n >> x;
    vector<int> a(n); for (auto& x : a) cin >> x;
    sort(a.begin(), a.end());
    vector<int> d(n);
    ll sum = 0;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
        if (sum > x) break;

        // += (i + 1) * d
        // (i + 1) * d + sum <= x
        // d <= (x - sum) / (i + 1)
        ans += (x - sum) / (i + 1) + 1; // <= d is good
    }
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}