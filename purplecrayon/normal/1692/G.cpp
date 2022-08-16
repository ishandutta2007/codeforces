#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 2e3+10, MOD = 1e9+7;

void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n); for (auto& x : a) cin >> x;
    vector<bool> can(n);
    can[0] = 0;
    for (int i = 1; i < n; i++) {
        if (2 * a[i] > a[i-1]) {
            can[i] = 1;
        }
    }
    vector<int> ps(n);
    for (int i = 0; i < n; i++) {
        ps[i] = can[i] + (i ? ps[i-1] : 0);
    }
    auto sum = [&](int l, int r) {
        return ps[r] - (l ? ps[l-1] : 0);
    };

    int ans = 0;
    for (int i = 1; i + k <= n; i++) {
        if (sum(i, i + k - 1) == k) {
            ans++;
        }
    }
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}