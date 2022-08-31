#pragma region kyopro_template
#include <bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define each(x, v) for (auto &x : v)
#define all(v) (v).begin(), (v).end()
#define sz(v) ((int)(v).size())
#define mem(a, val) memset(a, val, sizeof(a))
#define ini(...)   \
  int __VA_ARGS__; \
  in(__VA_ARGS__)
#define inl(...)         \
  long long __VA_ARGS__; \
  in(__VA_ARGS__)
#define ins(...)      \
  string __VA_ARGS__; \
  in(__VA_ARGS__)
#define inc(...)    \
  char __VA_ARGS__; \
  in(__VA_ARGS__)
#define in2(s, t)                           \
  for (int i = 0; i < (int)s.size(); i++) { \
    in(s[i], t[i]);                         \
  }
#define in3(s, t, u)                        \
  for (int i = 0; i < (int)s.size(); i++) { \
    in(s[i], t[i], u[i]);                   \
  }
#define in4(s, t, u, v)                     \
  for (int i = 0; i < (int)s.size(); i++) { \
    in(s[i], t[i], u[i], v[i]);             \
  }
#define rep(i, N) for (long long i = 0; i < (long long)(N); i++)
#define repr(i, N) for (long long i = (long long)(N)-1; i >= 0; i--)
#define rep1(i, N) for (long long i = 1; i <= (long long)(N); i++)
#define repr1(i, N) for (long long i = (N); (long long)(i) > 0; i--)
using namespace std;
void solve();
using ll = long long;
template <class T = ll>
using V = vector<T>;
using vi = vector<int>;
using vl = vector<long long>;
using vvi = vector<vector<int>>;
using vd = V<double>;
using vs = V<string>;
using vvl = vector<vector<long long>>;
using P = pair<long long, long long>;
using vp = vector<P>;
using pii = pair<int, int>;
using vpi = vector<pair<int, int>>;
constexpr int inf = 1001001001;
constexpr long long infLL = (1LL << 61) - 1;
template <typename T, typename U>
inline bool amin(T &x, U y) {
  return (y < x) ? (x = y, true) : false;
}
template <typename T, typename U>
inline bool amax(T &x, U y) {
  return (x < y) ? (x = y, true) : false;
}
template <typename T, typename U>
ll ceil(T a, U b) {
  return (a + b - 1) / b;
}
constexpr ll TEN(int n) {
  ll ret = 1, x = 10;
  while (n) {
    if (n & 1) ret *= x;
    x *= x;
    n >>= 1;
  }
  return ret;
}

template <typename T, typename U>
ostream &operator<<(ostream &os, const pair<T, U> &p) {
  os << p.first << " " << p.second;
  return os;
}
template <typename T, typename U>
istream &operator>>(istream &is, pair<T, U> &p) {
  is >> p.first >> p.second;
  return is;
}
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
  int s = (int)v.size();
  for (int i = 0; i < s; i++) os << (i ? " " : "") << v[i];
  return os;
}
template <typename T>
istream &operator>>(istream &is, vector<T> &v) {
  for (auto &x : v) is >> x;
  return is;
}
void in() {}
template <typename T, class... U>
void in(T &t, U &... u) {
  cin >> t;
  in(u...);
}
void out() { cout << "\n"; }
template <typename T, class... U>
void out(const T &t, const U &... u) {
  cout << t;
  if (sizeof...(u)) cout << " ";
  out(u...);
}
template <typename T>
void die(T x) {
  out(x);
  exit(0);
}

#ifdef NyaanDebug
#include "NyaanDebug.h"
#define trc(...)                   \
  do {                             \
    cerr << #__VA_ARGS__ << " = "; \
    dbg_out(__VA_ARGS__);          \
  } while (0)
#define trca(v, N)       \
  do {                   \
    cerr << #v << " = "; \
    array_out(v, N);     \
  } while (0)
#define trcc(v)                             \
  do {                                      \
    cerr << #v << " = {";                   \
    each(x, v) { cerr << " " << x << ","; } \
    cerr << "}" << endl;                    \
  } while (0)
#else
#define trc(...)
#define trca(...)
#define trcc(...)
int main() { solve(); }
#endif

struct IoSetupNya {
  IoSetupNya() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    cerr << fixed << setprecision(7);
  }
} iosetupnya;

inline int popcount(unsigned long long a) { return __builtin_popcountll(a); }
inline int lsb(unsigned long long a) { return __builtin_ctzll(a); }
inline int msb(unsigned long long a) { return 63 - __builtin_clzll(a); }
template <typename T>
inline int getbit(T a, int i) {
  return (a >> i) & 1;
}
template <typename T>
inline void setbit(T &a, int i) {
  a |= (1LL << i);
}
template <typename T>
inline void delbit(T &a, int i) {
  a &= ~(1LL << i);
}
template <typename T>
int lb(const vector<T> &v, const T &a) {
  return lower_bound(begin(v), end(v), a) - begin(v);
}
template <typename T>
int ub(const vector<T> &v, const T &a) {
  return upper_bound(begin(v), end(v), a) - begin(v);
}
template <typename T>
vector<T> mkrui(const vector<T> &v) {
  vector<T> ret(v.size() + 1);
  for (int i = 0; i < int(v.size()); i++) ret[i + 1] = ret[i] + v[i];
  return ret;
};
template <typename T>
vector<int> mkord(const vector<T> &v, function<bool(T, T)> f) {
  vector<int> ord(v.size());
  iota(begin(ord), end(ord), 0);
  sort(begin(ord), end(ord), f);
  return ord;
}
template <typename T>
vector<T> mkuni(const vector<T> &v) {
  vector<T> ret(v);
  sort(ret.begin(), ret.end());
  ret.erase(unique(ret.begin(), ret.end()), ret.end());
  return ret;
}

#pragma endregion

constexpr long long MOD = /** 1000000007;  //*/ 998244353;

int a[256][256], b[256];

void q(){
  ini(N);
  mem(a,0);
  rep(i,N-1){
    ini(n); b[i]=n;
    rep(_,n){ini(x); a[i][x]=1;}
  }
  // s
  
  auto f=[&](int a0,int a1,int s)->vi{
    trc(a0,a1,s);
    vi ans(N); ans[0]=a0, ans[1]=a1;
    vi inv(N+1,-1); inv[a0]=0, inv[a1]=1;
    vi used(N-1); used[s]=1;
    // 2
    for(int i=2;i<N;i++){
      trc(i);
      rep(n,N-1){
        trc(n);
        if(used[n]) continue;
        // n
        int l = i - b[n] + 1;
        if(l<0)continue;
        // l ~ i
        int nxt = -1;
        rep1(m,N){
          if(a[n][m]){
            if(inv[m] == -1) nxt = (nxt == -1 ? m : inf);
            else if(inv[m] < l) nxt = inf;
          }
          if(nxt==inf)break;
        }
        if(nxt != -1 && nxt != inf){
          used[n] = 1;
          ans[i] = nxt;
          inv[nxt] = i; 
          break;
        }
      }
      if(accumulate(all(used),0) != i) return vi();
    }
    return ans;
  };
  
  rep(s, N-1){
    if(b[s]!=2) continue;
    int a0 = -1, a1 = -1;
    rep1(m,N) if(a[s][m]==1) (a0==-1?a0:a1)=m;
    auto t = f(a0,a1,s);
    auto u = f(a1,a0,s);
    if(sz(t)!=0){out(t);return;}
    if(sz(u)!=0){out(u);return;}
  }
  exit(1);
}

void solve(){
  int T;
  cin >> T;
  for(int i = 0 ; i < T ; i++) q();
}