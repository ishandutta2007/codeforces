#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 2e5+10, MOD = 1e9+7;

void solve() {
    int n; cin >> n;
    vector<int> a(n); for (auto& x : a) cin >> x, --x;
    vector<int> suf(n), pre(n);
    for (int i = n-1; i >= 0; i--) {
        suf[i] = a[i];
        if (i < n-1) suf[i] = min(suf[i], suf[i+1]);
    }
    for (int i = 0; i < n; i++) {
        pre[i] = a[i];
        if (i > 0) pre[i] = max(pre[i], pre[i-1]);
    }
    int ans = 1;
    for (int i = 1; i < n; i++) if (pre[i-1] < suf[i]) ans++;
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    cin >> T;
    while (T--) solve();
}