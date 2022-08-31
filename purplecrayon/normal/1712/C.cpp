#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 1e6+10, MOD = 998244353;

void solve() {
    int n; cin >> n;
    vector<int> a(n); for (auto& x : a) cin >> x, --x;
    vector<vector<int>> loc(n);
    for (int i = 0; i < n; i++) loc[a[i]].push_back(i);
    vector<bool> col(n);
    vector<int> prv{a[0]};

    auto get_value = [&](int i) {
        return col[a[i]] ? -1 : a[i];
    };

    for (int i = 1; i < n; i++) {
        if (get_value(i) < get_value(i-1)) {
            for (int x : prv) col[x] = 1;
            col[a[i-1]] = 1;
            prv.clear();
        }
        prv.push_back(a[i]);
    }
    int ans = 0;
    for (auto x : col) ans += x;
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}