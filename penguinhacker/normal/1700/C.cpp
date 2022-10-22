#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 2e5+10, MOD = 1e9+7;
const ll INF = 1e18+10;

void solve() {
    int n; cin >> n;
    vector<ll> a(n); for (auto& x : a) cin >> x;
    vector<ll> sum(n);

    auto add = [&](int l, int r, ll x) {
        sum[l] += x;
        if (r < n-1) sum[r+1] -= x;
    };
    for (int i = 0; i < n; i++) add(i, i, a[i]);

    ll ans = 0;
    for (int i = 1; i < n; i++) {
        ans += abs(a[i] - a[i-1]);
        if (a[i] - a[i-1] > 0) {
            add(i, n-1, a[i-1] - a[i]);
        } else {
            add(0, i-1, a[i] - a[i-1]);
        }
    }
    for (int i = 1; i < n; i++) sum[i] += sum[i-1];
    for (int i = 1; i < n; i++) assert(sum[i] == sum[i-1]);

    cout << ans + abs(sum[0]) << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}