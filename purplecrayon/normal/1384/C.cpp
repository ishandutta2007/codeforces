#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 1e2+10, ALP=21;

string a, b;
vector<int> adj[ALP];
bool vis[ALP];

void dfs(int c){
    vis[c] = true; for (auto nxt : adj[c]) if (!vis[nxt]) dfs(nxt);
}
void solve(){
    int n; cin >> n;
    cin >> a >> b;
    for (int i = 0; i < ALP; i++) adj[i].clear();
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < n; i++) { 
        if(a[i]!=b[i]) adj[a[i]-'a'].push_back(b[i]-'a'), adj[b[i]-'a'].push_back(a[i]-'a'); 
        if (a[i] > b[i]) {
            cout << -1 << "\n"; return;
        }
    }
    int ans = ALP;
    for (int i = 0; i < ALP; i++) if (!vis[i]) dfs(i), ans--;
    cout << ans << "\n";
}

int main(){
    int t; cin >> t;
    while (t--) solve();
}