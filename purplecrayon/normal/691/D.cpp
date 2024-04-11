#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 1e6+10, MOD = 1e9+7;


int n, m, a[MAXN];
vector<int> adj[MAXN], comp;
bool vis[MAXN];

void dfs(int c) {
    vis[c] = 1;
    comp.push_back(c);
    for (auto nxt : adj[c]) if (!vis[nxt]) {
        dfs(nxt);
    }
}
void solve(){
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i], --a[i];
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b, --a, --b;
        adj[a].push_back(b), adj[b].push_back(a);
    }
    for (int i = 0; i < n; i++) if (!vis[i]) {
        comp.clear();
        dfs(i);

        sort(comp.begin(), comp.end());
        vector<int> val;
        for (auto c : comp) val.push_back(a[c]);
        sort(val.rbegin(), val.rend());
        for (int i = 0; i < sz(comp); i++) a[comp[i]] = val[i];
    }
    for (int i = 0; i < n; i++) cout << a[i]+1 << ' '; cout << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    //cin >> T;
    while (T--) solve();
}