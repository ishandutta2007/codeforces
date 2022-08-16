#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 1e2+10, MOD = 1e9+7;

int n, m, q;
int a[N][N];
ar<int, 2> loc[N][N];

void solve() {
    cin >> n >> m >> q;
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
        loc[i][j] = {i, j};
    while (q--) {
        int t; cin >> t;
        if (t == 1) {
            int r; cin >> r, --r;
            vector<ar<int, 2>> new_row(m);
            for (int i = 0; i < m; i++) new_row[i] = loc[r][(i+1)%m];
            for (int i = 0; i < m; i++) loc[r][i] = new_row[i];
        } else if (t == 2) {
            int c; cin >> c, --c;
            vector<ar<int, 2>> new_col(n);
            for (int i = 0; i < n; i++) new_col[i] = loc[(i+1)%n][c];
            for (int i = 0; i < n; i++) loc[i][c] = new_col[i];
        } else if (t == 3) {
            int i, j, x; cin >> i >> j >> x, --i, --j;
            a[loc[i][j][0]][loc[i][j][1]] = x;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}