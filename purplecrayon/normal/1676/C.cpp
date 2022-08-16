#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 2e5+10, MOD = 1e9+7;

void solve() {
    int n, m; cin >> n >> m;
    vector<string> a(n); for (auto& s : a) cin >> s;
    int ans = MOD;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            string x = a[i], y = a[j];
            int c = 0;
            for (int i = 0; i < m; i++) {
                c += abs(x[i] - y[i]);
            }
            ans = min(ans, c);
        }
    }
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}