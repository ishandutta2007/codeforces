#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 3e5+10, MOD = 998244353;
const int INF = 1e9 + 10;

void solve() {
    int n, x; cin >> n >> x;
    vector<int> a(n); for (auto& x : a) cin >> x;
    vector<int> best(n + 1, -INF);
    for (int l = 0; l < n; l++) {
        int sum = 0;
        for (int r = l; r < n; r++) {
            sum += a[r];
            best[r - l + 1] = max(best[r - l + 1], sum);
        }
    }
    for (int k = 0; k <= n; k++) {
        int ans = 0;
        for (int l = 0; l <= n; l++) {
            ans = max(ans, best[l] + min(k, l) * x);
        }
        cout << ans << ' ';
    }
    cout << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}