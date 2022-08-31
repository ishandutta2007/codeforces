#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 1e5+10, MOD = 1e9+7;

void solve() {
    int n, l, r; cin >> n >> l >> r;
    vector<int> a(n); for (auto& x : a) cin >> x;

    sort(a.begin(), a.end());
    auto get = [&](int x) {
        ll ans = 0;
        for (int i = 1; i < n; i++) {
            ans += min<int>(upper_bound(a.begin(), a.end(), x - a[i]) - a.begin(), i);
        }
        return ans;
    };

    cout << get(r) - get(l-1) << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}