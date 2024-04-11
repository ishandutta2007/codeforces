#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 3e5+10, MOD = 1e9+7;

void solve() {
    int n; cin >> n;
    vector<int> a(n); for (auto& x : a) cin >> x;
    if (n == 1) {
        cout << 0 << '\n';
        return;
    }

    vector<pair<int, int>> ans;
    auto op = [&](int l, int r) {
        ans.emplace_back(l, r);
        if ((a[l] + a[r]) % 2) a[r] = a[l];
        else a[l] = a[r];
    };

    op(0, n-1);
    assert(a[0] == a[n-1]);
    for (int i = 1; i < n-1; i++) {
        if (a[i] % 2 != a[0] % 2) {
            op(0, i);
        } else {
            op(i, n-1);
        }
    }
    cout << sz(ans) << '\n';
    for (auto [a, b] : ans) cout << a+1 << ' ' << b+1 << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}