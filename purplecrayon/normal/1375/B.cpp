#include <bits/stdc++.h>
using namespace std;

#define sz(v) (int)v.size()
// #define f first
// #define s second
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
const int MAXN = 510, MAXM = 2e5+10, MAXL = 20, ALP = 26, INF = 1e9+10, MOD = 1e9+7;
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};
// const ll INF = 1e18+10;

void solve(){
    int n, m; cin >> n >> m;
    vector<vector<int>> g(n, vector<int>(m, 0));
    bool bad = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> g[i][j]; int nn=0;
            for (int k = 0; k < 4; k++){
                int ni = i+hA[k], nj = j+kA[k];
                if (ni >= 0 && ni < n && nj >= 0 && nj < m) nn++;
            }
            if (g[i][j]>nn) bad = 1;
            g[i][j] = nn;
        }
    }
    if (bad) cout << no;
    else {
        cout << yes;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                cout << g[i][j] << " ";
            }
            cout << "\n";
        }
    }
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1; 
    cin >> t; 
    while (t--) solve();
}