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


// Sparse Table
template<typename T>
struct SparseTable{
  vector< vector< T > > table;
  vector< int > log_table;

  SparseTable(const vector< T > &v) {
    int b = 0;
    while((1 << b) <= (int)v.size()) ++b;
    table.assign(b, vector< T >(1 << b));
    for(int i = 0; i < (int)v.size(); i++) {
      table[0][i] = v[i];
    }
    for(int i = 1; i < b; i++) {
      for(int j = 0; j + (1 << i) <= (1 << b); j++) {
        table[i][j] = max(table[i - 1][j], table[i - 1][j + (1 << (i - 1))]);
      }
    }
    log_table.resize(v.size() + 1);
    for(int i = 2; i < (int)log_table.size(); i++) {
      log_table[i] = log_table[i >> 1] + 1;
    }
  }

  //  [l , r) 
  inline T query(int l, int r) {
    int b = log_table[r - l];
    return max(table[b][l], table[b][r - (1 << b)]);
  }
};

void solve(){
  ini(N);
  vi v(N); in(v);
  trc(v);
  v.reserve(2 * N);
  rep(i,N) v.pb(v[i]);
  SparseTable<int> sparse(v);

  vi memo(N , inf);
  for(int i = N + 0; i < N + N; i++){
    int val = v[i];
    if(sparse.query(0 , i) <= 2 * val) continue;
    int ok = 0 , ng = i;
    while(ok + 1 < ng){
      int med = (ok + ng) / 2;
      if(sparse.query(med , ng) > 2 * val) ok = med;
      else ng = med;
    }
    // ok2*val
    amin( memo[ok % N] , i - ok );
  }
  vi ans(N , inf);
  repr(i,N) {
    if(memo[i] != inf) amin(ans[i] , memo[i]);
    if(ans[(i + 1) % N] != inf) amin(ans[i] , ans[(i+1)%N] + 1);
  }
  repr(i,N) {
    if(memo[i] != inf) amin(ans[i] , memo[i]);
    if(ans[(i + 1) % N] != inf) amin(ans[i] , ans[(i+1)%N] + 1);
  }
  repr(i,N) {
    if(memo[i] != inf) amin(ans[i] , memo[i]);
    if(ans[(i + 1) % N] != inf) amin(ans[i] , ans[(i+1)%N] + 1);
  }
  rep(i,N) if(ans[i] >= 1e8) ans[i] = -1;
  out(ans);

  /**
  // 
  vi bns(N);
  rep(i,N){
    int cnt = 0 , m = v[i];
    for(int j = i; cnt <= 2 * N ; j = (j + 1) % N){
      if(m > 2 * v[j]) break;
      amax(m , v[j]);
      cnt++;
    }
    bns[i] = cnt > 2 * N ? -1 : cnt;
  }
  trc(bns);
  trc(ans == bns ? 1 : 0);
  //*/
}