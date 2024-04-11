#include "bits/stdc++.h"
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 2e5+10, MOD = 1e9+7, MAXL = 34;
const int INF = 1e9+10;

int n;
set<int> adj[MAXN];
vector<int> pr[MAXN];

void solve(){
    cin >> n;
    for (int i = 0; i < 2*n; i++) {
        int a, b; cin >> a >> b, --a, --b;
        adj[a].insert(b), adj[b].insert(a);
    }
    for (int i = 0; i < n; i++) if (sz(adj[i]) != 4) {
        cout << -1 << '\n';
        return;
    }
    for (int a : adj[0]) for (int b : adj[0]) for (auto c : adj[b]) if (a != b && b != c && a != c) {
        vector<bool> vis(n); 
        vector<int> cur = {0, a, b, c};
        for (auto x : cur) vis[x] = 1;

        int st = b, loc = 2;
        while (sz(cur) < n) {
            bool bad=1;
            for (auto nxt : adj[st]) if (!vis[nxt]) {
                cur.push_back(nxt), vis[nxt] = 1;
                bad = 0;
                st = cur[++loc];
                break;
            }
            if (bad) break;
        }
        if (sz(cur) != n) continue;
        //for (auto c : cur) cerr << c << ' '; cerr << endl;

        bool bad=0;
        for (int i = 0; i < n; i++) {
            set<int> s{cur[(i-1+n)%n], cur[(i-2+n)%n], cur[(i+1)%n], cur[(i+2)%n]};
            if (s != adj[cur[i]]) { bad = 1; break; }
        }
        if (bad) continue;

        for (auto c : cur) cout << c+1 << ' '; cout << '\n';
        return;
    }
    cout << -1 << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    //cin >> T;
    while (T--) solve();
}