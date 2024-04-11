#include "bits/stdc++.h"
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 4e3+10, MOD = 1e9+7;

int n, m, deg[MAXN];
vector<int> adj[MAXN];
bool d[MAXN][MAXN];

void solve(){
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b, --a, --b;
        adj[a].push_back(b), adj[b].push_back(a);
        d[a][b] = d[b][a] = 1;
        deg[a]++, deg[b]++;
    }
    for (int i = 0; i < n; i++) {
        sort(adj[i].begin(), adj[i].end(), [&](int a, int b){ return deg[a] < deg[b]; });
    }
    int ans = MOD;
    for (int i = 0; i < n; i++) {
        for (int j : adj[i]) {
            for (int c : adj[i]) if (d[c][j]) {
                ans = min(ans, deg[i]+deg[j]+deg[c]);
            }
        }
    }
    cout << (ans==MOD?-1:ans-6) << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    //cin >> T;
    while (T--) solve();
}