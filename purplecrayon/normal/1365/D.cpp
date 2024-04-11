#include <bits/stdc++.h>
using namespace std;

#define sz(v) (int)v.size()
// #define f first
// #define s second
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
const int MAXN = 60, MAXM = 1e5+10, ALP = 26, INF = 1e9+10, MOD = 1e9+7;
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};
// const ll INF = 1e18+10;

char g[MAXN][MAXN];
bool vis[MAXN][MAXN];
int n, m;

void dfs(int i, int j){
    vis[i][j] = 1;
    // cout << i << " " << j << endl;
    for (int k = 0; k < 4; k++){
        int ni = i+hA[k], nj = j+kA[k];
        if (ni < 0 || ni >= n || nj < 0 || nj >= m || g[ni][nj] == '#' || vis[ni][nj]) continue;
        dfs(ni, nj);
    }
}
void solve(){
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> g[i][j];
        }
    }
    if (g[n-1][m-1] == 'B'){ cout << no; return; }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (g[i][j] != 'B') continue;
            for (int k = 0; k < 4; k++){
                int ni = i+hA[k], nj = j+kA[k];
                if (ni < 0 || ni >= n || nj < 0 || nj >= m) continue;
                if (g[ni][nj] == 'G'){ cout << no; return; }
                if (g[ni][nj] != 'B') g[ni][nj] = '#';
            }
        }
    }
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) vis[i][j] = 0;
    // for (int i = 0; i < n; i++){
    //     for (int j = 0; j < n; j++) cout << g[i][j];
    //     cout << "\n";
    // }
    if (g[n-1][m-1] != '#') dfs(n-1, m-1);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (g[i][j] == 'G' && !vis[i][j]){ cout << no; return; }
        }
    }
    cout << yes;
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1; 
    cin >> t; 
    while (t--) solve();
}