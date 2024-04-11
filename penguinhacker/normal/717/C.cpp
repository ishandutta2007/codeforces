#include <bits/stdc++.h>
using namespace std;

#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 2e5+10, MOD = 1e4+7;


void solve() {
    int n; cin >> n;
    vector<int> a(n); for (auto& x : a) cin >> x;
    auto b = a;
    sort(a.begin(), a.end());
    sort(b.rbegin(), b.rend());
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ans += (long long) a[i] * b[i] % MOD;
        ans %= MOD;
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}