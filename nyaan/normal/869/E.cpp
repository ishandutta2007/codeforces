#pragma GCC optimize("O2")
#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstdarg>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <deque>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>

#define whlie while
#define retunr return
#define reutrn return
#define reutnr return
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define inf 1001001001
#define MOD 1000000007
#define infLL (1LL << 61)
#define FOR(i,a,b) for(int (i)=(int)(a); (i)<(int)(b); (i)++) // [a,b)
#define rep(i,N) FOR((i), 0, (int)(N)) // [0,N)
#define FORR(i,a,b) for(int (i)=(int)(b) - 1; (i)>=(int)(a); (i)--)
#define repr(i,N) FORR((i), 0, (int)(N))
#define each(x,v) for(auto &x : v)
#define all(v) (v).begin(),(v).end()
#define sz(v) ((int)(v).size())
#define vrep(v,it) for(auto it=v.begin();it!=v.end();it++)
#define vrepr(v,it) for(auto it=v.rbegin();it!=v.rend();it++)
#define ini(...) int __VA_ARGS__; in(__VA_ARGS__)
#define inl(...) ll __VA_ARGS__; in(__VA_ARGS__)
#define inc(...) char __VA_ARGS__; in(__VA_ARGS__)
#define ins(...) string __VA_ARGS__; in(__VA_ARGS__)
#define ind(...) double __VA_ARGS__; in(__VA_ARGS__)
#define inpii(...) pii __VA_ARGS__; in(__VA_ARGS__)
#define rand mtrand
#define randinit random_device seed_gen; mt19937_64 mtrand(seed_gen())

#ifdef LOCAL  
  #define trc(...) do { cout << #__VA_ARGS__ << " = "; dbg_out(__VA_ARGS__);} while(0)
  #define stopif(val) assert( !(val) )
  #define trcv(v,...) do { cout << #v << " = "; vector_debug(v , ##__VA_ARGS__);cout << endl;} while(0)
#else
  #define trc(...)
  #define stopif(...)
  #define trcv(...)
#endif

using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vs = vector<string>;
using vpii = vector<pii>;
using vvi = vector< vector<int> >;

struct IoSetupNya {IoSetupNya() { cin.tie(nullptr); ios::sync_with_stdio(false); cout << fixed << setprecision(15); cerr << fixed << setprecision(15);} } iosetupnya;
/* 
int gcd(int a, int b){if(a>b) swap(a,b); return a==0 ? b : gcd(b%a,a);} ll gcd(ll a, ll b){if(a>b) swap(a,b); return a==0 ? b : gcd(b%a,a);}
ll lcm(int a, int b){return (1LL * a / gcd(a,b)) * b;} ll lcm(ll a, ll b){return (a / gcd(a,b)) * b;}
*/
inline ll pow(int a, int b){ll ans = 1; rep(i,b) ans *= a; return ans;} inline ll pow(ll a, ll b){ll ans = 1; rep(i,b) ans*= a; return ans;}
inline ll pow(int a, ll b){ll ans = 1; rep(i,b) ans *= a; return ans;} inline ll pow(ll a, int b){ll ans = 1; rep(i,b) ans*= a; return ans;}
template<typename T, typename U> inline bool amin(T &x, U y) { return (y < x) ? (x = y, true) : false; }
template<typename T, typename U> inline bool amax(T &x, U y) { return (x < y) ? (x = y, true) : false; }
template<typename C> inline void _cin(C &c){cin >> c;}
template<typename T,typename U> inline void _cin(pair<T,U> &p){cin >> p.fi; cin >> p.se;}
template<typename C> inline void _cout(const C &c){cout << c;}
template<typename T,typename U> inline void _cout(const pair<T,U> &p){cout << p.fi << ' ' << p.se;}
void in(){} template <typename T,class... U> void in(T &t,U &...u){ _cin(t); in(u...);}
void out(){cout << "\n";} template <typename T,class... U> void out(const T &t,U ...u){ _cout(t); if(sizeof...(u)) cout << ' '; out(u...);}
template<typename C> inline void in(vector<C> &v,int N=-1){if(sz(v) != 0){int M=(N == -1) ? sz(v) : N; rep(i,M) _cin(v[i]);}else{C c;rep(i,N) v.pb((_cin(c),c));}}
template<typename C> inline void in(C v[],int N){rep(i,N) _cin(v[i]);}
template<typename C> inline void out(const vector<C> &v,int N=-1){int M=(N == -1) ? sz(v) : N; rep(i,M) {cout<<( (i)?" ":"" ); _cout(v[i]);} cout<<"\n";}
template<typename C> inline void out(C v[],int N){rep(i,N) {cout<<( (i)?" ":"" ); _cout(v[i]);} cout<<"\n";}
template<typename C> inline void vector_debug(const vector<C> &v,int N=-1){cout << "{"; int M=(N == -1) ? sz(v) : N; rep(i,M) {cout<<( (i)?", ":"" ); _cout(v[i]);} cout<<"}";}
template<typename C> inline void vector_debug(C v[], int N){cout << "{"; rep(i,N) {cout<<((i)?", ":""); _cout(*(v+i));} cout<<"}";}
void dbg_out(){cout << endl;} template <typename T,class... U> void dbg_out(const T &t,U ...u){ _cout(t); if(sizeof...(u)) cout << ", "; dbg_out(u...);}
template<typename C,class... U> void dbg_out(const vector<C> &v,U ...u){vector_debug(v); if(sizeof...(u)) cout << ", "; dbg_out(u...);}
template<typename C,class... U> void dbg_out(const vector<vector<C>> &v,U ...u){cout << "{ "; rep(i,sz(v)) {if(i)cout<<", "; vector_debug(v[i]);} cout << " }"; if(sizeof...(u)) cout << ", "; dbg_out(u...);}
template<typename C> inline C vmax(const vector<C> &v){C n=v[0]; rep(i,sz(v)) amax(n,v[i]); return n;} template<typename C> inline C vmax(C v[], int N){C n=v[0]; rep( i , N ) amax(n,v[i]); return n;}
template<typename C> inline C vmin(const vector<C> &v){C n=v[0]; rep(i,sz(v)) amin(n,v[i]); return n;} template<typename C> inline C vmin(C v[], int N){C n=v[0]; rep( i , N ) amin(n,v[i]); return n;}
void die(string s){out(s); exit(0);}

