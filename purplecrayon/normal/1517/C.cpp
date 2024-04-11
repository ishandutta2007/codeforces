#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 5e2+10, MOD = 1e9+7;

int n, a[MAXN][MAXN];

int dfs(int i, int j, int sz, int id) {
    if (sz <= 0) return 0;

    a[i][j] = id;

    int v = 1; sz--;
    if (j && a[i][j-1] == -1) {
        int nxt = dfs(i, j-1, sz, id);
        v += nxt, sz -= nxt;
    }
    if (i < n-1 && a[i+1][j] == -1) {
        int nxt=  dfs(i+1, j, sz, id);
        v += nxt, sz -= nxt;
    }
    return v;
}
void solve(){
    cin >> n;
    memset(a, -1, sizeof(a));
    for (int i = 0; i < n; i++) {
        int c; cin >> c;
        if (dfs(i, i, c, c) != c){ cout << -1 << '\n'; return; }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) cout << a[i][j] << ' ';
        cout << '\n';
    }
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    //cin >> T;
    while (T--) solve();
}