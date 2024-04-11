#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
const int MAXN = 2e5+10, ALP = 26, MAXL = 20, INF = 1e9+10;

bool bad = 0, bad1 = 0, bad2 = 0, ans[MAXN], vis[MAXN], vis1[MAXN], vis2[MAXN];
int n, a[MAXN], b[MAXN];
vector<pair<int, int>> locs[MAXN];
vector<pair<int, int>> adj[MAXN];

int dfs1(int c, int col=0){
    ans[c] = col; int sm = col; vis1[c] = 1;
    for (auto ed : adj[c]){
        int nxt = ed.first, val = ed.second;
        if (!vis1[nxt]){
            ans[nxt] = col^val; sm += dfs1(nxt, col^val);
        } else bad1 |= (ans[nxt] != (col^val));
    }
    return sm;
}
int dfs2(int c, int col=1){
    ans[c] = col; int sm = col; vis2[c] = 1;
    for (auto ed : adj[c]){
        int nxt = ed.first, val = ed.second;
        if (!vis2[nxt]){
            ans[nxt] = col^val; sm += dfs2(nxt, col^val);
        }
        else bad2 |= (ans[nxt] != (col^val));
    }
    return sm;
}
int dfs(int c, int col){
    ans[c] = col; int sm = col; vis[c] = 1;
    for (auto ed : adj[c]){
        int nxt = ed.first, val = ed.second;
        if (!vis[nxt]){
            ans[nxt] = col^val; sm += dfs(nxt, col^val);
        }
        else bad |= (ans[nxt] != (col^val));
    }
    return sm;
}
void solve(){
    cin >> n;
    for (int i = 0; i < n; i++) vis[i] = vis1[i] = vis2[i] = ans[i] = 0, adj[i].clear(), locs[i].clear();
    for (int i = 0; i < n; i++) cin >> a[i], --a[i];
    for (int i = 0; i < n; i++) cin >> b[i], --b[i];
    for (int i = 0; i < n; i++){
        locs[a[i]].push_back({i, 0});
        locs[b[i]].push_back({i, 1});
    }
    for (int i = 0; i < n; i++){
        if (locs[i].size() != 2) { cout << "-1\n"; return; }
        if (locs[i][0].second == locs[i][1].second){
            adj[locs[i][0].first].push_back({locs[i][1].first, 1});
            adj[locs[i][1].first].push_back({locs[i][0].first, 1});
            // cout << "AD: " << locs[i][0].first << " " << locs[i][1].first << "\n";
        } else {
            adj[locs[i][0].first].push_back({locs[i][1].first, 0});
            adj[locs[i][1].first].push_back({locs[i][0].first, 0});
        }
    }
    int nm = 0; bad = 0;
    for (int i = 0; i < n; i++) if (!vis[i]) {
        bad1 = bad2 = 0;
        int n1 = dfs1(i), n2 = dfs2(i);
        if (n1 < n2 && !bad1) nm += dfs(i, 0);
        else nm += dfs(i, 1);
        
    }
    if (bad) { cout << "-1\n"; return; }
    cout << nm << "\n";
    for (int i = 0; i < n; i++) if (ans[i]) cout << i+1 << " ";
    cout << "\n";
}
int main(){
    int t; cin >> t;
    while (t--) solve();
}