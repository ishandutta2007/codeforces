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
int rnd(int n){return uniform_int_distribution<int>(0, n)(rng);}
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
struct BinaryIndexedTree {
  vector< T > data;

  BinaryIndexedTree(int sz) {
    data.assign(++sz, 0);
  }

  T sum(int k) {
    T ret = 0;
    for(++k; k > 0; k -= k & -k) ret += data[k];
    return (ret);
  }

  void add(int k, T x) {
    for(++k; k < data.size(); k += k & -k) data[k] += x;
  }
};
template< typename structure_t, typename get_t, typename update_t >
struct SegmentTree2DCompressed {

  using merge_f = function< get_t(get_t, get_t) >;
  using range_get_f = function< get_t(structure_t &, int, int) >;
  using update_f = function< void(structure_t &, int, update_t) >;

  int sz;
  vector< structure_t > seg;
  const merge_f f;
  const range_get_f g;
  const update_f h;
  const get_t identity;
  vector< vector< int > > LL, RR;
  vector< vector< int > > beet;

  SegmentTree2DCompressed(int n, const merge_f &f, const range_get_f &g, const update_f &h, const get_t &identity)
      : f(f), g(g), h(h), identity(identity) {
    sz = 1;
    while(sz < n) sz <<= 1;
    beet.resize(2 * sz);
    LL.resize(2 * sz);
    RR.resize(2 * sz);
  }

  void update(int a, int x, update_t z, int k, int l, int r) {
    if(r <= a || a + 1 <= l) return;
    if(a <= l && r <= a + 1) return h(seg[k], x, z);
    update(a, LL[k][x], z, 2 * k + 0, l, (l + r) >> 1);
    update(a, RR[k][x], z, 2 * k + 1, (l + r) >> 1, r);
    return h(seg[k], x, z);
  }

  void update(int x, int y, update_t z) {
    y = lower_bound(begin(beet[1]), end(beet[1]), y) - begin(beet[1]);
    return update(x, y, z, 1, 0, sz);
  }

  get_t query(int a, int b, int x, int y, int k, int l, int r) {
    if(a >= r || b <= l) return identity;
    if(a <= l && r <= b) return g(seg[k], x, y);
    return f(query(a, b, LL[k][x], LL[k][y], 2 * k + 0, l, (l + r) >> 1),
             query(a, b, RR[k][x], RR[k][y], 2 * k + 1, (l + r) >> 1, r));
  }

  get_t query(int a, int b, int x, int y) {
    x = lower_bound(begin(beet[1]), end(beet[1]), x) - begin(beet[1]);
    y = lower_bound(begin(beet[1]), end(beet[1]), y) - begin(beet[1]);
    return query(a, b, x, y, 1, 0, sz);
  }

  void build() {
    for(int k = (int) beet.size() - 1; k >= sz; k--) {
      sort(begin(beet[k]), end(beet[k]));
      beet[k].erase(unique(begin(beet[k]), end(beet[k])), end(beet[k]));
    }
    for(int k = sz - 1; k > 0; k--) {
      beet[k].resize(beet[2 * k + 0].size() + beet[2 * k + 1].size());
      merge(begin(beet[2 * k + 0]), end(beet[2 * k + 0]), begin(beet[2 * k + 1]), end(beet[2 * k + 1]), begin(beet[k]));
      beet[k].erase(unique(begin(beet[k]), end(beet[k])), end(beet[k]));
      LL[k].resize(beet[k].size() + 1);
      RR[k].resize(beet[k].size() + 1);
      int tail1 = 0, tail2 = 0;
      for(int i = 0; i < beet[k].size(); i++) {
        while(tail1 < beet[2 * k + 0].size() && beet[2 * k + 0][tail1] < beet[k][i]) ++tail1;
        while(tail2 < beet[2 * k + 1].size() && beet[2 * k + 1][tail2] < beet[k][i]) ++tail2;
        LL[k][i] = tail1, RR[k][i] = tail2;
      }
      LL[k][beet[k].size()] = (int) beet[2 * k + 0].size();
      RR[k][beet[k].size()] = (int) beet[2 * k + 1].size();
    }
    for(int k = 0; k < beet.size(); k++) {
      seg.emplace_back(structure_t(beet[k].size()));
    }
  }

