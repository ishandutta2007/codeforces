#include <bits/stdc++.h>
#pragma GCC target("sse,sse2,avx2")
#pragma GCC optimize("unroll-loops,O2")
#define rep(i,l,r) for (int i = l; i < r; i++)
#define repr(i,r,l) for (int i = r; i >= l; i--)
#define X first
#define Y second
#define all(x) (x).begin() , (x).end()
#define pb push_back
#define endl '\n'
#define debug(x) cerr << #x << " : " << x << endl;
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pll;
constexpr ll N = 2e5+10,mod = 1e9+7,inf = 1e9+10;
inline int mkay(int a,int b){
    if (a+b >= mod) return a+b-mod;
    if (a+b < 0) return a+b+mod;
    return a+b;
}
 
inline int poww(int a,int k,int md = mod){
    if (k < 0) return 0;
    int z = 1;
    while (k){
        if (k&1) z = 1ll*z*a%md;
        a = 1ll*a*a%md;
        k /= 2;
    } 
    return z; 
}

vector<pll> adj[N];
vector<int> in[N],out[N];
set<int> act;
ll d[N];
bool vis[N],pk[N];
int n,m,s;

inline void dij(){
    d[s] = 0;
    priority_queue<pair<ll,int> > pq;
    pq.push({0,s});
    while (!pq.empty()){
        auto p = pq.top();
        pq.pop();
        int v = p.Y;
        if(-p.X != d[v]) continue;
        for (pll u : adj[v]){
            if (d[v]+u.Y < d[u.X]){
                d[u.X] = d[v]+u.Y;
                pq.push({-d[u.X],u.X});
            }
        }
    }
}

inline bool cmp(int u,int v){
    return (d[u] < d[v]);
}

inline bool check(int v){
    for (int u : in[v]) if (act.find(u) == act.end()) return 0;
    return 1;
}

int bfs(int s){
    queue<int> q;
    queue<int> ve;
    q.push(s);
    int ans = 0;
    while (!q.empty()){
        int v = q.front();
        q.pop();
        pk[v] = 1;
        ans++;
        act.insert(v);
        for (int u : out[v]){
            if (vis[u]) continue;
            vis[u] = 1;
            ve.push(u);
        }
        while (q.empty() && !ve.empty()){
            v = ve.front();
            ve.pop();
            vis[v] = 0;
            if (check(v)) q.push(v);
        }
    }
    return ans;
}

int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    memset(d,63,sizeof d);
    cin >> n >> m >> s;
    rep(i,0,m){
        int u,v,w;
        cin >> u >> v >> w;
        adj[u].pb({v,w});
        adj[v].pb({u,w});
    }
    if (adj[s].empty()){
        cout << 0;
        return 0;
    }
    dij();
    rep(v,1,n+1){
        for (pll p : adj[v]){
            if (d[p.X] == d[v]+p.Y){
                out[v].pb(p.X);
                in[p.X].pb(v);
            }
        }
    }
    vector<int> ve;
    rep(i,1,n+1) ve.pb(i);
    sort(all(ve),cmp);
    int ans = 1;
    rep(i,1,n){
        int v = ve[i];
        if (pk[v]) continue;
        if (d[v] > inf*inf) break;
        ans = max(ans,bfs(v));
        act.clear();
    }
    cout << ans;
    return 0;
}