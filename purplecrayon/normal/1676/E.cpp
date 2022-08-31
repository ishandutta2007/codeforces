#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 2e5+10, MOD = 1e9+7;

void solve() {
    int n, q; cin >> n >> q;
    vector<ll> a(n); for (auto& x : a) cin >> x;
    sort(a.rbegin(), a.rend());
    for (int i = 1; i < n; i++) a[i] += a[i-1];

    while (q--) {
        ll x; cin >> x;
        int i = std::lower_bound(a.begin(), a.end(), x) - a.begin();
        if (i == n) cout << -1 << '\n';
        else cout << i+1 << '\n';
    }
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}