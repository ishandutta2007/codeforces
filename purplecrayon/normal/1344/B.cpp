#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 1e3+10, MOD = 1e9+7;

int n, m;
string g[MAXN];
bool row[MAXN], col[MAXN], vis[MAXN][MAXN];

int mn_row[MAXN], mx_row[MAXN];
int mn_col[MAXN], mx_col[MAXN];


int dx[4]={1, 0, -1, 0}, dy[4]={0, 1, 0, -1};

void dfs(int i, int j) {
    vis[i][j] = 1;
    for (int k = 0; k < 4; k++) {
        int ni = i+dx[k], nj = j+dy[k];
        if (ni < 0 || ni >= n || nj < 0 || nj >= m || g[ni][nj] == '.' || vis[ni][nj]) continue;
        dfs(ni, nj);
    }
}

void solve(){
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> g[i];
    fill(row, row+n, 0), fill(col, col+n, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (g[i][j] == '#') row[i] = col[j] = 1;
        }
    }
    bool white_row = 0, white_col = 0;
    for (int i = 0; i < n; i++) white_row |= !row[i];
    for (int i = 0; i < m; i++) white_col |= !col[i];
    if (white_row ^ white_col) {
        cout << -1 << '\n';
        return;
    }

    fill(mn_row, mn_row+n, MOD), fill(mx_row, mx_row+n, -1);
    fill(mn_col, mn_col+m, MOD), fill(mx_col, mx_col+m, -1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (g[i][j] == '#') {
                mn_row[i] = min(mn_row[i], j);
                mx_row[i] = max(mx_row[i], j);

                mn_col[j] = min(mn_col[j], i);
                mx_col[j] = max(mx_col[j], i);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (mn_row[i] > mx_row[i]) continue;
        for (int j = 0; j < m; j++) {
            bool me = g[i][j] == '#';
            bool he = mn_row[i] <= j && j <= mx_row[i];
            if (me != he) {
                cout << -1 << '\n';
                return;
            }
        }
    }
    for (int j = 0; j < m; j++) {
        if (mn_col[j] > mx_col[j]) continue;
        for (int i = 0; i < n; i++) {
            bool me = g[i][j] == '#';
            bool he = mn_col[j] <= i && i <= mx_col[j];
            if (me != he) {
                cout << -1 << '\n';
                return;
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) if (g[i][j] == '#') {
        if (!vis[i][j]) {
            ans++;
            dfs(i, j);
        }
    }
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    //cin >> T;
    while (T--) solve();
}