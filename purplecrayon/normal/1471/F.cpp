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
const int MAXN = 3e5+10, MAXM = 5e5+10, MAXL = 20, ALP = 26, MOD = 1e9+7, MAXK = 110, INF = 1e9+10, MAXA = 62, MAXB = 24, MAXBB = (1<<MAXB), MOD2=MOD-1;
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int n, m, vis[MAXN];
vector<int> adj[MAXN];

int dfs(int c){
    vis[c] = 1; int sub=1;
    for (auto nxt : adj[c]) if (!vis[nxt]) sub += dfs(nxt);
    return sub;
}
void solve(){
    for (int i = 0; i < n; i++) adj[i].clear();

    cin >> n >> m;
    for (int i = 0; i < m; i++){
        int a, b; cin >> a >> b, --a, --b;
        adj[a].push_back(b), adj[b].push_back(a);
    }
    fill(vis, vis+n, 0);
    if (dfs(0) != n){ cout << no; return; }

    fill(vis, vis+n, -1);
    queue<int> q;
    set<int> cand;

    auto ad = [&](int c){
        q.push(c); vis[c] = 1;
        cand.insert(c);
    };

    ad(0);

    while (sz(q)){
        auto c = q.front(); q.pop();

        if (!cand.count(c)){ vis[c] = 0; continue; }

        for (auto nxt : adj[c]) {
            vis[nxt] = 0;
            cand.erase(nxt);
            for (auto x : adj[nxt]) if (vis[x] == -1) {
                ad(x);
            }
        }
    }
    cout << yes << std::count(vis, vis+n, 1) << '\n';
    for (int i = 0; i < n; i++) if (vis[i] == 1) cout << (i+1) << ' ';
    cout << '\n';
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t_c=1;
    cin >> t_c;
    while (t_c--) solve();
}