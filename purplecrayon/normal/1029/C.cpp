#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 3e5+10, MOD = 1e9+7;

ar<int, 2> isect(ar<int, 2> one, ar<int, 2> two) {
    if (one[1] < two[0] || two[1] < one[0]) return {-1, -1};
    if (one[1] < 0 || two[1] < 0) return {-1, -1};
    return {max(one[0], two[0]), min(one[1], two[1])};
}
void solve() {
    int n; cin >> n;
    vector<ar<int, 2>> a(n); for (auto& [l, r] : a) cin >> l >> r;
    vector<ar<int, 2>> pre = a, suf = a;
    for (int i = 1; i < n; i++) pre[i] = isect(pre[i-1], pre[i]);
    for (int i = n-2; i >= 0; i--) suf[i] = isect(suf[i+1], suf[i]);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ar<int, 2> c{0, int(1e9)};
        if (i) c = isect(c, pre[i-1]);
        if (i < n-1) c = isect(c, suf[i+1]);
        ans = max(ans, c[1] - c[0]);
    }
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}