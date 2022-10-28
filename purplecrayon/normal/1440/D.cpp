#include "bits/stdc++.h"
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define sz(v) (int)v.size()
#define ar array
// #define f first
// #define s second
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef unsigned int ui;
const int MAXN = 1e5+10, MAXQ = 3e5+10, MAXL = 20, ALP = 26, MOD = 1e9+7, MAXK = 17, INF = 1e9+10, MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};

int n, m, k, deg[MAXN];
bool vis[MAXN];
vector<int> adj[MAXN];
unordered_set<int> ts[MAXN];

void solve(){
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) adj[i].clear(), deg[i]=vis[i]=0, ts[i].clear();
    for (int i = 0; i < m; i++){
        int a, b; cin >> a >> b, --a, --b;
        adj[a].push_back(b), adj[b].push_back(a);
        ts[a].insert(b), ts[b].insert(a);
        deg[a]++, deg[b]++;
    }
    bool canCq=ll(k)*ll(k-1)/ll(2) <= m;
    queue<int> q;
    for (int i = 0; i < n; i++) if (deg[i] < k) q.push(i);
    vector<int> cq; cq.reserve(k);
    while (sz(q)){
        int c=q.front(); q.pop();
        // cout << c << '\n';
        vis[c]=1;
        if (canCq && deg[c] == k-1){
            cq.clear(); cq.push_back(c); bool bad=0;
            for (auto nxt : adj[c]) if (!vis[nxt]) { cq.push_back(nxt); bad |= deg[nxt] < k-1; }
            assert(sz(cq) == k);
            // cout << "CLIQUE\n";
            // cout << c << ' ' << sz(cq) << '\n';
            // for (auto it : cq) cout << it << ' '; cout << '\n';
            for (int x = 0; x < k && !bad; x++) for (int y = 0; y < k && !bad; y++) if (x != y && (ts[cq[x]].find(cq[y])==ts[cq[x]].end())) bad=1;
            if (!bad){
                cout << "2\n";
                for (auto it : cq) cout << (it+1) << ' '; cout << '\n';
                return;
            }
        }
        for (auto nxt : adj[c]) if (!vis[nxt]) {
            deg[nxt]--;
            if (deg[nxt] == k-1) q.push(nxt);
        }
    }
    vector<int> ans;
    for (int i = 0; i < n; i++) if (!vis[i]) ans.push_back(i);
    if (ans.empty()){ cout << "-1\n"; return; }
    cout << "1 " << sz(ans) << '\n';
    for (auto it : ans) cout << (it+1) << ' ', assert(deg[it]>=k);
    cout << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    cin >> t;
    while (t--) solve();
}