////////////
/// main ///
////////////

template<typename T,typename F,T UNIT>
struct ST2D{
  int hsize,wsize;
  vector<vector<T>> seg;
  F func;
  vector<int> h_sz,w_sz;
  vector<int> hlist,wlist;
  ST2D(const vector<vector<T>> &v , F func): func(func){
    seg.resize( (hsize=v.size())<<1 , 
      vector<T>( (wsize=v[0].size())<<1 , UNIT )
    );
    hlist.reserve(32);
    wlist.reserve(32);
    int hn = 0; h_sz.pb(0); w_sz.pb(0);
    while(hn < hsize){
      int hm = 1 << (31 - __builtin_clz(hsize ^ hn));
      for(int i = hn; i < hn + hm; i++){
        int wn = 0;
        while(wn < wsize){
          int wm = 1 << (31 - __builtin_clz(wsize ^ wn));
          for(int j = wn; j < wn + wm; j++){
            seg[hn + hm + i][wn + wm + j] = v[i][j];
          }
          wn += wm;
          if(i == 0) w_sz.pb(wn);
        }
      }
      h_sz.pb(hn += hm);
    }
    build();
  }

  void build(){
    auto ith = h_sz.begin();
    while(1){
      int hl = *(ith++);
      if(ith == h_sz.end()) return;
      int hr = *ith;
      const int dif = hl << 1;
      for(int i=hl+hr;i<(hr<<1);i++){
        build2(i);
      }
      for(int i = hr - hl - 1; i > 0; i--){
        build3(i,dif);
      }
    }
  }

  void build2(int i){
    auto itw = w_sz.begin();
    while(1){
      int wl = *(itw++);
      if(itw == w_sz.end()) return;
      int wr = *itw;
      const int dif = wl << 1;
      for(int j = wr - wl - 1; j > 0; j--){
        seg[i][dif|j] = func(
          seg[i][dif|(j<<1)] , seg[i][dif|(j<<1)|1]
        );
      }
    }
  }

  void build3(int i,int dif){
    auto itw = w_sz.begin();
    while(1){
      int wl = *(itw++);
      if(itw == w_sz.end()) return;
      int wr = *itw;
      for(int j=(wl<<1)+1;j<(wr<<1);j++){
        seg[dif|i][j] = func(
          seg[dif|(i<<1)][j] , seg[dif|(i<<1)|1][j]
        );
      }
    }
  }

