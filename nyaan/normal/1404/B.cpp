#pragma region kyopro_template
#define Nyaan_template
#include <immintrin.h>
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
#define reg(i, a, b) for (long long i = (a); i < (b); i++)
#define die(...)      \
  do {                \
    out(__VA_ARGS__); \
    return;           \
  } while (0)
using namespace std;
using ll = long long;
template <class T>
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

#ifdef NyaanDebug
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
template <typename T>
void _cout(const T &c) {
  cerr << c;
}
void _cout(const int &c) {
  if (c == 1001001001)
    cerr << "inf";
  else if (c == -1001001001)
    cerr << "-inf";
  else
    cerr << c;
}
void _cout(const unsigned int &c) {
  if (c == 1001001001)
    cerr << "inf";
  else
    cerr << c;
}
void _cout(const long long &c) {
  if (c == 1001001001 || c == (1LL << 61) - 1)
    cerr << "inf";
  else if (c == -1001001001 || c == -((1LL << 61) - 1))
    cerr << "-inf";
  else
    cerr << c;
}
void _cout(const unsigned long long &c) {
  if (c == 1001001001 || c == (1LL << 61) - 1)
    cerr << "inf";
  else
    cerr << c;
}
template <typename T, typename U>
void _cout(const pair<T, U> &p) {
  cerr << "{ ";
  _cout(p.fi);
  cerr << ", ";
  _cout(p.se);
  cerr << " } ";
}
template <typename T>
void _cout(const vector<T> &v) {
  int s = v.size();
  cerr << "{ ";
  for (int i = 0; i < s; i++) {
    cerr << (i ? ", " : "");
    _cout(v[i]);
  }
  cerr << " } ";
}
template <typename T>
void _cout(const vector<vector<T>> &v) {
  cerr << "[ ";
  for (const auto &x : v) {
    cerr << endl;
    _cout(x);
    cerr << ", ";
  }
  cerr << endl << " ] ";
}
void dbg_out() { cerr << endl; }
template <typename T, class... U>
void dbg_out(const T &t, const U &... u) {
  _cout(t);
  if (sizeof...(u)) cerr << ", ";
  dbg_out(u...);
}
template <typename T>
void array_out(const T &v, int s) {
  cerr << "{ ";
  for (int i = 0; i < s; i++) {
    cerr << (i ? ", " : "");
    _cout(v[i]);
  }
  cerr << " } " << endl;
}
template <typename T>
void array_out(const T &v, int H, int W) {
  cerr << "[ ";
  for (int i = 0; i < H; i++) {
    cerr << (i ? ", " : "");
    array_out(v[i], W);
  }
  cerr << " ] " << endl;
}
#else
#define trc(...)
#define trca(...)
#define trcc(...)
#endif

inline int popcnt(unsigned long long a) { return __builtin_popcountll(a); }
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
int btw(T a, T x, T b) {
  return a <= x && x < b;
}
template <typename T, typename U>
T ceil(T a, U b) {
  return (a + b - 1) / b;
}
constexpr long long TEN(int n) {
  long long ret = 1, x = 10;
  while (n) {
    if (n & 1) ret *= x;
    x *= x;
    n >>= 1;
  }
  return ret;
}
template <typename T>
vector<T> mkrui(const vector<T> &v) {
  vector<T> ret(v.size() + 1);
  for (int i = 0; i < int(v.size()); i++) ret[i + 1] = ret[i] + v[i];
  return ret;
};
template <typename T>
vector<T> mkuni(const vector<T> &v) {
  vector<T> ret(v);
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
template <typename T = int>
vector<T> mkiota(int N) {
  vector<T> ret(N);
  iota(begin(ret), end(ret), 0);
  return ret;
}
template <typename T>
vector<int> mkinv(vector<T> &v) {
  vector<int> inv(v.size());
  for (int i = 0; i < (int)v.size(); i++) inv[v[i]] = i;
  return inv;
}

struct IoSetupNya {
  IoSetupNya() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    cerr << fixed << setprecision(7);
  }
} iosetupnya;

void solve();
int main() { solve(); }

#pragma endregion
using namespace std;

template <typename T>
struct edge {
  int src, to;
  T cost;

