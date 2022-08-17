#include <bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define rep(i,N) for(long long i = 0; i < (long long)(N); i++)
#define repr(i,N) for(long long i = (long long)(N) - 1; i >= 0; i--)
#define rep1(i,N) for(long long i = 1; i <= (long long)(N) ; i++)
#define repr1(i,N) for(long long i = (N) ; (long long)(i) > 0 ; i--)
#define each(x,v) for(auto& x : v)
#define all(v) (v).begin(),(v).end()
#define sz(v) ((int)(v).size())
#define ini(...) int __VA_ARGS__; in(__VA_ARGS__)
#define inl(...) long long __VA_ARGS__; in(__VA_ARGS__)
#define ins(...) string __VA_ARGS__; in(__VA_ARGS__)
using namespace std; void solve();
using ll = long long; template<class T = ll> using V = vector<T>;
using vi = V<int>; using vl = V<>; using vvi = V< V<int> >;
constexpr int inf = 1001001001; constexpr ll infLL = (1LL << 61) - 1;
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
 
using P = pair<int,int>; using vp = V<P>;
constexpr int MOD = /**/ 1000000007; //*/ 998244353;
//////////
 
void solve(){
  inl(N);
  V<int> lucky(N , 0);
  vp v; 
  map<P,int> m;
  rep(i , N){
    ini(l);
    int cmin , cmax;
    rep(_ , l){
      ini(x);
      if(_ == 0) cmin = cmax = x;
      else {
        if(cmin < x) lucky[i] = 1;
        amax(cmax , x);
        amin(cmin , x);
      }
    }
    if(lucky[i] == 0) {
      v.eb(cmin , cmax);
      m[P(cmin , cmax)]++;
    }
  } 
  
  ll ans = N * N;
 
  sort(all(v));
  priority_queue< int,vi,greater<int> > Q;
  ll s = sz(v);
  rep(i , s){
    trc(v[i]);
    
    Q.push(v[i].se);
    while(!Q.empty() && Q.top() <= v[i].fi){
      Q.pop();
    }

    // 
    // i + 1Q
    // -> i + 1 - Q.size()
    trc(i + 1 - Q.size());
    ans -= 0LL + i + 1 - Q.size();

  }

  // 
  each(x , m){
    if(x.fi.fi == x.fi.se) ans -= 1LL * x.se * (x.se - 1) / 2;
  }

  out(ans);
 
}