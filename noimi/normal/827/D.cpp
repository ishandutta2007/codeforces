#pragma region Macros
#pragma GCC optimize("O3")

#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define rep2(i,a,b) for(ll i=a;i<=b;++i)
#define rep(i,n) for(ll i=0;i<n;++i)
#define rep3(i,a,b) for(ll i=a;i>=b;--i)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pb push_back
#define eb emplace_back
#define vi vector<int>
#define vec vector<int>
#define vll vector<ll>
#define vpi vector<pii>
#define vpll vector<pll>
#define overload2(_1,_2,name,...) name
#define vv(a,b) vector<vector<int>>(a,vector<int>(b))
#define vv2(a,b,c) vector<vector<int>>(a,vector<int>(b,c))
#define vvl(a,b) vector<vector<ll>>(a,vector<ll>(b))
#define vvl2(a,b,c) vector<vector<ll>>(a,vector<ll>(b,c))
#define vvv(a,b,c) vector<vv(b,c)>(a)
#define vvv2(a,b,c,d) vector<vv(b,c,d)>(a)
#define vvvl(a,b,c) vector<vvl(b,c)>(a)
#define vvvl2(a,b,c,d) vector<vvl(b,c,d)>(a)
#define fi first
#define se second
#define all(c) begin(c),end(c)
#define ios ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define lb(c,x) distance((c).begin(),lower_bound(all(c),(x)))
#define ub(c,x) distance((c).begin(),upper_bound(all(c),(x)))
using namespace std;
template<class T> using pq = priority_queue<T>;
template<class T> using pqg = priority_queue<T,vector<T>,greater<T>>;
#define Size(c) (int)(c).size()
#define INT(...) int __VA_ARGS__;IN(__VA_ARGS__)
#define LL(...) ll __VA_ARGS__;IN(__VA_ARGS__)
#define ULL(...) ull __VA_ARGS__;IN(__VA_ARGS__)
#define STR(...) string __VA_ARGS__;IN(__VA_ARGS__)
#define CHR(...) char __VA_ARGS__;IN(__VA_ARGS__)
#define DBL(...) double __VA_ARGS__;IN(__VA_ARGS__)
#define LD(...) ld __VA_ARGS__;IN(__VA_ARGS__)
#define VEC(type,name,size) vector<type> name(size);IN(name)
#define VV(type,name,h,w) vector<vector<type>>name(h,vector<type>(w));IN(name)
int scan(){ return getchar(); }
void scan(int& a){ cin>>a; }
void scan(long long& a){ cin>>a; }
void scan(char &a){cin>>a;}
void scan(double &a){ cin>>a; }
void scan(long double& a){ cin>>a; }
void scan(char a[]){ scanf("%s", a); }
void scan(string& a){ cin >> a; }
template<class T> void scan(vector<T>&);
template<class T, size_t size> void scan(array<T, size>&);
template<class T, class L> void scan(pair<T, L>&);
template<class T, size_t size> void scan(T(&)[size]);
template<class T> void scan(vector<T>& a){ for(auto& i : a) scan(i); }
template<class T> void scan(deque<T>& a){ for(auto& i : a) scan(i); }
template<class T, size_t size> void scan(array<T, size>& a){ for(auto& i : a) scan(i); }
template<class T, class L> void scan(pair<T, L>& p){ scan(p.first); scan(p.second); }
template<class T, size_t size> void scan(T (&a)[size]){ for(auto& i : a) scan(i); }
template<class T> void scan(T& a){ cin >> a; }
void IN(){}
template <class Head, class... Tail> void IN(Head& head, Tail&... tail){ scan(head); IN(tail...); }
string stin() {string s;cin>>s;return s;}
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}
vi iota(int n){vi a(n);iota(all(a),0);return a;}
template<class T> void UNIQUE(vector<T> &x){sort(all(x));x.erase(unique(all(x)),x.end());}
int in() {int x;cin>>x;return x;}
ll lin() {unsigned long long x;cin>>x;return x;}
void print(){putchar(' ');}
void print(bool a){cout<<a;}
void print(int a){cout<<a;}
void print(long long a){cout<<a;}
void print(char a){cout<<a;}
void print(string &a){cout<<a;}
void print(double a){cout<<a;}
template<class T> void print(const vector<T>&);
template<class T, size_t size> void print(const array<T, size>&);
template<class T, class L> void print(const pair<T, L>& p);
template<class T, size_t size> void print(const T (&)[size]);
template<class T> void print(const vector<T>& a){ if(a.empty()) return; print(a[0]); for(auto i = a.begin(); ++i != a.end(); ){ cout<<" "; print(*i); } cout<<endl;}
template<class T> void print(const deque<T>& a){ if(a.empty()) return; print(a[0]); for(auto i = a.begin(); ++i != a.end(); ){ cout<<" "; print(*i); } }
template<class T, size_t size> void print(const array<T, size>& a){ print(a[0]); for(auto i = a.begin(); ++i != a.end(); ){ cout<<" "; print(*i); } }
template<class T, class L> void print(const pair<T, L>& p){ cout<<'(';print(p.first); cout<<","; print(p.second);cout<<')'; }
template<class T> void print(set<T> &x){for(auto e:x)print(e),cout<<" ";cout<<endl;}
template<class T, size_t size> void print(const T (&a)[size]){ print(a[0]); for(auto i = a; ++i != end(a); ){ cout<<" "; print(*i); } }
template<class T> void print(const T& a){ cout << a; }
int out(){ putchar('\n'); return 0; }
template<class T> int out(const T& t){ print(t); putchar('\n'); return 0; }
template<class Head, class... Tail> int out(const Head& head, const Tail&... tail){ print(head); putchar(' '); out(tail...); return 0; }
ll gcd(ll a, ll b){ while(b){ ll c = b; b = a % b; a = c; } return a; }
ll lcm(ll a, ll b){ if(!a || !b) return 0; return a * b / gcd(a, b); }
vector<pll> factor(ll x){ vector<pll> ans; for(ll i = 2; i * i <= x; i++) if(x % i == 0){ ans.push_back({i, 1}); while((x /= i) % i == 0) ans.back().second++; } if(x != 1) ans.push_back({x, 1}); return ans; }
vector<int> divisor(int x){ vector<int> ans; for(int i=1;i*i<=x;i++)if(x%i==0){ans.pb(i);if(i*i!=x)ans.pb(x/i);} return ans;}
int popcount(ll x){return __builtin_popcountll(x);}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rnd(int n){return uniform_int_distribution<int>(0, n-1)(rng);}
#define endl '\n'

