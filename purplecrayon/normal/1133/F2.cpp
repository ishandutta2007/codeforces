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
const ll INF = 1e18+10;

int n, m, d;
vector<int> adj[MAXN], ch[MAXN];
bool vis[MAXN];
vector<pair<int, int>> ans;

void dfs1(int c=0, int p=-1){
    vis[c]=1;
    for (auto nxt : adj[c]) if (!vis[nxt]){
        dfs1(nxt, c); ch[c].push_back(nxt);
    }
}
void dfs2(int c){
    vis[c]=1; //cout << c << '\n';
    for (auto nxt : adj[c]) if (!vis[nxt]){
        cout << (c+1) << ' ' << (nxt+1)  << '\n';
        dfs2(nxt);
    }
}
void solve(){
    cin >> n >> m >> d;
    for (int i = 0; i < m; i++){
        int a, b; cin >> a >> b, --a, --b;
        adj[a].push_back(b), adj[b].push_back(a);
    }
    memset(vis, 0, sizeof(vis)); dfs1();
    if (d > sz(adj[0]) || d < sz(ch[0])){ cout << no; return; }
    cout << yes;
    {
        set<int> s; for (auto& it : adj[0]) s.insert(it); for (auto& it : ch[0]) s.erase(it);
        vector<int> v; for (auto& it : s) if (sz(v)+sz(ch[0]) < d) v.push_back(it);
        for (auto& it : ch[0]) v.push_back(it);
        adj[0] = v;
    }
    memset(vis, 0, sizeof(vis)); vis[0] = 1;
    for (auto& it : adj[0]) cout << (0+1) << ' ' << (it+1) << '\n', vis[it]=1;
    for (auto& it : adj[0]) dfs2(it);
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    // cin >> t;
    while (t--) solve();
}