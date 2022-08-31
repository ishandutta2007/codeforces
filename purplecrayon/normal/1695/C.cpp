#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 3e5+10, MOD = 1e9+7;

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (auto& r : a) for (auto& c : r) cin >> c;
    if ((n + m - 1) % 2) {
        cout << "NO\n";
        return;
    }
    vector<vector<int>> mn(n, vector<int>(m, MOD)), mx(n, vector<int>(m, -MOD));
    mn[0][0] = mx[0][0] = a[0][0];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i) {
                mn[i][j] = min(mn[i][j], mn[i-1][j] + a[i][j]);
                mx[i][j] = max(mx[i][j], mx[i-1][j] + a[i][j]);
            }
            if (j) {
                mn[i][j] = min(mn[i][j], mn[i][j-1] + a[i][j]);
                mx[i][j] = max(mx[i][j], mx[i][j-1] + a[i][j]);
            }
        }
    }
    if (mn[n-1][m-1] <= 0 && mx[n-1][m-1] >= 0) {
        cout << "YES\n";
        return;
    }
    cout << "NO\n";
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}