#include "bits/stdc++.h"
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 1e5+10, MOD = 1e9+7;

int n, m, k, w, adj[1111][1111], ans[1111], prv[1111];
int cost(vector<string> a, vector<string> b) {
            int cur = 0;
            for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
                cur += b[i][j]!=a[i][j];
            return cur*w;
}
bool vis[1111];
ar<int, 2> bld[1111];
vector<string> a[1111];

void solve(){
    cin >> n >> m >> k >> w;
    for (int i = 0; i < k; i++) {
        a[i].resize(n);
        for (int j = 0; j < n; j++) cin >> a[i][j];
    }
    for (int i = 0; i < k; i++) for (int j = 0; j < k; j++) {
        adj[i][j] = cost(a[i], a[j]);
    }
    memset(prv, -1, sizeof(prv)); memset(vis, 0, sizeof(vis));
    for (int i = 0; i < k; i++) ans[i] = n*m;
    int tot=0;
    for (int rep = 0; rep < k; rep++) { //dij
        pair<int, int> cur{MOD, MOD};
        for (int i = 0; i < k; i++) if (!vis[i]) cur = min(cur, {ans[i], i});
        bld[rep] = {cur.second, prv[cur.second]}, vis[cur.second] = 1, tot += cur.first;
        for (int i = 0; i < k; i++) if (adj[i][cur.second] < ans[i]) prv[i] = cur.second, ans[i] = adj[i][cur.second];
    }
    cout << tot << '\n';
    for (int i = 0; i < k; i++) cout << bld[i][0]+1 << ' ' << bld[i][1]+1 << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    //cin >> T;
    while (T--) solve();
}