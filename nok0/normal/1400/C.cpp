#include<bits/stdc++.h>
using namespace std;
#pragma region Macros
#define ll long long
#define ld long double
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
using P = pair<ll, ll>;
#define ios\
    ios::sync_with_stdio(false);\
    cin.tie(nullptr);
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
template<class T> T Roundup_div(T x, T y) {return (x+(y-1))/y;}
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

//Strongly Connected Components()(Graph Template)
struct SCC{
    const Graph &g;
    Graph ng, rg;
    V<int> compo, order, used;

    //g:, ret:
    SCC(Graph &g, Graph &ret) : g(g), ng(SZ(g)), rg(SZ(g)), compo(SZ(g), -1), used(SZ(g)){
        REP(i, SZ(g)){
            for(auto v : g[i]){
                ng[i].pb(v);
                rg[v].pb(i);
            }
        }
        build(ret);
    }

    int operator[](int k){ return compo[k];}

    void dfs(int now){
        if(used[now]) return;
        used[now] = true;
        for(auto to : ng[now]) dfs(to);
        order.eb(now);
    }

    void rdfs(int now, int count){
        if(compo[now] != -1) return;
        compo[now] = count;
        for(auto to : rg[now]) rdfs(to, count);
    }

    void build(Graph &ret){
        REP(i, SZ(ng)) dfs(i);
        reverse(all(order));
        int group = 0;
        for(auto i : order) if(compo[i] == -1) rdfs(i, group), group++;
        ret.resize(group);
        REP(i, SZ(g)){
            for(auto &to : g[i]){
                int s = compo[i], t = compo[to];
                if(s != t) ret[s].eb(t);
            }
        }
    }
};

//2-SAT(SCC)
struct TwoSat{
    int n;
    Graph g;
    TwoSat(int n) : n(n), g(n * 2){}
    int negate(int v){return (n + v) % (n * 2);}
    void add_if(int u,int v){
        //u -> v <=> !v -> !u
        g[u].pb(v);
        g[negate(v)].pb(negate(u));
    }
    void add_or(int u,int v){
        //u or v <=> !u -> v
        add_if(negate(u), v);
    }
    void add_nand(int u,int v){
        //u nand v <=> u -> !v
        add_if(u, negate(v));
    }
    void set_true(int v){
        //v <=> !v ->  v
        g[negate(v)].pb(v);
    }
    void set_false(int v){
        //!v <=>  v -> !v
        g[v].pb(negate(v));
    }
    vector<int> build(){
        Graph ret;
        SCC scc(g, ret);
        vector<int> res(n);
        for(int i=0;i<n;i++){
            if(scc[i] == scc[n+i]) return {};
            res[i] = scc[i] > scc[n+i];
        }
        return res;
    }
};


void solve(){
    STR(s);
    INT(x);
    int n = SZ(s);
    TwoSat TS(n);
    REP(i, n){
        if(s[i] == '1'){
            if(i + x < n and i - x > -1) TS.add_or(i - x, i + x);
            else{
                if(i + x < n) TS.set_true(i + x);
                if(i - x > -1) TS.set_true(i - x);
                if(i + x >= n and i - x < 0){
                    cout << -1 << endl;
                    return;
                }
            }
        }
        else{
            if(i + x < n) TS.set_false(i + x);
            if(i - x > -1) TS.set_false(i - x);
        }
    }
    auto res = TS.build();
    if(SZ(res) == 0) print(-1);
    else{
        REP(i, SZ(res)) cout << res[i];
        cout << endl;
    }
}

int main(){
    ios;
    INT(t);
    while(t--) solve();
}