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
using P = pair<int,int>; using vp = vector<P>;
constexpr int MOD = /** 1000000007; //*/ 998244353;
////////////////

void solve(){
  ini(N);
  vp v(N); in(v);
  if(N == 1) die("YES");
  sort(all(v));
  // no
  rep(i , N){
    if(v[i].se - v[i].fi == 1) die("NO");
  }
  {
    int nya = 0;
    rep(i , N){
      if(i == N - 1) break;
      amax(nya , v[i].se);
      if(nya == (i + 1) * 2) die("NO");
    }
  }

  set<int> used , unused;
  rep(i , N){
    if(i == 0){
      used.insert(v[i].se);
      continue;
    }    
    auto it1 = used.lower_bound(v[i].fi);
    auto it2 = unused.upper_bound(v[i].fi);

    if(it2 != unused.end()){
      while(it2 != unused.end()){
        if(v[i].se < *it2) break;
        used.insert(*it2);
        it2 = unused.erase(it2);
      }
    } 

    if(it1 != used.end()){
      if(*it1 > v[i].se){
        unused.insert(v[i].se);
      }
      else {
        it1++;
        if(it1 != used.end() && (*it1) < v[i].se) die("NO");
        used.insert(v[i].se);
      }
    }    
  }
  out("YES");
}