#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 2e5+10, MOD = 998244353;

void solve() {
    int n; cin >> n;
    vector<int> a(n); for (auto& x : a) cin >> x;
    vector<int> loc(n);
    for (int i = 0; i < n; i++) loc[a[i]] = i;

    auto count = [&](int k, int L, int R) {
        if (R - L + 1 > k) return 0;
        int one = max(0, R - k + 1), two = min(L, n - k);
        return max(0, two - one + 1);
    };

    int L = n, R = -1;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        L = min(L, loc[i]), R = max(R, loc[i]);
        // number of intervals of size 2 * (i + 1) or 2 * (i + 1) - 1 that contain L..R
        ans += count(2 * (i + 1), L, R) + count(2 * (i + 1) - 1, L, R);
    }
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}