  edge(int to, T cost) : src(-1), to(to), cost(cost) {}
  edge(int src, int to, T cost) : src(src), to(to), cost(cost) {}

  edge &operator=(const int &x) {
    to = x;
    return *this;
  }

  operator int() const { return to; }
};
template <typename T>
using Edges = vector<edge<T>>;
template <typename T>
using WeightedGraph = vector<Edges<T>>;
using UnweightedGraph = vector<vector<int>>;

// Input of (Unweighted) Graph
UnweightedGraph graph(int N, int M = -1, bool is_directed = false,
                      bool is_1origin = true) {
  UnweightedGraph g(N);
  if (M == -1) M = N - 1;
  for (int _ = 0; _ < M; _++) {
    int x, y;
    cin >> x >> y;
    if (is_1origin) x--, y--;
    g[x].push_back(y);
    if (!is_directed) g[y].push_back(x);
  }
  return g;
}

// Input of Weighted Graph
template <typename T>
WeightedGraph<T> wgraph(int N, int M = -1, bool is_directed = false,
                        bool is_1origin = true) {
  WeightedGraph<T> g(N);
  if (M == -1) M = N - 1;
  for (int _ = 0; _ < M; _++) {
    int x, y;
    cin >> x >> y;
    T c;
    cin >> c;
    if (is_1origin) x--, y--;
    g[x].eb(x, y, c);
    if (!is_directed) g[y].eb(y, x, c);
  }
  return g;
}

// Input of Edges
template <typename T>
Edges<T> esgraph(int N, int M, int is_weighted = true, bool is_1origin = true) {
  Edges<T> es;
  for (int _ = 0; _ < M; _++) {
    int x, y;
    cin >> x >> y;
    T c;
    if (is_weighted)
      cin >> c;
    else
      c = 1;
    if (is_1origin) x--, y--;
    es.emplace_back(x, y, c);
  }
  return es;
}

// Input of Adjacency Matrix
template <typename T>
vector<vector<T>> adjgraph(int N, int M, T INF, int is_weighted = true,
                           bool is_directed = false, bool is_1origin = true) {
  vector<vector<T>> d(N, vector<T>(N, INF));
  for (int _ = 0; _ < M; _++) {
    int x, y;
    cin >> x >> y;
    T c;
    if (is_weighted)
      cin >> c;
    else
      c = 1;
    if (is_1origin) x--, y--;
    d[x][y] = c;
    if (!is_directed) d[y][x] = c;
  }
  return d;
}
using namespace std;


// Depth of Rooted Tree
// unvisited nodes : d = -1
vector<int> Depth(const UnweightedGraph &g, int start = 0) {
  vector<int> d(g.size(), -1);
  auto dfs = [&](auto rec, int cur, int par = -1) -> void {
    d[cur] = par == -1 ? 0 : d[par] + 1;
    for (auto &dst : g[cur]) {
      if (dst == par) continue;
      rec(rec, dst, cur);
    }
  };
  dfs(dfs, start);
  return d;
}

// Depth of Rooted Weighted Tree
// unvisited nodes : d = -1
template <typename T>
vector<T> Depth(const WeightedGraph<T> &g, int start = 0) {
  vector<T> d(g.size(), -1);
  auto dfs = [&](auto rec, int cur, T val, int par = -1) -> void {
    d[cur] = val;
    for (auto &dst : g[cur]) {
      if (dst == par) continue;
      rec(rec, dst, val + dst.cost, cur);
    }
  };
  dfs(dfs, start, 0);
  return d;
}

// Diameter of Tree
// return value : { {u, v}, length }
pair<pair<int, int>, int> Diameter(const UnweightedGraph &g) {
  auto d = Depth(g, 0);
  int u = max_element(begin(d), end(d)) - begin(d);
  d = Depth(g, u);
  int v = max_element(begin(d), end(d)) - begin(d);
  return make_pair(make_pair(u, v), d[v]);
}

// Diameter of Weighted Tree
// return value : { {u, v}, length }
template <typename T>
pair<pair<int, int>, T> Diameter(const WeightedGraph<T> &g) {
  auto d = Depth(g, 0);
  int u = max_element(begin(d), end(d)) - begin(d);
  d = Depth(g, u);
  int v = max_element(begin(d), end(d)) - begin(d);
  return make_pair(make_pair(u, v), d[v]);
}

