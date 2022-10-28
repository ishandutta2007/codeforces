#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define sz(v) (int)v.size()
#define ar array
// #define f first
// #define s second
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef unsigned int ui;
const int MAXN = 2e2+10, MAXQ = 3e5+10, MAXL = 20, ALP = 26, MOD = 1e9+7, MAXK = 17, INF = 1e9+10, MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n", first = "DA\n", second = "NET\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};

void solve(){
    int n, m; cin >> n >> m;
    vector<string> g(n);
    for (auto& it : g) cin >> it;
    pair<int, int> v{-1, -1};
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++) if (g[i][j] == '*') {
            int x=0;
            for (int k = 0; k < 4; k++){
                int ni = i+hA[k], nj = j+kA[k];
                if (ni >= 0 && ni < n && nj >= 0 && nj < m){
                    x += (g[ni][nj] == '*');
                }
            }
            if (x == 4){
                v = {i, j};
            }
        }
    }
    if (v == make_pair(-1, -1)){ cout << no; return; }
    g[v.first][v.second] = '.';
    {
        int c = v.first-1;
        while (c >= 0 && g[c][v.second] == '*') g[c][v.second] = '.', c--;
    }
    {
        int c = v.first+1;
        while (c < n && g[c][v.second] == '*') g[c][v.second] = '.', c++;
    }
    {
        int c = v.second-1;
        while (c >= 0 && g[v.first][c] == '*') g[v.first][c] = '.', c--;
    }
    {
        int c = v.second+1;
        while (c >= 0 && g[v.first][c] == '*') g[v.first][c] = '.', c++;
    }
    for (auto it : g) for (auto c : it) if (c == '*'){ cout << no; return; }
    cout << yes;
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    // cin >> t; 
    while (t--) solve();
}