#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define FOR(i,l,r) for(ll i=(l);i<(r);++i)
#define REP(i,n) FOR(i,0,n)
#define REPS(i,n) FOR(i,1,n+1)
#define RFOR(i,l,r) for(ll i=(l);i>=(r);--i)
#define RREP(i,n) RFOR(i,n-1,0)
#define RREPS(i,n) RFOR(i,n,1)
#define pb push_back
#define eb emplace_back
#define SZ(x) ((ll)(x).size())
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
template<class T = ll> using V = vector<T>;
template<class T = ll> using VV = V<V<T>>;
template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b; return true; }return false; }
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b; return true; }return false; }
inline void Yes(bool b = true) {cout << (b ? "Yes" : "No") << '\n';}
inline void YES(bool b = true) {cout << (b ? "YES" : "NO") << '\n';}
inline void err(bool b = true) {if(b) {cout << -1 << '\n'; exit(0);}}
template<class T> inline void fin(bool b = true, T e = 0) {if(b) {cout << e << '\n'; exit(0);}}
template<class T> T Roundup_div(T x, T y) {return (x+(y-1))/y;}
const ll INF = 1e18;
template <typename T>
T pow(T a, long long n, T e = 1) {
    T ret = e;
    while (n) {
        if (n & 1) ret *= a;
        a *= a;
        n >>= 1;
    }
    return ret;
}
 
using Graph = VV<>;
 
ll n, m, a, b, c, res, pre, sum;

V<> bfs(Graph &G, ll a){
    V<> dist(n);
    V<bool> vis(n, false);
    queue<int> que;
    dist[a] = 0;
    vis[a] = true;
	que.push(a);
    while (!que.empty()) {
        ll v = que.front();
        que.pop();
        for (ll nv : G[v]) {
            if (vis[nv]) continue;
            dist[nv] = dist[v] + 1;
            que.push(nv);
            vis[nv] = true;
        }
    }
    return dist;
}
 
void solve(){
    cin >> n >> m >> a >> b >> c; a--; b--; c--;
    V<> p(m);
    REP(i, m) cin >> p[i];
    sort(all(p));
    V<> rui(m + 1);
    REP(i, m) rui[i + 1] = rui[i] + p[i];
    Graph G(n);
    REP(i, m){
        ll u, v; cin >> u >> v; u--; v--;
        G[u].pb(v);
        G[v].pb(u);
    }
    V<> da = bfs(G, a), db = bfs(G, b), dc = bfs(G, c);
    res = INF;
    REP(i, n){
        pre = 0;
        sum = da[i] + db[i] + dc[i];
        if(sum > m) continue;
        ll cnt = 0;
        pre += rui[sum] + rui[db[i]];
        chmin(res, pre);
    }
    cout << res << '\n';
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--) solve();
}