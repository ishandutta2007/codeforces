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

#pragma endregion
constexpr long long MOD = /** 1000000007; //*/ 998244353;

void q() {
  ini(r, g, b);
  vl s(r), t(g), u(b);
  in(s, t, u);
  sort(all(s));
  sort(all(t));
  sort(all(u));

  auto gg = [](vl &s, vl &t, vl &u) ->ll{
    auto f = [](ll x, ll y, ll z) {
      return (x - y) * (x - y) + (y - z) * (y - z) + (z - x) * (z - x);
    };
    ll ans = infLL;
    rep(i, sz(s)) {
      ll n = s[i];
      auto it = lower_bound(all(t), n);
      ll m[3];

      if (it == t.end()) it--;
      m[1] = *it;
      if (it != t.begin()) it--;
      m[0] = *it;
      it = upper_bound(all(t), n);
      if (it == t.end()) it--;
      m[2] = *it;

      rep(j, 3) {
        auto it = lower_bound(all(u), m[j]);
        if (it == u.end()) it--;
        amin(ans, f(n, m[j], *it));
        if (it != u.begin()) it--;
        amin(ans, f(n, m[j], *it));
        it = upper_bound(all(u), m[j]);
        if (it == u.end()) it--;
        amin(ans, f(n, m[j], *it));
        it = lower_bound(all(u), n);
        if (it == u.end()) it--;
        amin(ans, f(n, m[j], *it));
        if (it != u.begin()) it--;
        amin(ans, f(n, m[j], *it));
        it = upper_bound(all(u), n);
        if (it == u.end()) it--;
        amin(ans, f(n, m[j], *it));
      }
    }
    return ans;
  };

  ll ans = infLL;
  ans = min(ans, gg(s,t,u));
  ans = min(ans, gg(s,u,t));
  ans = min(ans, gg(t,s,u));
  ans = min(ans, gg(t,u,s));
  ans = min(ans, gg(u,s,t));
  ans = min(ans, gg(u,t,s));
  out(ans);
}

void solve() {
  ini(T);
  rep(i, T) q();
}