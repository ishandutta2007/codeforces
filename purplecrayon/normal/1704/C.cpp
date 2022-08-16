#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 3e5+10, MOD = 1e9+7;

void solve() {
    int n, m; cin >> n >> m;
    vector<int> a(m); for (auto& x : a) cin >> x;
    sort(a.begin(), a.end());
    if (m == 1) {
        cout << 2 << '\n';
        return;
    }
    vector<int> gap;
    for (int i = 1; i < m; i++) gap.push_back(a[i] - a[i-1] - 1);
    gap.push_back(a[0] + n - a[m-1] - 1);

    sort(gap.rbegin(), gap.rend());
    int need = 0;
    int ans = m;
    for (int x : gap) {
        int cur = x - 2 * need;
        ans += min(x, 2 * need);
        if (cur <= 0) continue;
        if (cur == 1) need++;
        else if (cur == 2) ans++, need++;
        else ans++, need += 2;
    }
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}