#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 5e5+10, MOD = 1e9+7;

int n, m, par[MAXN], depth[MAXN], match[MAXN];
bool vis[MAXN];
vector<int> adj[MAXN];

void dfs(int c=0, int p=-1, int d=0) {
    par[c] = p, depth[c] = d;
    vis[c] = 1;
    for (auto nxt : adj[c]) if (!vis[nxt]) {
        dfs(nxt, c, d+1);
    }
}
void solve(){
    cin >> n >> m;
    for (int i = 0; i < n; i++) adj[i].clear();
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b, --a, --b;
        adj[a].push_back(b), adj[b].push_back(a);
    }
    fill(vis, vis+n, 0);
    dfs();

    fill(match, match+n, -1);

    vector<ar<int, 2>> ans; ans.reserve(n/2);
    for (int i = 0; i < n; i++) {
        if (depth[i]+1 >= (n+1)/2) {
            cout << "PATH\n" << depth[i]+1 << '\n';
            for (int c = i; c != -1; c = par[c]) cout << c+1 << ' ';
            cout << '\n';
            return;
        }
        if (match[depth[i]] == -1) match[depth[i]] = i;
        else {
            ans.push_back({match[depth[i]], i});
            match[depth[i]] = -1;
        }
    }
    cout << "PAIRING\n" << sz(ans) << '\n';
    for (auto c : ans) cout << c[0]+1 << ' ' << c[1]+1 << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    cin >> T;
    while (T--) solve();
}