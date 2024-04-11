#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;
#if __has_include(<atcoder/all>)
#include <atcoder/all>
using namespace atcoder;
#endif
using ll = long long;
using ld = long double;
using ull = long long;
#define endl "\n"
typedef pair<int, int> Pii;
#define REP3(i, m, n) for (int i = (m); (i) < int(n); ++ (i))
#define rep(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define ALL(x) begin(x), end(x)
#define all(s) (s).begin(),(s).end()
//#define rep2(i, m, n) for (int i = (m); i < (n); ++i)
//#define rep(i, n) rep2(i, 0, n)
#define PB push_back 
#define drep2(i, m, n) for (int i = (m)-1; i >= (n); --i)
#define drep(i, n) drep2(i, n, 0)
#define rever(vec) reverse(vec.begin(), vec.end())
#define sor(vec) sort(vec.begin(), vec.end())
//#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
#define fi first
#define se second
#define pb push_back
#define P pair<ll,ll>
#define NP next_permutation
//const ll mod = 1000000009;
//const ll mod = 998244353;
const ll mod = 1000000007;
const ll inf = 9100000000000000000ll;
const ld eps = ld(0.0000000000001);
static const long double pi = 3.141592653589793;
template<class T>void vcin(vector<T> &n){for(int i=0;i<int(n.size());i++) cin>>n[i];}
template<class T,class K>void vcin(vector<T> &n,vector<K> &m){for(int i=0;i<int(n.size());i++) cin>>n[i]>>m[i];}
template<class T>void vcout(vector<T> &n){for(int i=0;i<int(n.size());i++){cout<<n[i]<<" ";}cout<<endl;}
template<class T>void vcin(vector<vector<T>> &n){for(int i=0;i<int(n.size());i++){for(int j=0;j<int(n[i].size());j++){cin>>n[i][j];}}}
template<class T>void vcout(vector<vector<T>> &n){for(int i=0;i<int(n.size());i++){for(int j=0;j<int(n[i].size());j++){cout<<n[i][j]<<" ";}cout<<endl;}cout<<endl;}
void yes(bool a){cout<<(a?"yes":"no")<<endl;}
void YES(bool a){cout<<(a?"YES":"NO")<<endl;}
void Yes(bool a){cout<<(a?"Yes":"No")<<endl;}
void possible(bool a){ cout<<(a?"possible":"impossible")<<endl; }
void Possible(bool a){ cout<<(a?"Possible":"Impossible")<<endl; }
void POSSIBLE(bool a){ cout<<(a?"POSSIBLE":"IMPOSSIBLE")<<endl; }
template<class T>auto min(const T& a){ return *min_element(all(a)); }
template<class T>auto max(const T& a){ return *max_element(all(a)); }
template<class T,class F>void print(pair<T,F> a){cout<<a.fi<<" "<<a.se<<endl;}
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0;}
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0;}
template<class T> void ifmin(T t,T u){if(t>u){cout<<-1<<endl;}else{cout<<t<<endl;}}
template<class T> void ifmax(T t,T u){if(t>u){cout<<-1<<endl;}else{cout<<t<<endl;}}
template<typename T,typename ...Args>auto make_vector(T x,int arg,Args ...args){if constexpr(sizeof...(args)==0)return vector<T>(arg,x);else return vector(arg,make_vector<T>(x,args...));}
ll modPow(ll a, ll n, ll mod) { if(mod==1) return 0;ll ret = 1; ll p = a % mod; while (n) { if (n & 1) ret = ret * p % mod; p = p * p % mod; n >>= 1; } return ret; }
vector<ll> divisor(ll x){ vector<ll> ans; for(ll i = 1; i * i <= x; i++){ if(x % i == 0) {ans.push_back(i); if(i*i!=x){ ans.push_back(x / ans[i]);}}}sor(ans); return ans; }
ll pop(ll a){ll res=0;while(a){res+=a%2;a/=2;}return res;}
template<class T>
struct Sum{
  vector<T> data;
  Sum(const vector<T>& v):data(v.size()+1){
    for(ll i=0;i<v.size();i++) data[i+1]=data[i]+v[i];
  }
  T get(ll l,ll r) const {
    return data[r]-data[l];
  }
};
template<class T>
struct Sum2{
  vector<vector<T>> data;
  Sum2(const vector<vector<T>> &v):data(v.size()+1,vector<T>(v[0].size()+1)){
    for(int i=0;i<v.size();i++) for(int j=0;j<v[i].size();j++) data[i+1][j+1]=data[i][j+1]+v[i][j];
    for(int i=0;i<v.size();i++) for(int j=0;j<v[i].size();j++) data[i+1][j+1]+=data[i+1][j];
  }
  T get(ll x1,ll y1,ll x2,ll y2) const {
    return data[x2][y2]+data[x1][y1]-data[x1][y2]-data[x2][y1];
  }
};
 
