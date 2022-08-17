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
constexpr int MOD = /**/ 1000000007; //*/ 998244353;
////////////////

#define pow nyapow
inline ll nyapow(ll b,ll n){
  ll ret = 1;
  while(n){
    if(n & 1) ret *= b;
    b *= b;
    n >>= 1;
  }
  return ret;
}

void solve(){
  inl(N , K);
  vl v(N); in(v);
  vector<ll> cnt(100001 , 0);
  each(x , v) cnt[x]++;
  
  if(K == 2){
    vl dnt(100001 , 0);
    for(ll j = 1; j <= 100000; j++){
      ll nya = 1;
      for(ll k = 1; k * k <= j; k++) if(j % (k*k) == 0) nya = j / (k * k);
      dnt[nya] += cnt[j];
    }
    ll ans = 0;
    rep1(i , 100000) ans += dnt[i] * (dnt[i] - 1) / 2;
    rep1(i , 15) trc(dnt[i]);
    out(ans);
    
  }
  else{
    vl kouho;
    if(K == 3){
      for(ll j = 1; j * j * j <= 1e11; j++){
        kouho.push_back(j * j * j);
      }
    }
    else{
      for(ll j = 1; log10(j) * K <= 11.0; j++){
        kouho.push_back(pow(j , K));
      }
    }
    ll ans = 0;
    each(x , kouho){
      for(long long i = (x + 99999) / 100000; i <= 100000 && i * i <= x ; i++){
        if(x % i == 0){
          if(i * i != x){
            ans += cnt[i] * cnt[x / i];
          }
          else{
            ans += ( cnt[i] * cnt[i] - cnt[i] ) / 2;
          }
        }
      }
    }
    out(ans);
  }
     
  
  


}