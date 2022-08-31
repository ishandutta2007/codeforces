#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 2e5+10, MOD = 1e9+7;

int n;
vector<int> adj[MAXN];

bool leaf(int c) {
    return sz(adj[c]) == int(bool(c));
}
int ans = 0;
int open = 0;
int dfs(int c=0, int p=-1) {
    //returns 1 if deleted, 0 if exists, -1 if leaf
    bool bad = 0, bud = 0;
    int child = 0;
    for (auto nxt : adj[c]) if (nxt != p) {
        int they = dfs(nxt, c);
        if (they == 0) bad = 1;
        else if (they == -1) bud = 1, child++;
        else continue;
    }
    if (bad) return 0;
    if (bud) {
        if (c)
            open++;
        return 1;
    } else {
        ans++;
        return -1;
    }
}
void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) adj[i].clear();
    for (int i = 0; i < n-1; i++) {
        int a, b; cin >> a >> b, --a, --b;
        adj[a].push_back(b), adj[b].push_back(a);
    }
    ans = open = 0;
    dfs();
    ans -= open;
    //in a dfs, check if i can be deleted
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    cin >> T;
    while (T--) solve();
}