#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 1e5+10;

int n; bool bad = 0;
vector<int> adj[MAXN];
ll sub[MAXN], nm[MAXN], h[MAXN], hh[MAXN], bb[MAXN], m;

ll dfs1(int c=0, int p=-1){
    sub[c] = nm[c];
    for (auto nxt : adj[c]) if (nxt != p){
        sub[c] += dfs1(nxt, c);
    }
    hh[c] = (sub[c]+h[c])>>1;
    bb[c] = sub[c]-hh[c];
    return sub[c];
}
void dfs2(int c=0, int p=-1){
    ll sm = 0;
    for (auto nxt : adj[c]) if (nxt != p) dfs2(nxt, c), sm += hh[nxt];
    if (hh[c]+bb[c] != sub[c] || hh[c]-bb[c] != h[c] || hh[c] < sm || hh[c] > sub[c] || bb[c] > sub[c]) bad = 1;
}
void solve(){
    int n; cin >> n >> m; for (int i = 0; i < n; i++) adj[i].clear();
    for (int i = 0; i < n; i++) cin >> nm[i];
    for (int i = 0; i < n; i++) cin >> h[i];
    for (int i = 0; i < n-1; i++){
        int a, b; cin >> a >> b, --a, --b;
        adj[a].push_back(b), adj[b].push_back(a);
    }
    bad = 0; dfs1(); dfs2();
    // for (int i = 0; i < n; i++) cout << hh[i] << " ";
    // cout << endl; for (int i = 0; i < n; i++) cout << bb[i] << " ";
    // cout << endl;
    cout << (bad ? "NO" : "YES") << "\n";
}

int main(){
    int t; cin >> t;
    while (t--) solve();
}