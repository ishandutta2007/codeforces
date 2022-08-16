#include <bits/stdc++.h>
using namespace std;

#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 2e5+10, MOD = 998244353;
const ll INF = 2e18;

void solve() {
    int n, q; cin >> n >> q;
    ll ans = 0;
    vector<pair<int, int>> a(n); for (auto& x : a) cin >> x.first, x.second = 0, ans += x.first;
    pair<int, int> last{-1, -1};
    for (int qt = 1; qt <= q; qt++) {
        int t; cin >> t;
        if (t == 1) {
            int i, x; cin >> i >> x, --i;
            ans -= last.second < a[i].second ? a[i].first : last.first;
            ans += x;
            a[i] = {x, qt};
        } else {
            int x; cin >> x;
            last = {x, qt};
            ans = (long long) x * n;
        }
        cout << ans << '\n';
    }
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}