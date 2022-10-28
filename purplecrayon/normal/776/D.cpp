#include <bits/stdc++.h>
using namespace std;

#define sz(v) (int)v.size()

typedef vector<int> vi;
typedef long long ll;
const int MAXN = 1e5+10, MAXM = 1e5+10;
const string yes = "YES\n", no = "NO\n";

int n, m, a[MAXN];
bool vis[MAXN], vis1[MAXN], vis2[MAXN], ans[MAXN];
vector<pair<int, int>> adj[MAXN];
vector<int> door[MAXN];

void dfs(int c, int b){
    vis[c] = 1; ans[c] = b;
    for (auto nxt : adj[c]) if (!vis[nxt.first]) {
        dfs(nxt.first, b^nxt.second);
    }
}
bool dfs1(int c, int b){
    vis1[c] = 1; ans[c] = b;
    for (auto nxt : adj[c]){
        if (vis1[nxt.first]||vis[nxt.first]){
            if (b^nxt.second != ans[nxt.first]) return false;
            continue;
        } else if (!dfs1(nxt.first, b^nxt.second)) return false;
    }
    return true;
}
bool dfs2(int c, int b){
    vis2[c] = 1; ans[c] = b;
    for (auto nxt : adj[c]){
        if (vis2[nxt.first]||vis[nxt.first]){
            if (b^nxt.second != ans[nxt.first]) return false;
            continue;
        } else if (!dfs2(nxt.first, b^nxt.second)) return false;
    }
    return true;
}
void solve(){
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++){
        int mi; cin >> mi;
        for (int j = 0; j < mi; j++){
            int d; cin >> d, --d;
            door[d].push_back(i);
        }
    }
    for (int i = 0; i < n; i++){
        if (sz(door[i])!=2){ cout << no; return; }
        int val = (a[i] ? 0 : 1);
        int a = door[i][0], b = door[i][1];
        adj[a].push_back({b, val}); adj[b].push_back({a, val});
        vis[i] = vis1[i] = vis2[i] = false;
    }
    // for (int i = 0; i < n; i++) for (auto it : adj[i]) cout << i << " " << it.first << " " << it.second << "\n";
    bool bad = 0;
    for (int i = 0; i < m && !bad; i++) if (!vis[i]) {
        if (dfs1(i, 0)) dfs(i, 0);
        else if (dfs2(i, 1)) dfs(i, 1);
        else bad = 1;
    }
    cout << (bad?no:yes);
}
int main(){
    ios::sync_with_stdio(false); cin.sync_with_stdio(false); cin.tie(0);
    int t=1;
    // cin >> t;
    while (t--) solve();
}