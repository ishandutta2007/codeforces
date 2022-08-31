#pragma GCC optimize("O2")
#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdarg>
#include <cstdio>
#include <cstring>
#include <deque>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>

#define whlie while
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define inf 1001001001
#define infLL (1LL << 61)
#define MOD 1000000007
#define FOR(i,a,b) for(int (i)=(int)(a); (i)<(int)(b); (i)++) // [a,b)
#define rep(i,N) FOR((i), 0, (int)(N)) // [0,N)
#define FORR(i,a,b) for(int (i)=(int)(b) - 1; (i)>=(int)(a); (i)--)
#define repr(i,N) FORR((i), 0, (int)(N))
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

#ifdef LOCAL  
  #define trc(...) do { cout << #__VA_ARGS__ << " = "; dbg_out(__VA_ARGS__);} while(0)
  #define stopif(val) assert( !(val) )
  #define trcv(v,...) do { cout << #v << " = "; vector_debug(v , ##__VA_ARGS__);} while(0)
#else
  #define trc(...)
  #define stopif(...)
  #define trcv(...)
#endif

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef vector<pii> vpii;
typedef vector< vector<int> > vvi;

struct IoSetup {IoSetup() { cin.tie(nullptr); ios::sync_with_stdio(false); cout << fixed << setprecision(15); cerr << fixed << setprecision(15);} } iosetup;

int gcd(int a, int b){if(a>b) swap(a,b); return a==0 ? b : gcd(b%a,a);} ll gcd(ll a, ll b){if(a>b) swap(a,b); return a==0 ? b : gcd(b%a,a);}
ll lcm(int a, int b){return (1LL * a / gcd(a,b)) * b;} ll lcm(ll a, ll b){return (a / gcd(a,b)) * b;}
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

////////////
/// main ///
////////////

// 
// 0-indexed
// kk+size
// kk/2,2k
template<typename T>
struct ST{
  int size;
  vector<T> seg;

  // 
  // func(a,UNIT)=aUNIT
  T UNIT = inf;
  // 
  T func(T a, T b){
    return min(a,b);
  }
  // 
  
  ST(int N){
    size = 1;
    while(size < N) size <<= 1;
    seg.assign(2 * size, UNIT);
    build();
  }

  ST(const vector<T> &v){
    // initialize
    int N = (int)v.size();
    size = 1;
    while(size < N) size <<= 1;
    seg.resize(2 * size);
    // set
    for(int i=0;i < N; i++){
      seg[i + size] = v[i];
    }
    build();
  }

  void set(int k,T& x){
    seg[k + size] = x;
  }

  void build(){
    for(int k=size-1; k>0; k--){
      seg[k] = func(seg[2 * k] , seg[2 * k + 1]);
    }
  }
  
  void update(int k, T x){
    k += size; seg[k] = x;
    while(k >>= 1){
      seg[k] = func(seg[2 * k] , seg[2 * k + 1]);
    }
  }
  
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

int main(){
  ini(q);
  while(q--){
    ini(N);
    vi a(N),b(N);
    in(a,N); in(b,N);
    ST<int> st(a);
    vvi cnt(N + 1);
    repr(i,N){
      cnt[a[i]].pb(i);
    }
    /* 
    int l=0,r = N-1;
    while(l != r && a[l] == b[l]) l++;
    while(r != l && a[r] == b[r]) r--;
    */
    int flg = 1;
    rep(i,N){
      trc(i,cnt[b[i]].empty());
      trc(cnt[b[i]]);
      if(cnt[b[i]].empty()){
        flg = 0; break;
      }
      int j = cnt[b[i]].back();
      
      if(st.query(0,j) < b[i]){
        flg = 0; break;
      }
      cnt[b[i]].pop_back();
      st.update(j,inf);
    }
    out(flg ? "YES" : "NO");
  }
}