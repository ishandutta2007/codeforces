#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 2e5+10, MOD = 1e9+7;

bool grid[31][31];

int dx[4]={1, 0, -1, 0}, dy[4]={0, 1, 0, -1};

void solve(){
    int n, m; cin >> n >> m;

    memset(grid, 0, sizeof(grid));
    vector<ar<int, 2>> corners{{0, 0}, {0, m-1}, {n-1, 0}, {n-1, m-1}};
    for (int i = 0; i < 4; i++) {
        grid[corners[i][0]][corners[i][1]] = 1;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j]){ cout << 1; continue; }
            bool bad = !(i == n-1 || i == 0 || j == m-1 || j == 0);
            for (int k = 0; k < 4; k++) {
                int ni = i+dx[k], nj = j+dy[k];
                if (ni < 0 || ni >= n || nj < 0 || nj >= m) continue;
                if (grid[ni][nj]) bad = 1;
            }
            if (bad) cout << 0;
            else cout << 1, grid[i][j] = 1;
        }
        cout << '\n';
    }
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    cin >> T;
    while (T--) solve();
}