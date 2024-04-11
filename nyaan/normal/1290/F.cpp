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

#define in2(N,s,t) rep(i,N){in(s[i] , t[i]);}
#define in3(N,s,t,u) rep(i,N){in(s[i] , t[i] , u[i]);}
using vd = V<double>; using vs = V<string>; using vvl = V< V<> >;
template<typename T>using heap = priority_queue< T , V<T> , greater<T> >;

using P = pair<int,int>; using vp = V<P>;
constexpr int MOD = /** 1000000007; //*/ 998244353;
//////////////////

template< int mod >
struct ModInt {
  int x;

  ModInt() : x(0) {}

  ModInt(int64_t y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}

  ModInt &operator+=(const ModInt &p) {
    if((x += p.x) >= mod) x -= mod;
    return *this;
  }

  ModInt &operator-=(const ModInt &p) {
    if((x += mod - p.x) >= mod) x -= mod;
    return *this;
  }

  ModInt &operator*=(const ModInt &p) {
    x = (int) (1LL * x * p.x % mod);
    return *this;
  }

  ModInt &operator/=(const ModInt &p) {
    *this *= p.inverse();
    return *this;
  }

  ModInt operator-() const { return ModInt(-x); }

  ModInt operator+(const ModInt &p) const { return ModInt(*this) += p; }

  ModInt operator-(const ModInt &p) const { return ModInt(*this) -= p; }

  ModInt operator*(const ModInt &p) const { return ModInt(*this) *= p; }

  ModInt operator/(const ModInt &p) const { return ModInt(*this) /= p; }

  bool operator==(const ModInt &p) const { return x == p.x; }

  bool operator!=(const ModInt &p) const { return x != p.x; }

  ModInt inverse() const {
    int a = x, b = mod, u = 1, v = 0, t;
    while(b > 0) {
      t = a / b;
      swap(a -= t * b, b);
      swap(u -= t * v, v);
    }
    return ModInt(u);
  }

  ModInt pow(int64_t n) const {
    ModInt ret(1), mul(x);
    while(n > 0) {
      if(n & 1) ret *= mul;
      mul *= mul;
      n >>= 1;
    }
    return ret;
  }

  friend ostream &operator<<(ostream &os, const ModInt &p) {
    return os << p.x;
  }

  friend istream &operator>>(istream &is, ModInt &a) {
    int64_t t;
    is >> t;
    a = ModInt< mod >(t);
    return (is);
  }

  static int get_mod() { return mod; }
};

using modint = ModInt< MOD >;
using vm = vector<modint>;

constexpr int MAX = 21;
modint dp[MAX][MAX][MAX][MAX][2][2];
modint ep[MAX][MAX][MAX][MAX][2][2];

void solve(){
  ini(N , M);
  vp a(N); in(a);

  dp[0][0][0][0][0][0] = 1;
  while(M > 0){
    //trc(M);
    rep(acpx , MAX) rep(acnx , MAX) rep(acpy , MAX) rep(acny , MAX) rep(afx , 2) rep(afy , 2)
      ep[acpx][acnx][acpy][acny][afx][afy] = 0;
    
    rep(cpx , MAX) rep(cnx , MAX) rep(cpy , MAX) rep(cny , MAX) rep(fx , 2) rep(fy , 2)
    {      
      modint cur = dp[cpx][cnx][cpy][cny][fx][fy];
      if(cur == 0) continue;
      //trc(cur , cpx , cnx , cpy , cny , fx , fy);
      rep(bit , 1 << N){
        int dpx = cpx;
        int dnx = cnx;
        int dpy = cpy;
        int dny = cny;
        rep(i , N){
          if( (bit >> i) & 1){
            dpx += max(0 , a[i].first);
            dnx -= min(0 , a[i].first);
            dpy += max(0 , a[i].second);
            dny -= min(0 , a[i].second);
          }
        }
        if( (dpx & 1) != (dnx & 1) ) continue;
        if( (dpy & 1) != (dny & 1) ) continue;
        int nfx = (dpx & 1) > (M & 1) ? 1 : (dpx & 1) < (M & 1) ? 0 : fx;
        int nfy = (dpy & 1) > (M & 1) ? 1 : (dpy & 1) < (M & 1) ? 0 : fy;
        dpx >>= 1; dnx >>= 1; dpy >>= 1; dny >>= 1;
        //trc(bit , dpx , dnx , dpy , dny , nfx , nfy);
        ep[dpx][dnx][dpy][dny][nfx][nfy] += cur;
      }

    }
    swap(dp , ep);
    M >>= 1;
  }
  out(dp[0][0][0][0][0][0] - 1);
}