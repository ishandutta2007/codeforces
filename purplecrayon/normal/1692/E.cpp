#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 2e3+10, MOD = 1e9+7;

void solve() {
    int n, s; cin >> n >> s;
    vector<int> a(n); for (auto& x : a) cin >> x;
    int need = s;

    vector<int> loc(n + 1, n);
    int ans = -1;
    int ps = 0;
    loc[0] = -1;
    for (int i = 0; i < n; i++) {
        ps += a[i];
        if (ps >= need) ans = max(ans, i - loc[ps - need]);
        if (loc[ps] == n) loc[ps] = i;
    }
    cout << (ans == -1 ? -1 : n - ans) << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}