// nodes on the path u-v ( O(N) )
template <typename G>
vector<int> Path(G &g, int u, int v) {
  vi ret;
  int end = 0;
  auto dfs = [&](auto rec, int cur, int par = -1) -> void {
    ret.push_back(cur);
    if (cur == v) {
      end = 1;
      return;
    }
    for (int dst : g[cur]) {
      if (dst == par) continue;
      rec(rec, dst, cur);
      if (end) return;
    }
    if (end) return;
    ret.pop_back();
  };
  dfs(dfs, u);
  return ret;
}
using namespace std;


// Rerooting
// f1(c1, c2) ... merge value of child node
// f2(memo[i], chd, par) ... return value from child node to parent node
// memo[i] ... result of subtree rooted i
// dp[i] ... result of tree rooted i
template <typename T, typename G, typename F1, typename F2>
struct Rerooting {
  const G &g;
  const F1 f1;
  const F2 f2;
  vector<T> memo, dp;
  T I;

  Rerooting(const G &g, const F1 f1, const F2 f2, const T &I)
      : g(g), f1(f1), f2(f2), memo(g.size(), I), dp(g.size(), I), I(I) {
    dfs(0, -1);
    efs(0, -1, I);
  }

  const T &operator[](int i) const { return dp[i]; }

  void dfs(int cur, int par) {
    for (auto &dst : g[cur]) {
      if (dst == par) continue;
      dfs(dst, cur);
      memo[cur] = f1(memo[cur], f2(memo[dst], dst, cur));
    }
  }

  void efs(int cur, int par, const T &pval) {
    // get cumulative sum
    vector<T> buf;
    for (auto dst : g[cur]) {
      if (dst == par) continue;
      buf.push_back(f2(memo[dst], dst, cur));
    }
    vector<T> head(buf.size() + 1), tail(buf.size() + 1);
    head[0] = tail[buf.size()] = I;
    for (int i = 0; i < (int)buf.size(); i++) head[i + 1] = f1(head[i], buf[i]);
    for (int i = (int)buf.size() - 1; i >= 0; i--)
      tail[i] = f1(tail[i + 1], buf[i]);

    // update
    dp[cur] = par == -1 ? head.back() : f1(pval, head.back());

    // propagate
    int idx = 0;
    for (auto &dst : g[cur]) {
      if (dst == par) continue;
      efs(dst, cur, f2(f1(pval, f1(head[idx], tail[idx + 1])), cur, dst));
      idx++;
    }
  }
};

/*

using T = ;
// identify element of f1, and answer of leaf
T I = ;
// merge value of child node
auto f1 = [&](T x, T y) -> T {

};
// return value from child node to parent node
auto f2 = [&](T x, int chd, int par) -> T {

};
Rerooting<T, decltype(g), decltype(f1), decltype(f2)> dp(g, f1, f2, I);

*/

void q() {
  ini(N, a, b, da, db);
  --a, --b;
  auto g = graph(N);
  

  if (da * 2 >= db) die("Alice");

  auto path = Path<vvi>(g, a, b);
  int d = sz(path) - 1;
  //trc(path);
  //trc(d);
  if (d >= 2 * da + 1) die("Bob");
  if (d <= da) die("Alice");

  auto diam = Diameter(g);
  if(diam.second <= 2 * da) die("Alice");
  
  using T = int;
  // identify element of f1, and answer of leaf
  T I = 0;
  // merge value of child node
  auto f1 = [&](T x, T y) -> T { return max(x, y); };
  // return value from child node to parent node
  auto f2 = [&](T x, int, int) -> T { return x + 1; };
  Rerooting<T, decltype(g), decltype(f1), decltype(f2)> dp(g, f1, f2, I);
  vi val = dp.dp;

  auto as = Depth(g, a);
  for(int i = 0; i < N; i++) {
    if(as[i] <= da and val[i] <= da) die("Alice");
  }
  out("Bob");
}

void solve() {
  ini(T);
  rep(i, T) q();
}