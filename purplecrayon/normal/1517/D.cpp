#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 5e2+10, MOD = 1e9+7;

int n, m, k;
int rght[MAXN][MAXN], down[MAXN][MAXN], lft[MAXN][MAXN], up[MAXN][MAXN];
int pre[MAXN][MAXN], cur[MAXN][MAXN];

void solve(){
    cin >> n >> m >> k;
    if (k&1){ 
        for (int i = 0; i < n; i++) { for (int j = 0; j < m; j++) cout << -1 << ' '; cout << '\n'; }
        return;
    }
    k /= 2;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m-1; j++) {
            cin >> rght[i][j];
            lft[i][j+1] = rght[i][j];
        }
    }
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < m; j++) {
            cin >> down[i][j];
            up[i+1][j] = down[i][j];
        }
    }
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cur[i][j] = MOD;

    for (int rep = 0; rep < k; rep++) {
        for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
            if (i) cur[i][j] = min(cur[i][j], pre[i-1][j]+up[i][j]);
            if (i < n-1) cur[i][j] = min(cur[i][j], pre[i+1][j]+down[i][j]);
            if (j) cur[i][j] = min(cur[i][j], pre[i][j-1]+lft[i][j]);
            if (j < m-1) cur[i][j] = min(cur[i][j], pre[i][j+1]+rght[i][j]);
        }
        for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
            pre[i][j] = cur[i][j], cur[i][j] = MOD;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << 2*pre[i][j] << ' ';
        }
        cout << '\n';
    }
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    //cin >> T;
    while (T--) solve();
}