#ifdef _LOCAL
    #undef endl
    #define debug(x) cout<<#x<<": ";print(x);cout<<endl;
    void err(){}
    template<class T> void err(const T& t){ print(t);  cout<<" ";}
    template<class Head, class... Tail> void err(const Head& head, const Tail&... tail){ print(head); putchar(' '); out(tail...); }
#else
    #define debug(x)
    template<class... T> void err(const T&...){}
#endif
#pragma endregion

template< typename T >
struct edge{
    int from, to,id;
    T cost;
    edge(int to,T cost) : from(-1), to(to), cost(cost){}
    edge(int from,int to,T cost) : from(from), to(to), cost(cost){}
    edge(int from,int to,T cost,int id):from(from),to(to),cost(cost),id(id){}
    edge &operator=(const int &x) {
        to = x;
        return *this;
    }
    bool operator<(edge &rhs)const{
        return cost < rhs.cost;
    }
    operator int() const{ return to;}
};

template< typename T >
using Edges = vector< edge< T > >;
template< typename T >
using WeightedTree = vector< Edges<T>>;
using tree = vector< vector<int> >;

tree make(int n,int offset = 1){
    tree res(n);
    for(int i = 0;i < n-1; i++){
        int a,b; cin >> a >> b;
        a -= offset,b -= offset;
        res[a].emplace_back(b);
        res[b].emplace_back(a);
    }
    return res;
}
template< typename T >
WeightedTree<T> make2(int n, int offset = 1){
    WeightedTree<T> res(n);
    for(int i = 0;i < n-1 ; i++){
        int a,b ; cin >> a >> b;
        a -= offset, b -= offset;
        T c; cin >> c;
        res[a].emplace_back(b,c);
        res[b].emplace_back(a,c);
    }
    return res;
}

struct UnionFind {
  vector< int > data;
 
  UnionFind(int sz) {
    data.assign(sz, -1);
  }
 
