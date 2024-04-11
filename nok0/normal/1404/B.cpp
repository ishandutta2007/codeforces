#include<bits/stdc++.h>
using namespace std;
#pragma region Macros
#define ll long long
#define ld long double
#define FOR(i,l,r) for(int i=(l);i<(r);++i)
#define REP(i,n) FOR(i,0,n)
#define REPS(i,n) FOR(i,1,n+1)
#define RFOR(i,l,r) for(int i=(l);i>=(r);--i)
#define RREP(i,n) RFOR(i,n-1,0)
#define RREPS(i,n) RFOR(i,n,1)
#define pb push_back
#define eb emplace_back
#define SZ(x) ((ll)(x).size())
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
template<class T = ll> using V = vector<T>;
template<class T = ll> using VV = V<V<T>>;
using P = pair<ll, ll>;
#define VEC(type, name, size)\
    V<type> name(size);\
    IN(name)
#define VVEC(type, name, h, w)\
    VV<type> name(h, V<type>(w));\
    IN(name)
#define INT(...)\
    int __VA_ARGS__;\
    IN(__VA_ARGS__)
#define LL(...)\
    ll __VA_ARGS__;\
    IN(__VA_ARGS__)
#define STR(...)\
    string __VA_ARGS__;\
    IN(__VA_ARGS__)
#define CHAR(...)\
    char __VA_ARGS__;\
    IN(__VA_ARGS__)
#define DOUBLE(...)\
    DOUBLE __VA_ARGS__;\
    IN(__VA_ARGS__)
#define LD(...)\
    LD __VA_ARGS__;\
    IN(__VA_ARGS__)
template <class T> void scan(T a) { cin >> a; }
void scan(int &a) { cin >> a; }
void scan(long long &a) { cin >> a; }
void scan(char &a) { cin >> a; }
void scan(double &a) { cin >> a; }
void scan(long double &a) { cin >> a; }
void scan(char a[]) { scanf("%s", a); }
void scan(string &a) { cin >> a; }
template <class T> void scan(V<T> &);
template <class T, class L> void scan(pair<T, L> &);
template <class T> void scan(V<T> &a) { for(auto &i : a) scan(i); }
template <class T, class L> void scan(pair<T, L> &p){ scan(p.first); scan(p.second); }
template <class T> void scan(T &a) { cin >> a; }
void IN() {}
template <class Head, class... Tail> void IN(Head &head, Tail &... tail) { scan(head); IN(tail...); }
template <class T> inline void print(T x){ cout << x << '\n';}
struct inputoutputfaster{
    inputoutputfaster(){
        ios::sync_with_stdio(false);\
        cin.tie(nullptr);
        cout << fixed << setprecision(15);
    }
}inputoutputfaster_;
template <class T> V<T> press(V<T> &x){ 
    V<T> res = x;
    sort(all(res));
    res.erase(unique(all(res)), res.end());
    REP(i, SZ(x)){
        x[i] = lower_bound(all(res), x[i]) - res.begin();
    }
    return res;
}
template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b; return true; }return false; }
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b; return true; }return false; }
inline void Yes(bool b = true) {cout << (b ? "Yes" : "No") << '\n';}
inline void YES(bool b = true) {cout << (b ? "YES" : "NO") << '\n';}
inline void err(bool b = true) {if(b) {cout << -1 << '\n'; exit(0);}}
template<class T> inline void fin(bool b = true, T e = 0) {if(b) {cout << e << '\n'; exit(0);}}
template<class T> T divup(T x, T y) {return (x+(y-1))/y;}
template <typename T> T pow(T a, long long n, T e = 1) {T ret = e; while (n) {if (n & 1) ret *= a; a *= a; n >>= 1; } return ret; }
const ll INF = 1e18;
#pragma endregion

// Graph Template
struct Edge{
    ll to,cost;
    Edge(ll to,ll cost):to(to),cost(cost){}
    bool operator < (const Edge& a) const{
        return cost < a.cost;
    }
};
using Graph = VV<>;
using WGraph = VV<Edge>;

