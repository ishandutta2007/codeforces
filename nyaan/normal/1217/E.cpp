#include <bits/stdc++.h>
#define whlie while
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define rep(i,N) for(int i = 0; i < (N); i++)
#define repr(i,N) for(int i = (N) - 1; i >= 0; i--)
#define rep1(i,N) for(int i = 1; i <= (N) ; i++)
#define repr1(i,N) for(int i = (N) ; i > 0 ; i--)
#define each(x,v) for(auto& x : v)
#define all(v) (v).begin(),(v).end()
#define sz(v) ((int)(v).size())
#define vrep(v,it) for(auto it = v.begin(); it != v.end(); it++)
#define vrepr(v,it) for(auto it = v.rbegin(); it != v.rend(); it++)
#define ini(...) int __VA_ARGS__; in(__VA_ARGS__)
#define inl(...) ll __VA_ARGS__; in(__VA_ARGS__)
#define ins(...) string __VA_ARGS__; in(__VA_ARGS__)
using namespace std; void solve();
using ll = long long; using vl = vector<ll>;
using vi = vector<int>; using vvi = vector< vector<int> >;
constexpr int inf = 1001001001;
constexpr ll infLL = (1LL << 61) - 1;
struct IoSetupNya {IoSetupNya() { cin.tie(nullptr); ios::sync_with_stdio(false); cout << fixed << setprecision(15); cerr << fixed << setprecision(7);} } iosetupnya;
template<typename T, typename U> inline bool amin(T &x, U y) { return (y < x) ? (x = y, true) : false; }
template<typename T, typename U> inline bool amax(T &x, U y) { return (x < y) ? (x = y, true) : false; }
template<typename T, typename U> ostream& operator <<(ostream& os, const pair<T, U> &p) { os << p.first << " " << p.second; return os; }
template<typename T, typename U> istream& operator >>(istream& is, pair<T, U> &p) { is >> p.first >> p.second; return is; }
template<typename T> ostream& operator <<(ostream& os, const vector<T> &v) { int s = (int)v.size(); rep(i,s) os << (i ? " " : "") << v[i]; return os; }
template<typename T> istream& operator >>(istream& is, vector<T> &v) { for(auto &x : v) is >> x; return is; }
void in(){} template <typename T,class... U> void in(T &t,U &...u){ cin >> t; in(u...);}
void out(){cout << "\n";} template <typename T,class... U> void out(const T &t,const U &...u){ cout << t; if(sizeof...(u)) cout << " "; out(u...);}
template<typename T>void die(T x){out(x); exit(0);}
#ifdef NyaanDebug
  #include "NyaanDebug.h"
  #define trc(...) do { cerr << #__VA_ARGS__ << " = "; dbg_out(__VA_ARGS__);} while(0)
  #define trca(v,...) do { cerr << #v << " = "; array_out(v , __VA_ARGS__ );} while(0)
#else
  #define trc(...)
  #define trca(...)
  int main(){solve();}
#endif

using P = pair<ll,ll>;
using vp = vector<P>;
constexpr int MOD = /**/ 1000000007; //*/ 998244353;
/////////////////

// 
template<typename T,typename F>
struct ST{

  int size;
  vector<T> seg;
  const F func;
  const T UNIT;
  
  ST(int N,F func , T UNIT): func(func) , UNIT(UNIT) {
    size = 1;
    while(size < N) size <<= 1;
    seg.assign(2 * size, UNIT);
  }

  ST(const vector<T> &v,F func , T UNIT) : func(func) , UNIT(UNIT){
    // initialize
    int N = (int)v.size();
    size = 1;
    while(size < N) size <<= 1;
    seg.assign(2 * size , UNIT);
    // set
    for(int i = 0; i < N; i++){
      seg[i + size] = v[i];
    }
    build();
  }

  void set(int k, T x){
    seg[k + size] = x;
  }

  void build(){
    for(int k = size-1; k > 0; k--){
      seg[k] = func(seg[2 * k] , seg[2 * k + 1] );
    }
  }
  
  void update(int k, T x){
    k += size; seg[k] = x;
    while(k >>= 1){
      seg[k] = func( seg[2 * k] , seg[2 * k + 1] );
    }
  }
  
  // [a,b)
  T query(int a, int b){
    T L = UNIT, R = UNIT;
    for(a+=size,b+=size; a<b; a>>=1,b>>=1){
      if(a & 1) L = func(L,seg[a++]);
      if(b & 1) R = func(seg[--b],R);
    }
    return func(L, R);
  }

  T operator[](const int &k) const{
    return seg[k + size];
  }

};

void solve(){
  ini(N,Q);
  vl v(N); in(v);
  auto f = [](P a,P b){
    ll m1 = min(a.fi , b.fi);
    ll m2 = min( (a.fi + b.fi - m1) , min(a.se,b.se) );
    return P(m1,m2);
  };
  P UNIT = P(infLL,infLL);
  using SEG = ST<P , decltype(f)>;
  vector<SEG> seg(10 , SEG(N , f , UNIT));

  rep(i,N){
    ll cur = v[i];
    rep(j , 10){
      if(cur % 10){
        seg[j].set(i , P(v[i] , infLL) );
      }
      cur /= 10;
    }
  }
  rep(j,10) seg[j].build();
  trc("HUGA");
  rep(hoge,Q){
    ini(cmd);
    trc(hoge);
    if(cmd == 2){
      ini(i , j); i--;
      ll ans = infLL;
      rep(k,10){
        auto cur = seg[k].query(i , j);
        amin(ans , cur.fi + cur.se);
      }
      out(ans >= infLL ? -1 : ans);
    }
    else{
      ini(i); inl(x); i--;
      ll cur = x;
      rep(j,10){
        if(cur % 10) seg[j].update(i , P(x , infLL));
        else seg[j].update(i , P(infLL , infLL) );
        cur /= 10;
      }
    }

  }
  
}