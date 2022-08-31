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
#define rand rng
using namespace std; void solve();
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector< vector<int> >;
constexpr int inf = 1001001001;
constexpr ll infLL = (1LL << 61) - 1;
mt19937_64 rng(58);
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
  int main(){solve_dbg();}
#else
  #define trc(...)
  #define trca(...)
  int main(){solve();}
#endif

using P = pair<ll,ll>;
constexpr int MOD = 998244853;

/////////

// Union-Find
//  UF(N); N
//  unite(x,y);  same(x,y);
//  count
struct UF{
  vector<int> par,sizes;
  int count;
  UF(int N) : par(N),sizes(N, 1),count(N){ for(int i=0; i<N; i++) par[i]=i; }

  int find(int x){ return par[x]==x ? x : par[x] = find(par[x]); }

  bool same(int x,int y){ return find(x) == find(y); }

  int size(int x){ return sizes[find(x)]; }

  void unite(int x, int y){
    x = find(x); y = find(y);
    if(x == y) return;
    if(sizes[x] < sizes[y]) swap(x,y);
    par[y] = x;
    sizes[x] += sizes[y];
    count--;
  }
};

void solve(){
  ini(N , M);
  vi x(N) , y(N) , w(N);
  rep(i , N - 1){
    in(x[i] , y[i] , w[i]);
    x[i]--; y[i]--;
  }
  vi q(M); in(q);
  trc(q);
  vi ord(N - 1); iota(all(ord) , 0);
  sort(all(ord),[&](int a,int b){return w[a]<w[b];});
  trc(ord);
  UF uf(N);
  vl ans(200010);
  auto it = ord.begin();
  ll cur = 0;
  rep1(i , 200001){
    while(it!=ord.end() && w[*it] == i){
      ll as = uf.size(x[*it]);
      ll bs = uf.size(y[*it]);
      uf.unite(x[*it] , y[*it]);
      cur -= as * (as - 1) / 2;
      cur -= bs * (bs - 1) / 2;
      cur += (as+bs) * (as+bs-1) / 2;
      it++;
    }
    ans[i] = cur;
  }
  rep(i , M) cout << (i?" ":"") << ans[q[i]];
  out();
}