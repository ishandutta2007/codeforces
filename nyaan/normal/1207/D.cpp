#include <bits/stdc++.h>
#define whlie while
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define rep(i,N) for(int i = 0; i < (N); i++)
#define repr(i,N) for(auto i = (N) - 1; i >= 0; i -= 1)
#define each(x,v) for(auto& x : v)
#define all(v) (v).begin(),(v).end()
#define sz(v) ((int)(v).size())
#define vrep(v,it) for(auto it = v.begin(); it != v.end(); it++)
#define vrepr(v,it) for(auto it = v.rbegin(); it != v.rend(); it++)
#define ini(...) int __VA_ARGS__; in(__VA_ARGS__)
#define inl(...) ll __VA_ARGS__; in(__VA_ARGS__)
#define ins(...) string __VA_ARGS__; in(__VA_ARGS__)
#define rand mtrand
using namespace std; void solve();
using ll = long long; using vi = vector<int>;
using vl = vector<ll>; using vvi = vector< vector<int> >;
constexpr int inf = 1001001001; constexpr ll infLL = 0x1FFFFFFFFFFFFFFFLL;
struct IoSetupNya {IoSetupNya() { cin.tie(nullptr); ios::sync_with_stdio(false); cout << fixed << setprecision(15); cerr << fixed << setprecision(15);} } iosetupnya;
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
  #define trc(...) do { cout << #__VA_ARGS__ << " = "; dbg_out(__VA_ARGS__);} while(0)
  #define trca(v,N) do { cout << #v << " = "; array_out(v , N);cout << endl;} while(0)
  int main(){ auto start = clock(); m_dbg(); cerr << "time : " << clock() - start  << " ms" << endl; }
#else
  #define trc(...)
  #define trca(...)
  int main(){ solve(); }
#endif

using P = pair<int,int>;
constexpr int MOD = 998244353;
random_device seed_gen; mt19937_64 mtrand(seed_gen());
//////////////////////////////////////////

vector<ll> fac,finv,inv;
void COMinit(int MAX) {
  fac.resize(MAX , 0);
  finv.resize(MAX , 0);
  inv.resize(MAX , 0);
  fac[0] = fac[1] = finv[0] = finv[1] = inv[1] = 1;
  for (int i = 2; i < MAX; i++){
    fac[i] = fac[i - 1] * i % MOD;
    inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
    finv[i] = finv[i - 1] * inv[i] % MOD;
  }
}
// nCk combination 
inline long long COM(int n,int k){
  if(n < k || k < 0) return 0;
  else return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}
// nPk permutation
inline long long PER(int n,int k){
  if (n < k || k < 0) return 0;
  else return (fac[n] * finv[n - k]) % MOD;
}
// nHk homogeneous polynomial
inline long long HGP(int n,int k){
  if(n == 0 && k == 0) return 1; //?
  else if(n < 1 || k < 0) return 0;
  else return fac[n + k - 1] * (finv[k] * finv[n - 1] % MOD) % MOD;
}

template<typename T>
ll cnt(vector<T> &v){
  int N = sz(v);
  map<T,int> m;
  ll ans = 1;
  rep(i,N) m[v[i]]++;
  each(x , m){
    ans = ans * fac[x.se] % MOD;
  }
  return ans;
}

void solve(){
  ini(N);
  vector<P> v(N); in(v);
  COMinit(N + 10);
  ll ans = fac[N];
  trc(ans);
  vi v1(N); rep(i,N) v1[i] = v[i].fi;
  trc(cnt(v1));
  ans = (ans + MOD - cnt(v1)) % MOD;
  rep(i,N) v1[i] = v[i].se;
  trc(cnt(v1));
  ans = (ans + MOD - cnt(v1)) % MOD;
  sort(all(v));
  rep(i,N-1){
    if(v[i].se > v[i + 1].se) die(ans);
  }
  trc(cnt(v));
  ans = (ans + cnt(v)) % MOD;
  out(ans);
}