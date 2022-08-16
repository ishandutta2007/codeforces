#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 5e2+10, MOD = 1e9+7;

int n, m;
string g[MAXN];

int qry(vector<vector<int>>& a, int r1, int c1, int r2, int c2) {
    if (r2 < r1 || c2 < c1) return 0;
    auto get = [&](int i, int j) { return i < 0 || i >= n || j < 0 || j >= m ? 0 : a[i][j]; };
    return get(r2, c2) - get(r2, c1 - 1) - get(r1 - 1, c2) + get(r1 - 1, c1 - 1);
}
void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> g[i];
    }
    vector<vector<int>> v(n, vector<int>(m, 0));
    vector<vector<int>> h(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i < n-1) {
                v[i][j] = (g[i][j] == '.') && (g[i+1][j] == '.');
            }
            if (j < m-1) {
                h[i][j] = (g[i][j] == '.') && (g[i][j+1] == '.');
            }
            if (i) v[i][j] += v[i-1][j], h[i][j] += h[i-1][j];
            if (j) v[i][j] += v[i][j-1], h[i][j] += h[i][j-1];
            if (i && j) v[i][j] -= v[i-1][j-1], h[i][j] -= h[i-1][j-1];
        }
    }
    int q; cin >> q;
    while (q--) {
        int r1, c1, r2, c2; cin >> r1 >> c1 >> r2 >> c2, --r1, --c1, --r2, --c2;
        cout << qry(v, r1, c1, r2-1, c2) + qry(h, r1, c1, r2, c2-1) << '\n';
    }
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    // cin >> T;
    while (T--) solve();
}