#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 1e5+10;

int n;
ll s, w[MAXN], sm, sub[MAXN];
vector<pair<int, ll>> adj[MAXN];

ll dfs(int c=0, int p=-1, ll wi=0){
    sub[c] = 0; w[c] = wi; ll nm=0;
    for (auto nxt : adj[c]) if (nxt.first != p){
        sub[c] += dfs(nxt.first, c, nxt.second); nm++;
    }
    sub[c] += (!nm ? 1 : 0);
    return sub[c];
}
void solve(){
    cin >> n >> s; for (int i = 0; i < n; i++) adj[i].clear();
    for (int i = 0; i < n-1; i++){
        int a, b; ll w;
        cin >> a >> b >> w, --a, --b;
        adj[a].push_back({b, w}); adj[b].push_back({a, w});
    }
    dfs(); set<pair<ll, int>> poss; sm = 0;
    // for (int i = 0; i < n; i++) cout << sub[i] << " ";
    // cout << endl;
    for (int c = 1; c < n; c++) {
        ll cur = w[c]*sub[c], nw = (w[c]>>1)*sub[c];
        poss.insert({nw-cur, c}); sm+=w[c]*sub[c];
    }
    ll ans = 0;
    while (sm > s){
        auto c = poss.begin(); auto cc = *c; poss.erase(c);
        sm += cc.first; w[cc.second] = (w[cc.second]>>1);
        ll cur = w[cc.second]*sub[cc.second], nw = (w[cc.second]>>1)*sub[cc.second];
        poss.insert({nw-cur, cc.second}); ans++;
        // cout << cc.second << " " << sm << "\n";
    }
    cout << ans << "\n";
}

int main(){
    int t; cin >> t;
    while (t--) solve();
}