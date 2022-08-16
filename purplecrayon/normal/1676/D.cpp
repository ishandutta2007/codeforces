#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 2e5+10, MOD = 1e9+7;

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (auto& r : a) for (auto& c : r) cin >> c;
    
    map<int, ll> one, two;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            one[i - j] += a[i][j];
            two[i + j] += a[i][j];
        }
    }
    ll ans = -MOD;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ans = max(ans, one[i - j] + two[i + j] - a[i][j]);
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