  T getval(int i,int j){
    auto ith = upper_bound(h_sz.begin(),h_sz.end(),i);
    auto itw = upper_bound(w_sz.begin(),w_sz.end(),j);
    return seg[ (i += *ith) ][ (j += *itw) ];
  }

  void update(int i,int j,T x){
    auto ith = upper_bound(h_sz.begin(),h_sz.end(),i);
    auto itw = upper_bound(w_sz.begin(),w_sz.end(),j);
    seg[ (i += *ith) ][ (j += *itw) ] ^= x;
    int curi = i,curj = j;
    ith--; i -= (*(ith) << 1); const int difh = (*ith) << 1;
    itw--; j -= (*(itw) << 1); const int difw = (*itw) << 1;
    int ii = i;
    whlie(ii >>= 1){
      seg[difh | ii][curj] = func(
        seg[difh | (ii << 1)][curj] ,
        seg[difh | (ii << 1) | 1][curj]
      );
    }
    int jj = j;
    while(jj >>= 1){
      seg[curi][difw | jj] = func(
        seg[curi][difw | (jj << 1)] ,
        seg[curi][difw | (jj << 1) | 1]
      );
    }
    whlie(i >>= 1){
      int jjj = j;
      while(jjj >>= 1){
        seg[difh | i][difw | jjj] = func(
          seg[difh | i][difw | (jjj << 1)] ,
          seg[difh | i][difw | (jjj << 1) | 1]
        );
      }
    }
  }

  void add(int i,int j, T x){
    auto ith = upper_bound(h_sz.begin(),h_sz.end(),i);
    auto itw = upper_bound(w_sz.begin(),w_sz.end(),j);
    update(i , j , seg[ i + *ith ][ j + *itw ] + x );
  }

  T query(int ha,int wa,int hb,int wb){
    hlist.clear(); wlist.clear();
    makevec(ha,hb,hlist,h_sz);
    makevec(wa,wb,wlist,w_sz);
    //trc(hlist); trc(wlist);
    T ret = UNIT;
    for(const auto &i : hlist)
      for(const auto &j : wlist)
        ret = func(ret , seg[i][j]);
    return ret;
  }

  void makevec(int a,int b,vector<int> &v,vector<int>& w){
    //trc(a , b);
    b--;
    auto itl = upper_bound(w.begin(),w.end(),a);
    auto itr = upper_bound(w.begin(),w.end(),b);
    itl--; const int cur_sz = *(itr--) - *itr;
    while(itl != itr){
      if(a == *itl) v.pb( ((*itl++) << 1) | 1);
      else makevec(a , (*(++itl)) , v , w );
      a = *itl;
      //trc("a",v.back());
    }
    const int dif = (*itr) << 1;
    for(a += cur_sz - *itr,b += cur_sz + 1 - *itr;
      a < b;
      a>>=1,b>>=1
    ){
      //trc(a , b);
      if(a & 1) {v.pb(dif | (a++));}
      if(b & 1) {v.pb(dif | (--b));}
    }
  }
};

using P = pair<int,int>;
using ull = unsigned long long;
using vL = vector<ull>;
map<pair<P,P>,ull> m;
int main(){
  randinit;
  ini(N,M,Q);
  vector<vL> v(N+2 , vL(M+2 , 0));
  auto f = [](ull a, ull b){return a ^ b;};
  ST2D<ull , decltype(f) , 0> st(v , f);
  rep(i,Q){
    ini(c,h1,w1,h2,w2);
    trc(c,h1,w1,h2,w2);
    if(c == 1){
      ull val = rand();
      st.update(h1,w1,val);
      st.update(h1,w2+1,val);
      st.update(h2+1,w1,val);
      st.update(h2+1,w2+1,val);
      m[mp(P(h1,w1) , P(h2,w2))] = val;
      trc("1",val);
    }
    else if(c == 2){
      ull val = m[mp(P(h1,w1) , P(h2,w2))];
      st.update(h1,w1,val);
      st.update(h1,w2+1,val);
      st.update(h2+1,w1,val);
      st.update(h2+1,w2+1,val);
      trc("2",val);
    }
    else {
      trc(st.query(0,0,h1+1,w1+1));
      trc(st.query(0,0,h2+1,w2+1));
      if(st.query(0,0,h1+1,w1+1) == st.query(0,0,h2+1,w2+1)) out("Yes");
      else out("No");
    }
    /* *
    rep(i,N+1) rep(j,M+1) {
      trc(i , j , st.getval(i , j));
    }//*/
  }
}