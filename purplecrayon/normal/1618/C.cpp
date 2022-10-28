#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 2e5+10, MOD = 1e9+7;

void solve() {
    int n; cin >> n;
    vector<ll> a(n); for (auto& x : a) cin >> x;

    ar<ll, 2> g; g.fill(0);
    for (int i = 0; i < n; i++) g[i % 2] = std::gcd(g[i % 2], a[i]);
    for (ll x : g) {
        bool bad = 0;
        for (int i = 1; i < n && !bad; i++) {
            bool one = a[i-1] % x;
            bool two = a[i] % x;
            if (one == two)
                bad = 1;
        }
        if (!bad) {
            cout << x << '\n';
            return;
        }
    }
    cout << 0 << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    cin >> T;
    while (T--) solve();
}