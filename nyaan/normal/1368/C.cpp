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
template <class ll = ll>
using V = vector<ll>;
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
template <typename ll, typename U>
inline bool amin(ll &x, U y) {
  return (y < x) ? (x = y, true) : false;
}
template <typename ll, typename U>
inline bool amax(ll &x, U y) {
  return (x < y) ? (x = y, true) : false;
}
template <typename ll, typename U>
ll ceil(ll a, U b) {
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

template <typename ll, typename U>
ostream &operator<<(ostream &os, const pair<ll, U> &p) {
  os << p.first << " " << p.second;
  return os;
}
template <typename ll, typename U>
istream &operator>>(istream &is, pair<ll, U> &p) {
  is >> p.first >> p.second;
  return is;
}
template <typename ll>
ostream &operator<<(ostream &os, const vector<ll> &v) {
  int s = (int)v.size();
  for (int i = 0; i < s; i++) os << (i ? " " : "") << v[i];
  return os;
}
template <typename ll>
istream &operator>>(istream &is, vector<ll> &v) {
  for (auto &x : v) is >> x;
  return is;
}
void in() {}
template <typename ll, class... U>
void in(ll &t, U &... u) {
  cin >> t;
  in(u...);
}
void out() { cout << "\n"; }
template <typename ll, class... U>
void out(const ll &t, const U &... u) {
  cout << t;
  if (sizeof...(u)) cout << " ";
  out(u...);
}
template <typename ll>
void die(ll x) {
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

inline int popcnt(unsigned long long a) { return __builtin_popcountll(a); }
inline int lsb(unsigned long long a) { return __builtin_ctzll(a); }
inline int msb(unsigned long long a) { return 63 - __builtin_clzll(a); }
template <typename ll>
inline int getbit(ll a, int i) {
  return (a >> i) & 1;
}
template <typename ll>
inline void setbit(ll &a, int i) {
  a |= (1LL << i);
}
template <typename ll>
inline void delbit(ll &a, int i) {
  a &= ~(1LL << i);
}
template <typename ll>
int lb(const vector<ll> &v, const ll &a) {
  return lower_bound(begin(v), end(v), a) - begin(v);
}
template <typename ll>
int ub(const vector<ll> &v, const ll &a) {
  return upper_bound(begin(v), end(v), a) - begin(v);
}
template <typename ll>
vector<ll> mkrui(const vector<ll> &v) {
  vector<ll> ret(v.size() + 1);
  for (int i = 0; i < int(v.size()); i++) ret[i + 1] = ret[i] + v[i];
  return ret;
};
template <typename ll>
vector<ll> mkuni(const vector<ll> &v) {
  vector<ll> ret(v);
  sort(ret.begin(), ret.end());
  ret.erase(unique(ret.begin(), ret.end()), ret.end());
  return ret;
}
template <typename F>
vector<int> mkord(int N, F f) {
  vector<int> ord(N);
  iota(begin(ord), end(ord), 0);
  sort(begin(ord), end(ord), f);
  return ord;
}
template <typename ll = int>
vector<ll> mkiota(int N) {
  vector<ll> ret(N);
  iota(begin(ret), end(ret), 0);
  return ret;
}

#pragma endregion

constexpr int MOD = 998244353;


void solve(){
  ini(K);
  out(3*K+4);
  out(0,0);
  out(0,1);
  out(1,0);
  out(1,1);
  rep1(i,K){
    out(i,i+1);
    out(i+1,i);
    out(i+1,i+1);
  }
}