  bool unite(int x, int y) {
    x = find(x), y = find(y);
    if(x == y) return (false);
    if(data[x] > data[y]) swap(x, y);
    data[x] += data[y];
    data[y] = x;
    return (true);
  }
 
  int find(int k) {
    if(data[k] < 0) return (k);
    return (data[k] = find(data[k]));
  }
 
  int size(int k) {
    return (-data[find(k)]);
  }
};

template< typename G >
struct HLDecomposition{
    G &g;
    vector<int> sz, in, out, head, rev, par;

    HLDecomposition(G &g):
        g(g), sz(g.size()), in(g.size()), out(g.size()), head(g.size()), rev(g.size()), par(g.size()) {}
    
    void dfs_sz(int idx, int p){
        par[idx] = p;
        sz[idx] = 1;
        if(g[idx].size() and g[idx][0] == p) swap(g[idx][0], g[idx].back());
        for(auto &to: g[idx]){
            if(to == p) continue;
            dfs_sz(to,idx);
            sz[idx] += sz[to];
            if(sz[g[idx][0]] < sz[to]) swap(g[idx][0], to);
        }
    }

    void dfs_hld(int idx, int par, int &times){
        in[idx] = times++;
        rev[in[idx]] = idx;
        for(auto &to : g[idx]){
            if(to == par) continue;
            head[to] = (g[idx][0] == to ? head[idx] :to);
            dfs_hld(to,idx,times);
        }
        out[idx] = times;
    }

    template< typename T >
    void dfs_hld(int idx, int par, int &times,vector<T> &v){
        in[idx] = times++;
        rev[in[idx]] = idx;
        for(auto &to : g[idx]){
            if(to == par) {
                v[in[idx]] = to.cost;
                continue;
            }
            head[to] = (g[idx][0] == to ? head[idx] :to);
            dfs_hld(to,idx,times,v);
        }
        out[idx] = times;
    }

    void build(){
        dfs_sz(0,-1);
        int t = 0;
        dfs_hld(0,-1,t);
    }

    template< typename T >
    vector< T > build(){
        dfs_sz(0,-1);
        int t = 0;
        vector< T > res(g.size());
        dfs_hld<T>(0,-1,t,res);
        return res;
    }


    int la(int v,int k){
        while(1){
            int u = head[v];
            if(in[v] - k >= in[u]) return rev[in[v] - k];
            k -= in[v] - in[u] + 1;
            v = par[u];
        }
    }

    int lca(int u,int v){
        for(;; v = par[head[v]]){
            if(in[u] > in[v]) swap(u,v);
            if(head[u] == head[v]) return u;
        }
    }

    template< typename T, typename Q, typename F >
    T query(int u, int v, const T &e, const Q &q, const F &f, bool edge = false){
        T l = e, r = e;
        for(;; v = par[head[v]]){
            if(in[u] > in[v]) swap(u,v), swap(l,r);
            if(head[u] == head[v]) break;
            l = f(q(in[head[v]], in[v] + 1), l);
        }
        return f(f(q(in[u] + edge,in[v] + 1), l), r);
    }

    template< typename Q >
    void add(int u, int v, const Q &q, bool edge = false){
        for(;; v = par[head[v]]){
            if(in[u] > in[v]) swap(u,v);
            if(head[u] == head[v]) break;
            q(in[head[v]], in[v] + 1);
        }
        q(in[u] + edge, in[v] + 1);
    }
};

template< typename Monoid >
struct SegmentTree {
  using F = function< Monoid(Monoid, Monoid) >;

  int sz;
  vector< Monoid > seg;

  const F f;
  const Monoid M1;

  SegmentTree(int n, const F f, const Monoid &M1) : f(f), M1(M1) {
    sz = 1;
    while(sz < n) sz <<= 1;
    seg.assign(2 * sz, M1);
  }

  void set(int k, const Monoid &x) {
    seg[k + sz] = x;
  }