void Read_Graph(Graph &g, int m, bool directed = false){
    REP(i, m){
        LL(u, v); u--; v--;
        g[u].pb(v);
        if(!directed) g[v].pb(u);
    }
}
void Read_Tree(Graph &g, bool directed = false) {Read_Graph(g, SZ(g) - 1, directed);}

void Read_Graph(WGraph &g, int m, bool directed = false){
    REP(i, m){
        LL(u, v, c); u--; v--;
        g[u].pb({v, c});
        if(!directed) g[v].pb({u, c});
    }
}
void Read_Tree(WGraph &g, bool directed = false) {Read_Graph(g, SZ(g) - 1, directed);}

template <typename T>
struct ReRooting{
private:
    using F = function<T(T, int)>;
    using F2 = function<T(T, T)>;
    int n;
    Graph G;
    VV<T> dp;
    F f, g;
    F2 merge;
    T ide;

    T dfs1(int p, int k){
        T res = ide;
        int cnt = -1;
        REP(i, SZ(G[k])){
            if(G[k][i] == p) continue;
            dp[k][i] = dfs1(k, G[k][i]);
            res = merge(res, f(dp[k][i], G[k][i]));
        }
        return g(res, k);
    }

    void dfs2(int p, int k, T add){
        REP(i, SZ(G[k])){
            if(G[k][i] == p){
                dp[k][i] = add;
                break;
            }
        }
        V<T> pL(SZ(G[k]) + 1), pR(SZ(G[k]) + 1);
        pL[0] = ide;
        REP(i, SZ(G[k])) pL[i + 1] = merge(pL[i], f(dp[k][i], G[k][i]));
        pR[SZ(G[k])] = 1;
        RREP(i, SZ(G[k])) pR[i] = merge(pR[i + 1], f(dp[k][i], G[k][i]));
        REP(i, SZ(G[k])){
            if(G[k][i] == p) continue;
            T val = merge(pL[i], pR[i + 1]);
            dfs2(k, G[k][i], g(val, k));
        }
    }
    void build(int root){
        REP(i, n) dp[i].resize(SZ(G[i]));
        dfs1(-1, root);
        dfs2(-1, root, ide);
    }

public:
    ReRooting(Graph G_, F f_, F2 merge_, T ide_, F g_ = [](T a, int b){return a;})
    : G(G_), f(f_), merge(merge_), ide(ide_), g(g_){
        n = SZ(G);
        dp.resize(n);
    }

    V<T> solve(int root = 0){
        build(root);
        V<T> vec(n);
        REP(k, n){
            T res = ide;
            REP(i, SZ(G[k])) res = merge(res, f(dp[k][i], G[k][i]));
            vec[k] = g(res, k);
        }
        return vec;
    }
};

pair<int, int> dfs(const Graph &G, int u, int par) {  // 
    pair<int, int> ret = make_pair(0, u);
    for (auto e : G[u]) {
        if (e == par) continue;
        auto next = dfs(G, e, u);
        next.first += 1;
        ret = max(ret, next);
    }
    return ret;
}

int tree_diamiter(const Graph &G) {
    pair<int, int> p = dfs(G, 0, -1);
    pair<int, int> q = dfs(G, p.second, -1);
    return q.first;
}

void solve(){
    INT(n, a, b, da, db); a--; b--;
    Graph G(n);
    Read_Tree(G);
    int diameter = tree_diamiter(G);
    V<int> dist(n, -1);
    queue<int> q;
    dist[a] = 0;
    q.push(a);
    int t;
    while(SZ(q)){
        int v = q.front();
        q.pop();
        for(auto nv : G[v]){
            if(dist[nv] != -1) continue;
            dist[nv] = dist[v] + 1;
            if(nv == b){
                t = dist[nv];
                break;
            }
            q.push(nv);
        }
    }
    if(t <= da){
        print("Alice");
        return;
    }
    auto f = [](int a, int b){return a + 1;};
    auto merge = [](int a, int b){return max(a, b);};
    ReRooting<int> Re(G, f, merge, 1);
    auto res = Re.solve();
    int d = *min_element(all(res)) - 1;
    if(da * 2 >= diameter or d <= da or da * 2 >= db) print("Alice");
    else print("Bob");
}

int main(){
    INT(t);
    while(t--) solve();
}