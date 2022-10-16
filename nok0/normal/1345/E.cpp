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

Graph G, RG;
V<int> used, rused;
void dfs1(int k){
    if(used[k]) return;
    used[k] = 1;
    for(auto v : G[k]) dfs1(v);
}
bool dfs(int k){
    for(auto v : G[k]) dfs1(v);
    bool res = !used[k];
    used[k] = 1;
    return res;
}
void rdfs1(int k){
    if(rused[k]) return;
    rused[k] = 1;
    for(auto v : RG[k]) rdfs1(v);
}
bool rdfs(int k){
    for(auto v : RG[k]) rdfs1(v);
    bool res = !rused[k];
    rused[k] = 1;
    return res;
}

int main(){
    INT(n, m);
    G.resize(n);
    RG.resize(n);
    used.resize(n, 0);
    rused.resize(n, 0);
    V<> h(n, 0);
    REP(i, m){
        LL(u, v); u--; v--;
        G[u].pb(v);
        RG[v].pb(u);
        h[v]++;
    }
    stack<int> st;
    REP(i, n) if(!h[i]) st.push(i);
    //toporogical sort
    V<> t_sort;
    while(SZ(st)) {
        ll p = st.top(); st.pop();
        t_sort.push_back(p);
        for(auto v: G[p]) {
            h[v]--;
            if(!h[v]) st.push(v);
        }
    }
    //if Graph is DAG, return true. Else return false.
    auto is_DAG = [&](){return SZ(t_sort) == n;};
    fin(!is_DAG(), -1);
    V<char> res(n);
    int cnt = 0;
    REP(i, n){
        bool x = dfs(i), y = rdfs(i);
        if(x and y) res[i] = 'A', cnt++;
        else res[i] = 'E';
    }
    print(cnt);
    for(auto v : res) cout << v;
    cout << endl;
}