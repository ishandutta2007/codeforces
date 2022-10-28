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
const int MAXN = 2e5+10, MAXQ = 3e5+10, MAXL = 20, ALP = 26, MOD = 1e9+7, MAXK = 17, MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};
 
int qry(int a, int b){
    a++, b++;
    cout << "? " << a << ' ' << b << endl;
    int c; cin >> c, --c;
    return c;
}
void solve(){
    int n; cin >> n;
    vector<vector<int>> adj(n);
    for (int i = 0; i < n-1; i++){
        int a, b; cin >> a >> b, --a, --b;
        adj[a].push_back(b), adj[b].push_back(a);
    }
    vector<int> deg(n), vis(n);
    queue<int> q;
    for (int i = 0; i < n; i++){
        deg[i] = sz(adj[i]);
        if (deg[i] <= 1) q.push(i), vis[i] = 1;
    }
    while (sz(q)){
        int u=q.front(); q.pop();
        if (sz(q) == 0){ cout << "! " << u+1 << endl; return; }
        int v=q.front(); q.pop();

        int lca=qry(u, v);
        if (lca == u || lca == v){ cout << "! " << lca+1 << endl; return; }

        for (auto nxt : adj[u]) if (!vis[nxt]) {
            deg[nxt]--;
            if (deg[nxt] <= 1) q.push(nxt), vis[nxt]=1;
        }
        for (auto nxt : adj[v]) if (!vis[nxt]) {
            deg[nxt]--;
            if (deg[nxt] <= 1) q.push(nxt), vis[nxt]=1;
        }
    }
    assert(false);
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t_c=1;
    //cin >> t_c;
    while (t_c--) solve();
}