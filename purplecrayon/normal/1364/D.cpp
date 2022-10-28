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
const int MAXN = 1e5+10, MAXQ = 3e5+10, MAXL = 20, ALP = 26, MOD = 1e9+7, MAXK = 17, INF = 1e9+10, MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};

int n, m, k, par[MAXN], depth[MAXN];
vector<int> adj[MAXN];
bool vis[MAXN];

void dfs(int c=0, int p=-1, int d=0){
    par[c] = p, depth[c] = d, vis[c] = 1;
    for (auto nxt : adj[c]) if (nxt != p){
        if (!vis[nxt]){
            dfs(nxt, c, d+1);
        } else if (depth[c] > depth[nxt] && depth[c]-depth[nxt]+1 <= k){
            int v=c;
            cout << "2\n" << (depth[c]-depth[nxt]+1) << '\n';
            while (v != par[nxt]){
                cout << (v+1) << ' ';
                v = par[v];
            }
            exit(0);
        }
    }
}
void solve(){
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++){
        int a, b; cin >> a >> b, --a, --b;
        adj[a].push_back(b), adj[b].push_back(a);
    }
    memset(vis, 0, sizeof(vis));
    dfs();
    if (*max_element(depth, depth+n) >= k-1){
        int c=0; while (depth[c] < k-1) c++;
        vector<int> ans; ans.reserve((k+1)/2);
        while (sz(ans) < (k+1)/2){
            ans.push_back(c);
            c = par[par[c]];
        }
        cout << "1\n";
        for (auto& it : ans) cout << (it+1) << ' ';
        exit(0);
    }
    //it's a tree, 
    assert(m == n-1);
    int x=0, nm=0;
    for (int i = 0; i < n; i++) if (depth[i]&1) nm++;
    x = nm < n-nm;
    vector<int> ans; ans.reserve(n);
    for (int i = 0; i < n; i++) if (depth[i]&1^x) ans.push_back(i);

    assert(sz(ans) >= (k+1)/2);

    cout << "1\n";
    for (int i = 0; i < (k+1)/2; i++) cout << (ans[i]+1) << ' ';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    //cin >> t;
    while (t--) solve();
}