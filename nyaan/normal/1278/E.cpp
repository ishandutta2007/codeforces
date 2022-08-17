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
#define ini(...) int __VA_ARGS__; in(__VA_ARGS__)
#define inl(...) ll __VA_ARGS__; in(__VA_ARGS__)
#define ins(...) string __VA_ARGS__; in(__VA_ARGS__)
using namespace std; void solve();
using ll = long long; using vl = vector<ll>;
using vi = vector<int>; using vvi = vector< vector<int> >;
constexpr int inf = 1001001001;
constexpr ll infLL = (1LL << 61) - 1;
struct IoSetupNya {IoSetupNya() { cin.tie(nullptr); ios::sync_with_stdio(false); cout << fixed << setprecision(15); cerr << fixed << setprecision(10);} } iosetupnya;
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
using P = pair<vi,int>; using vp = vector<P>;
constexpr int MOD = /** 1000000007; //*/ 998244353;
////////////////

void solve(){
  ini(N);
  vvi g(N);
  rep(i , N - 1){
    ini(x , y); x--; y--;
    g[x].pb(y); g[y].pb(x);
  }

  auto efs = [&](auto rec,int cur,int par) -> int{
    int ret = 1 , m = 0;
    each(x , g[cur]){
      if(x == par) continue;
      int dval = rec(rec , x , cur);
      ret += dval;
      if(amax(m , dval)) swap(x , g[cur][0]);
    }
    return ret;
  };

  auto dfs = [&](auto rec,int cur,int par) -> P {
    trc(cur , par);
    if(sz(g[cur]) == 0){
      return P({cur} , cur);
    }
    if(sz(g[cur]) == 1 && g[cur][0] == par) 
      return P({cur} , cur);
    
    P ret = rec(rec , g[cur][0] , cur);
    vector<int> nya;
    rep1(i , sz(g[cur]) - 1){
      if(g[cur][i] == par) continue;
      P dst = rec(rec , g[cur][i] , cur);
      each(x , dst.first) ret.first.pb(x);
      nya.pb(dst.second);
    }
    ret.first.pb(cur);
    repr(i , sz(nya)) ret.first.pb(nya[i]);
    ret.first.pb(ret.second);
    
    ret.second = cur;
    trc(cur , par , ret);
    return ret;
  };

  efs(efs , 0 , -1);
  P nya = dfs(dfs , 0 , -1);
  vi v = nya.first; v.pb(nya.second);
  trc(v);

  vvi ans(N);
  rep(i , N * 2) ans[v[i]].pb(i + 1);

  each(x , ans) out(x);

}