  void build() {
    for(int k = sz - 1; k > 0; k--) {
      seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]);
    }
  }

  void update(int k, const Monoid &x) {
    k += sz;
    seg[k] = x;
    while(k >>= 1) {
      seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]);
    }
  }

  Monoid query(int a, int b) {
    Monoid L = M1, R = M1;
    for(a += sz, b += sz; a < b; a >>= 1, b >>= 1) {
      if(a & 1) L = f(L, seg[a++]);
      if(b & 1) R = f(seg[--b], R);
    }
    return f(L, R);
  }

  Monoid operator[](const int &k) const {
    return seg[k + sz];
  }

  template< typename C >
  int find_subtree(int a, const C &check, Monoid &M, bool type) {
    while(a < sz) {
      Monoid nxt = type ? f(seg[2 * a + type], M) : f(M, seg[2 * a + type]);
      if(check(nxt)) a = 2 * a + type;
      else M = nxt, a = 2 * a + 1 - type;
    }
    return a - sz;
  }

  // [a,x] x
  template< typename C >
  int find_first(int a, const C &check) {
    Monoid L = M1;
    if(a <= 0) {
      if(check(f(L, seg[1]))) return find_subtree(1, check, L, false);
      return -1;
    }
    int b = sz;
    for(a += sz, b += sz; a < b; a >>= 1, b >>= 1) {
      if(a & 1) {
        Monoid nxt = f(L, seg[a]);
        if(check(nxt)) return find_subtree(a, check, L, false);
        L = nxt;
        ++a;
      }
    }
    return -1;
  }

  // [x,b) x
  template< typename C >
  int find_last(int b, const C &check) {
    Monoid R = M1;
    if(b >= sz) {
      if(check(f(seg[1], R))) return find_subtree(1, check, R, true);
      return -1;
    }
    int a = sz;
    for(b += sz; a < b; a >>= 1, b >>= 1) {
      if(b & 1) {
        Monoid nxt = f(seg[--b], R);
        if(check(nxt)) return find_subtree(b, check, R, true);
        R = nxt;
      }
    }
    return -1;
  }
  void print(int n){
      for(int i = 0; i < n; i++){
          cerr << seg[i + sz] << " " ;
      }cerr << endl;
  }
};


signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);cout<<fixed<<setprecision(15);
    INT(n,m);
    Edges<ll> E;
    rep(i,m){
        INT(x,y,c);
        E.eb(x-1,y-1,c,i);
    }
    auto F = E;
    sort(all(E));
    UnionFind uf(n);
    WeightedTree<ll> g(n);
    vi used(m);
    for(auto e:E){
        if(uf.unite(e.from,e.to)){
            g[e.from].eb(e);
            swap(e.from,e.to);
            g[e.from].eb(e);
            used[e.id] = true;
        }
    }
    HLDecomposition<WeightedTree<ll>> hld(g);
    vector<int> v = hld.build<int>();
    vector<vi> IN(n),OUT(n);
    rep(i,m){
        if(!used[i]){
            int r = hld.lca(F[i].from,F[i].to);
            if(r == F[i].from){
                IN[F[i].to].pb(F[i].cost);
                OUT[r].eb(F[i].cost);
            }
            else if(r == F[i].to){
                IN[F[i].from].eb(F[i].cost);
                OUT[r].eb(F[i].cost);
            }
            else{
                IN[F[i].from].eb(F[i].cost);
                IN[F[i].to].eb(F[i].cost);
                rep(_,2)OUT[r].eb(F[i].cost);
            }
        }
    }
    vi ans(m,-1);
    auto dfs = [&](auto &&f,int x,int p,int id,int cost,multiset<int> &s)->void{
        for(auto e:g[x]){
            if(e==p) continue;
            multiset<int> res;
            f(f,e,x,e.id,e.cost,res);
            if(res.size()>s.size())swap(res,s);
            for(auto &e:res) s.emplace(e);
        }
        for(auto &e:OUT[x]) s.erase(s.lower_bound(e));
        for(auto &e:IN[x]) s.emplace(e);
        if(p!=-1){
            if(s.empty()){
                ans[id] = -1;
                return;
            }
            int mi = *s.begin();
            ans[id] = mi-1;
        }
    };
    multiset<int> res;
    dfs(dfs,0,-1,0,0,res);
    SegmentTree<int> seg(n,[](int x,int y){return max(x,y);},0);
    rep(i,n)seg.set(i,v[i]);
    seg.build();
    rep(i,m){
        if(used[i]) continue;
        int a = F[i].from,b = F[i].to;
        ans[i] = hld.query(a,b,0,[&](int x,int y){return seg.query(x,y);},[](int x,int y){return max(x,y);},true) - 1;
    }
    print(ans);
}