  void preupdate(int x, int y) {
    beet[x + sz].push_back(y);
  }
};

using BIT = BinaryIndexedTree< int >;
auto f = [](int x, int y) { return x + y; };
auto g = [](BIT &k, int x, int y) { return k.sum(y - 1) - k.sum(x - 1); };
auto h = [](BIT &k, int x, int y) { k.add(x, y); };





signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);cout<<fixed<<setprecision(15);
    INT(n,m);
    vector<set<int>> a(n);
    vi mem(n);
    rep(i,n){
        int x=in()-1;
        mem[i] = x;
        a[x].emplace(i);
    }
    using BIT = BinaryIndexedTree< ll >;
    auto g = [](BIT &k, int x, int y) { return k.sum(y - 1) - k.sum(x - 1); };
    auto h = [](BIT &k, int x, ll y) { k.add(x, y); };

    SegmentTree2DCompressed< BIT, ll,ll > seg(100002, plus<ll>(), g, h, 0LL);
    rep(i,n){
        bool f = true;
        int pre;
        if(a[i].empty()) continue;
        for(auto e:a[i]){
            if(f) pre = e,f=false;
            else{
                seg.preupdate(pre,e);
                pre = e;
            }
        }
    }
    struct query{
        int id,l,r,z;
        query(int l,int r,int z,int id):id(id),l(l),r(r),z(z){}
        query(int l,int r,int z):id(0),l(l),r(r),z(z){}
    };
    vector<query> Q;
    auto add = [&](int x,int y,int z){
        query q(x,y,z);
        Q.push_back(q);
    };
    auto b = a;
    while(m--){
        int id = in();
        if(id == 1){
            int p = in() - 1;
            int y = mem[p];
            int x = in() - 1;
            mem[p] = x;
            auto it = a[y].find(p);
            if(it != a[y].begin()){
                it--;
                int pre = *it;
                seg.preupdate(pre,p);
                add(pre,p,pre-p);
                it++;it++;
                if(it != a[y].end()) {
                    seg.preupdate(pre,*it);
                    add(pre,*it,*it-pre);
                    add(p,*it,p-*it);
                }
            }
            else{
                it++;
                if(it != a[y].end()){
                    add(p,*it,p-*it);
                }
            }
            a[y].erase(p);
            it = a[x].lower_bound(p);
            if(it != a[x].begin()){
                it--;
                int pre = *it;
                seg.preupdate(*it,p);
                add(*it,p,p-*it);
                it++;
                if(it != a[x].end()) {
                    seg.preupdate(p,*it);
                    add(pre,*it,pre-*it);
                    add(p,*it,*it-p);
                }
            }
            else if(it != a[x].end()){
                seg.preupdate(p,*it);
                add(p,*it,*it-p);
            }
            a[x].emplace(p);
        }
        else{
            int l=in()-1,r=in();
            Q.emplace_back(l,r,0,1);
        }
    }
    seg.build();
    rep(i,n){
        bool f = true;
        int pre;
        if(b[i].empty()) continue;
        for(auto e:b[i]){
            if(f) pre = e,f=false;
            else{
                // cout << pre << " " << e << " " << e-pre<<endl;
                seg.update(pre,e,e-pre);
                pre = e;
            }
        }
    }
    for(auto q:Q){
        if(q.id){
            cout << seg.query(q.l,q.r,q.l,q.r)<<endl;
        }
        else{
            // cout << q.l<<" "<<q.r<<" " <<q.z<<endl;
            seg.update(q.l,q.r,q.z);
        }
    }
}