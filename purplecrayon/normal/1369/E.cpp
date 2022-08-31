#include "bits/stdc++.h"
using namespace std;

template<class T> using min_pq=priority_queue<T, vector<T>, greater<T>>;

#define sz(v) (int)v.size()
#define ar array
// #define f first
// #define s second
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef unsigned int ui;
const int MAXN = 3e5+10, MAXM = 40, MAXL = 20, ALP = 20, MOD = 1e9+7, MAXK = 17, INF = 1e9+10, MAXA = 1e2+10, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};

void solve(){
    int n, m; cin >> n >> m;

    vector<int> a(n);
    vector<vector<pair<int, int>>> adj(n);
    for (auto& it : a) cin >> it;
    for (int i = 0; i < m; i++){
        int a, b; cin >> a >> b, --a, --b;
        adj[a].emplace_back(b, i), adj[b].emplace_back(a, i);
    }
    vector<int> deg(n);
    for (int i = 0; i < n; i++) deg[i] = sz(adj[i]);

    queue<int> q;
    vector<bool> vis(n), dead(m);
    for (int i = 0; i < n; i++) if (deg[i] <= a[i]) q.push(i), vis[i]=1;

    vector<int> ans;
    while (sz(q)){
        int c=q.front(); q.pop();
        deg[c] = 0;
        for (auto nxt : adj[c]) {
            if (!dead[nxt.second]) ans.push_back(nxt.second), dead[nxt.second]=1;
            if (!vis[nxt.first] && (--deg[nxt.first]) <= a[nxt.first]) q.push(nxt.first), vis[nxt.first]=1;
        }
        adj[c].clear();
    }
    
    const string GOOD="ALIVE\n", BAD="DEAD\n";
    if (sz(ans) != m){ cout << BAD; return; }
    cout << GOOD;
    reverse(ans.begin(), ans.end());
    for (auto& it : ans) cout << (it+1) << ' ';
    cout << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    //cin >> t;
    while (t--) solve();
}