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
#define infLL ( (1LL << 61))
#define MOD 1000000007
#define FOR(i,a,b) for(int (i)=((int)a); (i)<((int)b); (i)++) // [a,b)
#define rep(i,N) FOR((i), 0, ((int)N)) // [0,N)
#define FORR(i,a,b) for(int (i)=((int)b) - 1; (i)>=((int)a); (i)--)
#define repr(i,N) FORR((i), 0, ((int)N))
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define sz(v) ((int)(v).size())
#define vrep(v,it) for(auto it=v.begin();it!=v.end();it++)
#define vrepr(v,it) for(auto it=v.rbegin();it!=v.rend();it++)
#define inx(t,...) t __VA_ARGS__; in(__VA_ARGS__)
#define ini(...) int __VA_ARGS__; in(__VA_ARGS__)
#define inl(...) ll __VA_ARGS__; in(__VA_ARGS__)
#define inc(...) char __VA_ARGS__; in(__VA_ARGS__)
#define ins(...) string __VA_ARGS__; in(__VA_ARGS__)
#define ind(...) double __VA_ARGS__; in(__VA_ARGS__)
#define inpii(...) pii __VA_ARGS__; in(__VA_ARGS__)
#define invi(v,...) vi v; in(v,##__VA_ARGS__)
#define invl(v,...) vl v; in(v,##__VA_ARGS__)
#define mem(ar,val) memset((ar), (val), sizeof(ar) )
#define mem0(ar) memset((ar),  0, sizeof(ar) )
#define mem1(ar) memset((ar), -1, sizeof(ar) )

#ifdef LOCAL
    #define dbg(...) fprintf(stderr, __VA_ARGS__)
    #define trc(...) do { cout << #__VA_ARGS__ << " = "; dbg_out(__VA_ARGS__);} while(0)
    #define stopif(val) assert( !(val) )
    #define vdbg(v,...) do { cout << #v << " = "; vector_debug(v , ##__VA_ARGS__);} while(0)
#else
    #define dbg(...) 1
    #define trc(...) 1
    #define stopif(...) 1
    #define vdbg(...) 1
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

struct IoSetup {
  IoSetup() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    cerr << fixed << setprecision(15);
  }
} iosetup;

int gcd(int a, int b){if(a>b) swap(a,b); return a==0 ? b : gcd(b%a,a);} ll gcd(ll a, ll b){if(a>b) swap(a,b); return a==0 ? b : gcd(b%a,a);}
int lcm(int a, int b){return (a / gcd(a,b)) * b;} ll lcm(ll a, ll b){return (a / gcd(a,b)) * b;}
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
template<typename C> inline void vector_debug(const vector<C> &v,int N=-1){cout << "{"; int M=(N == -1) ? sz(v) : N; rep(i,M) {cout<<( (i)?", ":"" ); _cout(v[i]);} cout<<"}"<<endl;}
template<typename C> inline void vector_debug(C v[], int N){cout << "{"; rep(i,N) {cout<<((i)?", ":""); _cout(*(v+i));} cout<<"}"<<endl;}
void dbg_out(){cout << endl;} template <typename T,class... U> void dbg_out(const T &t,U ...u){ _cout(t); if(sizeof...(u)) cout << ", "; dbg_out(u...);}
template<typename C,class... U> void dbg_out(const vector<C> &v,U ...u){vector_debug(v); if(sizeof...(u)) cout << ", "; dbg_out(u...);}
template<typename C,class... U> void dbg_out(const vector<vector<C>> &v,U ...u){cout << "{ "; rep(i,sz(v)) {if(i)cout<<", "; vector_debug(v[i]);} cout << " }"; if(sizeof...(u)) cout << ", "; dbg_out(u...);}
template<typename C> inline C vmax(const vector<C> &v){C n=v[0]; rep(i,sz(v)) amax(n,v[i]); return n;} template<typename C> inline C vmax(C v[], int N){C n=v[0]; rep( i , N ) amax(n,v[i]); return n;}
template<typename C> inline C vmin(const vector<C> &v){C n=v[0]; rep(i,sz(v)) amin(n,v[i]); return n;} template<typename C> inline C vmin(C v[], int N){C n=v[0]; rep( i , N ) amin(n,v[i]); return n;}
template<typename C> inline C vsum(const vector<C> &v){C n=0; rep(i,sz(v)) n+=v[i]; return n;} template<typename C> inline C vsum(C v[], int N){C n=0; rep( i , N ) n+=v[i]; return n;}

////////////
/// main ///
////////////

template< typename T >
struct BIT {
  int N; int max_2beki;

  vector< T > data;
  //  1-indexed 0
  BIT(int size){
      N = ++size;
      data.assign(N, 0);
      max_2beki = 1;
      while(max_2beki * 2 <= N) max_2beki *= 2;
  }

  // [0,k]() 
  T sum(int k) {
    if(k < 0) return 0; // k<00
    T ret = 0;
    for(++k; k > 0; k -= k & -k) ret += data[k];
    return (ret);
  }

  // data[k] += x;
  void add(int k, T x) {
    for(++k; k < N; k += k & -k) data[k] += x;
  }

  // T
  inline T operator[](int k){
    return sum(k) - sum(k - 1);
  }

  // lower_bound sum(i)vali
  int lower_bound(T w){
    if(w <= 0) return 0;
    int x = 0;
    for(int k = max_2beki; k > 0; k /= 2){
      if(x+k <= N - 1 && data[x + k] < w){
        w -= data[x + k];
        x += k;
      }
    }
    return x;
  }

  // upper_bound sum(i)vali
  int upper_bound(T w){
    if(w < 0) return 0;
    int x = 0;
    for(int k = max_2beki; k > 0; k /= 2){
      if(x+k <= N - 1 && data[x + k] <= w){
        w -= data[x + k];
        x += k;
      }
    }
    return x;
  }
};

//   O(NlogN) (N)
// unzip...vector zip...map ... 
// compress(unzip,zip); 
// unzip[(val)] = (val);
// zip[(val)] = (val); 
template<typename T>
int compress(vector<T>& unzip, map<T, int>& zip) {
  sort(unzip.begin(), unzip.end());
  unzip.erase(unique(unzip.begin(), unzip.end()), unzip.end());
  for (int i = 0; i < sz(unzip); i++) {
      zip[unzip[i]] = i;
  }
  return sz(unzip);
}

int main(){
  ini(N,M);
  vl t(N); in(t , N);
  BIT<ll> bit(N) , cnt(N);
  using P = pair<ll,int>;
  map<P, int> zip;
  vector<P> unzip(N);
  rep(i,N) unzip[i] = P(t[i] , i);
  compress(unzip , zip);

  rep(i,N){
    if(i) cout << " ";
    cout << i - cnt.sum( (bit.upper_bound(M - t[i]) - 1) ) ;
    bit.add( zip[P(t[i],i)] , t[i] );
    cnt.add( zip[P(t[i],i)] , 1);
    rep(i,N){
      //trc(bit[i] , cnt[i]);
    }
  }
  
  
}