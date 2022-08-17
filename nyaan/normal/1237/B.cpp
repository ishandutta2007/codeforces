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
  #define trca(v,N) do { cerr << #v << " = "; array_out(v , N);cout << endl;} while(0)
#else
  #define trc(...)
  #define trca(...)
  int main(){solve();}
#endif

using P = pair<int,int>; using vp = vector<P>;
constexpr int MOD = /** 1000000007; //*/ 998244353;
////////////////

// BIT

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

  // [l,r]()
  inline T sum(int l,int r){
    return sum(r) - sum(l-1);
  }

  //  
  inline T operator[](int k){
    return sum(k) - sum(k-1);
  }

  // data[k] += x;
  void add(int k, T x) {
    for(++k; k < N; k += k & -k) data[k] += x;
  }

  // imos [l,r]x
  void imos(int l,int r,T x){
    add(l , x); add(r + 1 , -x);
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

void solve(){
  ini(N);
  vi a(N) , b(N); in(a); in(b);
  reverse(all(a)); reverse(all(b));
  vi ord(N + 1 , -1);
  rep(i,N) ord[b[i]] = i;
  BIT<int> bit(N + 1);
  rep(i,N) bit.add(i , 1);
  int ans = 0;
  rep(i , N){
    int idx = ord[a[i]];
    int num = bit.sum(idx - 1);
    if(num != 0) ans++;
    bit.add(idx , -1);
  }
  out(ans);

}