#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 3e5+10, MOD = 1e9+7;

void solve() {
    int n, k; cin >> n >> k;
    vector<ll> a(n); for (auto& x : a) cin >> x;
    if (k < n) {
        auto sum = a;
        for (int i = 1; i < n; i++) sum[i] += sum[i-1];
        ll ans = 0;
        for (int i = k-1; i < n; i++) {
            ans = max(ans, sum[i] - (i < k ? 0 : sum[i-k]));
        }
        cout << ans + (long long) k * (k - 1) / 2 << '\n';
    } else {
        ll ans = std::accumulate(a.begin(), a.end(), 0LL);
        cout << ((long long) 2 * k - n - 1) * n / 2 + ans << '\n';
    }
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}