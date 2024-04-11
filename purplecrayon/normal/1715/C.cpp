#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 1e5+10, MOD = 998244353;

void solve() {
    int n, m; cin >> n >> m;

    auto f = [&](ll x) {
        return (x + 1) * (n - x - 1);
    };

    vector<int> a(n); for (auto& x : a) cin >> x;
    vector<bool> has(n - 1);
    ll cur = 0;
    for (int i = 1; i < n; i++) if (a[i] != a[i-1]) {
        has[i-1] = 1;
        cur += f(i-1);
    }
    ll base = (long long) n * (n + 1) / 2;
    while (m--) {
        int i, x; cin >> i >> x, --i;
        if (i > 0) {
            if (has[i-1]) cur -= f(i-1);
            has[i-1] = (x != a[i-1]);
            if (has[i-1]) cur += f(i-1);
        }
        if (i < n-1) {
            if (has[i]) cur -= f(i);
            has[i] = (x != a[i+1]);
            if (has[i]) cur += f(i);
        }
        a[i] = x;
        cout << base + cur << '\n';
    }
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}