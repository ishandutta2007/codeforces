#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 5e5+10, MOD = 1e9+7;

int n;
vector<int> adj[MAXN], depth[MAXN];

map<vector<int>, pair<int, int>> mp;

pair<int, int> qry(vector<int> v) {
    sort(v.begin(), v.end());
    for (auto& x : v) x++;
    if (mp.count(v)) return mp[v];
    cout << "? " << sz(v);
    for (auto x : v) cout << ' ' << x;
    cout << endl;

    int node, dist; cin >> node >> dist, --node;
    return mp[v] = {node, dist};
}
void dfs(int c, int p, int d) {
    depth[d].push_back(c);
    for (auto nxt : adj[c]) if (nxt != p)
        dfs(nxt, c, d+1);
}
void solve() {
    cin >> n;
    mp.clear();
    for (int i = 0; i < n; i++) adj[i].clear(), depth[i].clear();
    for (int i = 0; i < n-1; i++) {
        int a, b; cin >> a >> b, --a, --b;
        adj[a].push_back(b), adj[b].push_back(a);
    }
    vector<int> v(n); iota(v.begin(), v.end(), 0);
    auto [root, dist] = qry(v);
    dfs(root, -1, 0);

    int lo = (dist+1)/2, hi = dist+1, mid = (lo+hi)/2;
    while (lo < mid && mid < hi) {
        if (!sz(depth[mid])) hi = mid;
        else {
            auto [_, cur] = qry(depth[mid]);
            if (cur == dist) lo = mid;
            else hi = mid;
        }
        mid = (lo+hi)/2;
    }

    int one = qry(depth[lo]).first;
    for (int i = 0; i < n; i++) depth[i].clear();
    dfs(one, -1, 0);
    int two = qry(depth[dist]).first;

    cout << "! " << one+1 << ' ' << two+1 << endl;
    
    string s; cin >> s;
    assert(s == "Correct");
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    cin >> T;
    while (T--) solve();
}