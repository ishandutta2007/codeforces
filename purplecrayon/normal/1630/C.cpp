#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 1e5+10, MOD = 998244353;

void solve() {
    int n; cin >> n;
    vector<int> a(n); for (auto& x : a) cin >> x, --x;
    vector<int> last(n, -1);
    for (int i = 0; i < n; i++)
        last[a[i]] = i;

    int ans = n;
    for (int p = 0, c = 0; p < n; ans--) {
        int cur = c;
        for (int i = p; i <= c; i++) cur = max(cur, last[a[i]]);
        if (cur == c) c++, p = c;
        else p = c, c = cur;
    }
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    // cin >> T;
    while (T--) solve();
}