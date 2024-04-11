#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 2e5+10, MOD = 1e9+7;

void solve() {
    int n, q; cin >> n >> q;
    vector<int> a(n); for (auto& x : a) cin >> x;
    sort(a.rbegin(), a.rend());

    vector<ll> sum(n);
    for (int i = 0; i < n; i++) sum[i] = a[i] + (i ? sum[i-1] : 0);

    auto qry = [&](int l, int r) {
        return sum[r] - (l ? sum[l-1] : 0);
    };

    while (q--) {
        int x, y; cin >> x >> y;
        cout << qry(x - y, x - 1) << '\n';
    }
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}