void cincout(){
  ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
  cout<< fixed << setprecision(6);
}
struct node{
  int a,b,c,d;
};
ll f[200000];
ll get(node a){
  if(a.d){
    return f[a.a];
  }
  else{
    return a.c+f[a.a]+f[a.b];
  }
}
node one(){
  node x;
  x.a=1,x.b=1,x.c=0,x.d=1;
  return x;
}
node zero(){
  node x;
  x.a=0,x.b=0,x.c=0,x.d=0;
  return x;
}
node T(){
  node x;
  x.a=0,x.b=0,x.c=0,x.d=1;
  return x;
}
node rev(node a){
  swap(a.a,a.b);
  return a;
}
node merge(node a,node b){
  if(a.d&&b.d){
      node x;
      x.a=a.a+b.a;
      x.b=a.b+b.b;
      x.c=0;
      x.d=1;
      return x;
    }
    else if(a.d){
      node x;
      x.a=a.a+b.a;
      x.b=b.b;
      x.c=b.c;
      x.d=0;
      return x;
    }
    else if(b.d){
      node x;
      x.a=a.a;
      x.b=a.b+b.a;
      x.c=a.c;
      x.d=0;
      return x;
    }
    else{
      node x;
      x.a=a.a;
      x.b=b.b;
      x.c=a.c+b.c+f[a.b+b.a];
      x.d=0;
      return x;
    }
}
template< typename Monoid >
struct SegmentTree {
  SegmentTree(){
  }
  using F = function< Monoid(Monoid, Monoid) >;
 
  int sz;
  vector< Monoid > seg;
 
