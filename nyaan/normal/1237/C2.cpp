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

template<class T>
struct compress{
  vector<T> xs;
  compress(const vector<T>& v){
    xs.reserve(v.size());
    for(T x : v) xs.push_back(x);
    sort(xs.begin(),xs.end());
    xs.erase(unique(xs.begin(),xs.end()) , xs.end());
  }

  int get(const T& x){
    return lower_bound(xs.begin(),xs.end(),x) - xs.begin();
  }
  int size(){
    return xs.size();
  }
  T& operator[](int i){
    return xs[i];
  }
};

void solve(){
  ini(N);
  vi x(N) , y(N) , z(N);
  rep(i,N) in(x[i] , y[i] , z[i]);
  
  compress<int> zx(x);
  rep(i,N) x[i] = zx.get(x[i]);

  vvi g(zx.size());
  rep(i , N) g[x[i]].pb(i);
  each(x,g) trc(x);
  int residue = -1;
  vi used(N , 0);
  map<int,vi> m;
  rep( i,zx.size() ){
    if(g[i].size() == 0) continue;
    m.clear();
    each(n , g[i]) m[y[n]].pb(n);
    int res2 = -1;
    each(nyaa , m){
      trc(nyaa.fi , nyaa.se);
      if(nyaa.se.size() == 0) continue;
      sort(all(nyaa.se) , [&](int a,int b){return z[a]<z[b];});
      for(int nya = 0; nya + 1 < int(nyaa.se.size()) ; nya += 2){
        out(nyaa.se[nya] + 1 , nyaa.se[nya+1] + 1);
      }
      if(nyaa.second.size() % 2 == 1){
        if(res2 == -1) res2 = nyaa.second.back();
        else {
          out(res2 + 1 , nyaa.second.back() + 1);
          res2 = -1;
        }
      }
    }
    if(residue != -1 && res2 != -1) {
      out(residue + 1 , res2 + 1);
      residue = -1;
    }
    else if(res2 != -1) residue = res2;
  }
  
}