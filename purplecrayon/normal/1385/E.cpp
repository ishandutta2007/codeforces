#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 2e5+10, ALP = 26, MAXL = 20, INF = 1e9+10;

int n, m, loc[MAXN], sz[MAXN];
vector<int> adj[MAXN], top;
vector<pair<int, int>> ed;
queue<int> q;

void solve(){
    cin >> n >> m; for (int i = 0; i < n; i++) adj[i].clear(), sz[i] = 0;
    top.clear(); ed.clear();
    for (int i = 0; i < m; i++){
        int t, a, b; cin >> t >> a >> b, --a, --b;
        if (t == 1){ //dir
            adj[a].push_back(b); sz[b]++;
        } else { //undir
            
        }
        ed.push_back({a, b});
    }
    for (int i = 0; i < n; i++) if (!sz[i]) q.push(i);
    while (q.size()){
        int c = q.front(); q.pop();
        loc[c] = (int)top.size(); top.push_back(c);
        for (auto nxt : adj[c]){
            sz[nxt]--;
            if (!sz[nxt]) q.push(nxt);
        }
    }
    if ((int)top.size() < n){
        cout << "NO\n"; return;
    }
    cout << "YES\n";
    for (auto e : ed){
        int a = e.first, b = e.second;
        if (loc[b] < loc[a]) swap(a, b);
        cout << a+1 << " " << b+1 << "\n";
    }
}
int main(){
    int t; cin >> t;
    while (t--) solve();
}