   F f;
  Monoid M1=::T();
  SegmentTree(int n, F f) : f(f) {
    sz = 1;
    while(sz < n) sz <<= 1;
   // cout<<"M1"<<" "<<M1.a<<" "<<M1.b<<" "<<M1.c<<" "<<M1.d<<endl;
    seg.assign(2 * sz, M1);
  }
  void set(int i, Monoid x) { seg[i + sz - 1] = x; }
  void update(int i, Monoid x) {
        i += sz - 1;
        seg[i] = x;
        while (i > 0) {
            i = (i - 1) / 2;  // parent
            seg[i] = f(seg[i * 2 + 1],seg[i * 2 + 2]);
        }
    }
  void debug(){
    ll now=0;
    for(auto e:seg){
     // cout<<now<<" "<<e.a<<" "<<e.b<<" "<<e.c<<" "<<e.d<<endl;
      now++;
    }
  }
    Monoid query(int a, int b) { return query_sub(a, b, 0, 0, sz); }
    Monoid query_sub(int a, int b, int k, int l, int r) {
   //  cout<<a<<" "<<b<<" "<<l<<" "<<r<<" "<<k<<endl;
        if (r <= a || b <= l) {
          //cout<<"E"<<" "<<M1.a<<" "<<M1.b<<" "<<M1.c<<" "<<M1.d<<endl;
            return M1;
        } else if (a <= l && r <= b) {
         // cout<<"SEG"<<" "<<seg[k].a<<" "<<seg[k].b<<" "<<seg[k].c<<" "<<seg[k].d<<endl;
            return seg[k];
        } else {
         //  cout<<"P"<<" "<<l<<" "<<r<<endl;
            Monoid vl = query_sub(a, b, k * 2 + 1, l, (l + r) / 2);
            Monoid vr = query_sub(a, b, k * 2 + 2, (l + r) / 2, r);
         node z=f(vl,vr);
        //  cout<<"p2"<<" "<<l<<" "<<r<<" "<<z.a<<" "<<z.b<<" "<<z.c<<" "<<z.d<<endl;
            return z;
        }
    }
};
template<typename T>
struct heavylightdecomposition{
  vector<ll> si,next,now,p;
  SegmentTree<node> S;
  vector<ll> d;
  function<T(T,T)> merge=::merge;
  void dfs3(vector<vector<ll>> &c,ll v=0,ll x=-1){
    for(auto e:c[v]){
      if(x==e) continue;
      d[e]=d[v]+1;
      dfs3(c,e,v);
    }
  }
  void dfs(vector<vector<ll>> &c2,ll v=0,ll x=-1){
    si[v]=1;
    for(auto &e:c2[v]){
      if(e==x) continue;
      p[e]=v;
      dfs(c2,e,v);
      si[v]+=si[e];
      if(si[e]>si[c2[v][0]]) swap(e,c2[v][0]);
    }
  }
  void dfs2(vector<vector<ll>> &c2,ll v,ll &nu,ll x){
    now[v]=nu;
    nu++;
  // cout<<"P"<<" "<<v<<" "<<c[v].size()<<endl;
    for(auto e:c2[v]){
      if(e==x) continue;
      if(e==c2[v][0]){
     //   cout<<"U"<<" "<<v<<" "<<e<<endl;
        next[e]=next[v];
      }
      else{
        next[e]=e;
      }
      dfs2(c2,e,nu,v);
    }
  }
  heavylightdecomposition(vector<vector<ll>> &c){
    ll n=c.size();
    si.resize(n);
    next.resize(n);
    p.resize(n);
    now.resize(n);
    vector<vector<ll>> c2(n);
    d.resize(n);
    dfs3(c);
    for(int i=0;i<n;i++){
      for(auto e:c[i]){
        if(d[e]>d[i]) c2[i].pb(e);
      }
    }
    dfs(c2);
    ll nu=0;
    dfs2(c2,0,nu,-1);
    node Y=T();
   /* for(auto e:next) cout<<e<<" ";
    cout<<endl;*/
    SegmentTree<node> seg(n,merge);
    node X=one();
    for(int i=1;i<n;i++) seg.update(i,X);
   // seg.build();
    S=seg;
    seg.debug();
   // cerr<<"X"<<" "<<S.query(1,2).a<<" "<<S.query(1,2).b<<" "<<S.query(1,2).c<<" "<<S.query(1,2).d<<endl;
  }
  ll lca(ll a,ll b){
    while(1){
      if(now[a]>now[b]){
        swap(a,b);
      }
      if(next[a]==next[b]){
        return a;
      }
      b=p[next[b]];
    }
  }
  void update(ll a,ll b){
    node X=zero();
    if(si[a]>si[b]) S.update(now[b],X);
    else S.update(now[a],X);
  }
  node query(ll a,ll b){
  //  cout<<"K"<<" "<<a<<" "<<b<<endl;
    int w=lca(a,b);
    node L=::T();
  //  cout<<L.d<<endl;
    while(next[a]!=next[w]){
      L=merge(L,rev(S.query(now[next[a]],now[a]+1)));
      a=p[next[a]];
    }
    L=merge(L,rev(S.query(now[w]+1,now[a]+1)));
  //  cout<<L.a<<" "<<L.b<<" "<<L.c<<" "<<L.d<<endl;
    node R=::T();
   // cout<<R.d<<endl;
   // cout<<"N"<<" "<<next[b]<<" "<<next[w]<<endl;
    while(next[b]!=next[w]){
    //  cout<<now[next[b]]<<" "<<now[b]<<" "<<S.query(now[next[b]],now[b]+1).a<<endl;
      R=merge(S.query(now[next[b]],now[b]+1),R);
      b=p[next[b]];
    }
    R=merge(S.query(now[w]+1,now[b]+1),R);
  //  cout<<R.a<<" "<<R.b<<" "<<R.c<<" "<<R.d<<endl;
    node X=merge(L,R);
   // cout<<X.a<<" "<<X.b<<" "<<X.c<<" "<<X.d<<endl;
    return X;
  }
};
int main() {
  cincout();
  ll n,q;
  cin>>n>>q;
  for(int i=1;i<=n-1;i++) cin>>f[i];
  vector<vector<ll>> c(n);
  vector<pair<P,P>> u;//{a,b,c,d} -> a () b -> (0) or query(1) c,d ->  or 
  for(int i=0;i<n-1;i++){
    ll x,y,z;
    cin>>x>>y>>z;
    x--;
    y--;
    c[x].pb(y);
    c[y].pb(x);
    u.pb({{z,inf},{x,y}});
  }
  for(int i=0;i<q;i++){
    ll x,y,z;
    cin>>x>>y>>z;
    x--;
    y--;
    u.pb({{z,i+1},{x,y}});
  }
  vector<ll> ans(q);
  sor(u);
  heavylightdecomposition<node> HLD(c);
  for(auto e:u){
   // cout<<e.fi.fi<<" "<<e.fi.se<<endl;
    if(e.fi.se==inf){
      ll x=e.se.fi,y=e.se.se;
      HLD.update(x,y);
    }
    else{
      ll x=e.se.se,y=e.se.fi;
      node q=HLD.query(x,y);
      //cerr<<q.a<<" "<<q.b<<" "<<q.c<<" "<<q.d<<endl;
      ans[e.fi.se-1]=get(q);
    }
  }
  for(auto e:ans) cout<<e<<endl;
}