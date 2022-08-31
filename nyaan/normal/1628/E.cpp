/**
 *  date : 2022-01-24 18:20:01
 */

#define NDEBUG

// http://yosupo06.github.io/Algorithm/src/base.hpp

#include <algorithm>

#include <array>

#include <bitset>

#include <cassert>

#include <complex>

#include <cstdio>

#include <cstring>

#include <iostream>

#include <map>

#include <numeric>

#include <queue>

#include <set>

#include <string>

#include <unordered_map>

#include <unordered_set>

#include <vector>


using namespace std;

using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n - 1); }
template <class T>
using V = vector<T>;
template <class T>
using VV = V<V<T>>;

#ifdef LOCAL

ostream& operator<<(ostream& os, __int128_t x) {
  if (x < 0) {
    os << "-";
    x *= -1;
  }
  if (x == 0) {
    return os << "0";
  }
  string s;
  while (x) {
    s += char(x % 10 + '0');
    x /= 10;
  }
  reverse(s.begin(), s.end());
  return os << s;
}
ostream& operator<<(ostream& os, __uint128_t x) {
  if (x == 0) {
    return os << "0";
  }
  string s;
  while (x) {
    s += char(x % 10 + '0');
    x /= 10;
  }
  reverse(s.begin(), s.end());
  return os << s;
}

template <class T, class U>
ostream& operator<<(ostream& os, const pair<T, U>& p);
template <class T>
ostream& operator<<(ostream& os, const V<T>& v);
template <class T>
ostream& operator<<(ostream& os, const deque<T>& v);
template <class T, size_t N>
ostream& operator<<(ostream& os, const array<T, N>& a);
template <class T>
ostream& operator<<(ostream& os, const set<T>& s);
template <class T, class U>
ostream& operator<<(ostream& os, const map<T, U>& m);

template <class T, class U>
ostream& operator<<(ostream& os, const pair<T, U>& p) {
  return os << "P(" << p.first << ", " << p.second << ")";
}

template <class T>
ostream& operator<<(ostream& os, const V<T>& v) {
  os << "[";
  bool f = false;
  for (auto d : v) {
    if (f) os << ", ";
    f = true;
    os << d;
  }
  return os << "]";
}

template <class T>
ostream& operator<<(ostream& os, const deque<T>& v) {
  os << "[";
  bool f = false;
  for (auto d : v) {
    if (f) os << ", ";
    f = true;
    os << d;
  }
  return os << "]";
}
template <class T, size_t N>
ostream& operator<<(ostream& os, const array<T, N>& a) {
  os << "[";
  bool f = false;
  for (auto d : a) {
    if (f) os << ", ";
    f = true;
    os << d;
  }
  return os << "]";
}

template <class T>
ostream& operator<<(ostream& os, const set<T>& s) {
  os << "{";
  bool f = false;
  for (auto d : s) {
    if (f) os << ", ";
    f = true;
    os << d;
  }
  return os << "}";
}
template <class T>
ostream& operator<<(ostream& os, const multiset<T>& s) {
  os << "{";
  bool f = false;
  for (auto d : s) {
    if (f) os << ", ";
    f = true;
    os << d;
  }
  return os << "}";
}

template <class T, class U>
ostream& operator<<(ostream& os, const map<T, U>& s) {
  os << "{";
  bool f = false;
  for (auto p : s) {
    if (f) os << ", ";
    f = true;
    os << p.first << ": " << p.second;
  }
  return os << "}";
}

struct PrettyOS {
  ostream& os;
  bool first;

  template <class T>
  auto operator<<(T&& x) {
    if (!first) os << ", ";
    first = false;
    os << x;
    return *this;
  }
};
template <class... T>
void dbg0(T&&... t) {
  (PrettyOS{cerr, true} << ... << t);
}
#define dbg(...)                                        \
  do {                                                  \
    cerr << __LINE__ << " : " << #__VA_ARGS__ << " = "; \
    dbg0(__VA_ARGS__);                                  \
    cerr << endl;                                       \
  } while (false);
#else
#define dbg(...)
#endif

// http://yosupo06.github.io/Algorithm/src/util/fast_io.hpp

#include <unistd.h>


struct Scanner {
  int fd = -1;
  char line[(1 << 15) + 1];
  size_t st = 0, ed = 0;
  void reread() {
    memmove(line, line + st, ed - st);
    ed -= st;
    st = 0;
    ed += ::read(fd, line + ed, (1 << 15) - ed);
    line[ed] = '\0';
  }
  bool succ() {
    while (true) {
      if (st == ed) {
        reread();
        if (st == ed) return false;
      }
      while (st != ed && isspace(line[st])) st++;
      if (st != ed) break;
    }
    if (ed - st <= 50) {
      bool sep = false;
      for (size_t i = st; i < ed; i++) {
        if (isspace(line[i])) {
          sep = true;
          break;
        }
      }
      if (!sep) reread();
    }
    return true;
  }
  template <class T, enable_if_t<is_same<T, string>::value, int> = 0>
  bool read_single(T& ref) {
    if (!succ()) return false;
    while (true) {
      size_t sz = 0;
      while (st + sz < ed && !isspace(line[st + sz])) sz++;
      ref.append(line + st, sz);
      st += sz;
      if (!sz || st != ed) break;
      reread();
    }
    return true;
  }
  template <class T, enable_if_t<is_integral<T>::value, int> = 0>
  bool read_single(T& ref) {
    if (!succ()) return false;
    bool neg = false;
    if (line[st] == '-') {
      neg = true;
      st++;
    }
    ref = T(0);
    while (isdigit(line[st])) {
      ref = 10 * ref + (line[st++] & 0xf);
    }
    if (neg) ref = -ref;
    return true;
  }
  template <class T>
  bool read_single(V<T>& ref) {
    for (auto& d : ref) {
      if (!read_single(d)) return false;
    }
    return true;
  }
  void read() {}
  template <class H, class... T>
  void read(H& h, T&... t) {
    bool f = read_single(h);
    assert(f);
    read(t...);
  }
  Scanner(FILE* fp) : fd(fileno(fp)) {}
};

struct Printer {
 public:
  template <bool F = false>
  void write() {}
  template <bool F = false, class H, class... T>
  void write(const H& h, const T&... t) {
    if (F) write_single(' ');
    write_single(h);
    write<true>(t...);
  }
  template <class... T>
  void writeln(const T&... t) {
    write(t...);
    write_single('\n');
  }

  Printer(FILE* _fp) : fp(_fp) {}
  ~Printer() { flush(); }

 private:
  static constexpr size_t SIZE = 1 << 15;
  FILE* fp;
  char line[SIZE], small[50];
  size_t pos = 0;
  void flush() {
    fwrite(line, 1, pos, fp);
    pos = 0;
  }
  void write_single(const char& val) {
    if (pos == SIZE) flush();
    line[pos++] = val;
  }
  template <class T, enable_if_t<is_integral<T>::value, int> = 0>
  void write_single(T val) {
    if (pos > (1 << 15) - 50) flush();
    if (val == 0) {
      write_single('0');
      return;
    }
    if (val < 0) {
      write_single('-');
      val = -val;  // todo min
    }
    size_t len = 0;
    while (val) {
      small[len++] = char(0x30 | (val % 10));
      val /= 10;
    }
    for (size_t i = 0; i < len; i++) {
      line[pos + i] = small[len - 1 - i];
    }
    pos += len;
  }
  void write_single(const string& s) {
    for (char c : s) write_single(c);
  }
  void write_single(const char* s) {
    size_t len = strlen(s);
    for (size_t i = 0; i < len; i++) write_single(s[i]);
  }
  template <class T>
  void write_single(const V<T>& val) {
    auto n = val.size();
    for (size_t i = 0; i < n; i++) {
      if (i) write_single(' ');
      write_single(val[i]);
    }
  }
};

Scanner sc{stdin};
Printer pr{stdout};


struct UnionFind {
  vector<int> data;
  UnionFind(int N) : data(N, -1) {}

  int find(int k) { return data[k] < 0 ? k : data[k] = find(data[k]); }

  int unite(int x, int y) {
    if ((x = find(x)) == (y = find(y))) return false;
    if (data[x] > data[y]) swap(x, y);
    data[x] += data[y];
    data[y] = x;
    return true;
  }

  // f ... merge function
  template<typename F>
  int unite(int x, int y,const F &f) {
    if ((x = find(x)) == (y = find(y))) return false;
    if (data[x] > data[y]) swap(x, y);
    data[x] += data[y];
    data[y] = x;
    f(x, y);
    return true;
  }

  int size(int k) { return -data[find(k)]; }

  int same(int x, int y) { return find(x) == find(y); }
};

/**
 * @brief Union Find(Disjoint Set Union)
 * @docs docs/data-structure/union-find.md
 */


template <typename T>
struct edge {
  int src, to;
  T cost;

  edge(int _to, T _cost) : src(-1), to(_to), cost(_cost) {}
  edge(int _src, int _to, T _cost) : src(_src), to(_to), cost(_cost) {}

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
    g[x].emplace_back(x, y, c);
    if (!is_directed) g[y].emplace_back(y, x, c);
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

/**
 * @brief 
 * @docs docs/graph/graph-template.md
 */


// LazySegmentTree
template <typename T, typename E, typename F, typename G, typename H>
struct LazySegmentTree {
  int n, height;
  F f;
  G g;
  H h;
  T ti;
  E ei;
  vector<T> dat;
  vector<E> laz;
  LazySegmentTree(int _n, F _f, G _g, H _h, T _ti, E _ei)
      : f(_f), g(_g), h(_h), ti(_ti), ei(_ei) {
    init(_n);
  }
  LazySegmentTree(const vector<T> &v, F _f, G _g, H _h, T _ti, E _ei)
      : f(_f), g(_g), h(_h), ti(_ti), ei(_ei) {
    init((int)v.size());
    build(v);
  }
  void init(int _n) {
    n = 1;
    height = 0;
    while (n < _n) n <<= 1, height++;
    dat.assign(2 * n, ti);
    laz.assign(2 * n, ei);
  }
  void build(const vector<T> &v) {
    int _n = v.size();
    init(_n);
    for (int i = 0; i < _n; i++) dat[n + i] = v[i];
    for (int i = n - 1; i; i--)
      dat[i] = f(dat[(i << 1) | 0], dat[(i << 1) | 1]);
  }
  inline T reflect(int k) { return laz[k] == ei ? dat[k] : g(dat[k], laz[k]); }
  inline void eval(int k) {
    if (laz[k] == ei) return;
    laz[(k << 1) | 0] = h(laz[(k << 1) | 0], laz[k]);
    laz[(k << 1) | 1] = h(laz[(k << 1) | 1], laz[k]);
    dat[k] = reflect(k);
    laz[k] = ei;
  }
  inline void thrust(int k) {
    for (int i = height; i; i--) eval(k >> i);
  }
  inline void recalc(int k) {
    while (k >>= 1) dat[k] = f(reflect((k << 1) | 0), reflect((k << 1) | 1));
  }
  void update(int a, int b, E x) {
    if (a >= b) return;
    thrust(a += n);
    thrust(b += n - 1);
    for (int l = a, r = b + 1; l < r; l >>= 1, r >>= 1) {
      if (l & 1) laz[l] = h(laz[l], x), l++;
      if (r & 1) --r, laz[r] = h(laz[r], x);
    }
    recalc(a);
    recalc(b);
  }
  void set_val(int a, T x) {
    thrust(a += n);
    dat[a] = x;
    laz[a] = ei;
    recalc(a);
  }
  T get_val(int a) {
    thrust(a += n);
    return reflect(a);
  }
  T query(int a, int b) {
    if (a >= b) return ti;
    thrust(a += n);
    thrust(b += n - 1);
    T vl = ti, vr = ti;
    for (int l = a, r = b + 1; l < r; l >>= 1, r >>= 1) {
      if (l & 1) vl = f(vl, reflect(l++));
      if (r & 1) vr = f(reflect(--r), vr);
    }
    return f(vl, vr);
  }
};

template <typename T, typename F>
struct SegmentTree {
  int N;
  int size;
  vector<T> seg;
  const F f;
  const T I;

  SegmentTree(F _f, const T &I_) : N(0), size(0), f(_f), I(I_) {}

  SegmentTree(int _N, F _f, const T &I_) : f(_f), I(I_) { init(_N); }

  SegmentTree(const vector<T> &v, F _f, T I_) : f(_f), I(I_) {
    init(v.size());
    for (int i = 0; i < (int)v.size(); i++) {
      seg[i + size] = v[i];
    }
    build();
  }

  void init(int _N) {
    N = _N;
    size = 1;
    while (size < N) size <<= 1;
    seg.assign(2 * size, I);
  }

  void set(int k, T x) { seg[k + size] = x; }

  void build() {
    for (int k = size - 1; k > 0; k--) {
      seg[k] = f(seg[2 * k], seg[2 * k + 1]);
    }
  }

  void update(int k, T x) {
    k += size;
    seg[k] = x;
    while (k >>= 1) {
      seg[k] = f(seg[2 * k], seg[2 * k + 1]);
    }
  }

  void add(int k, T x) {
    k += size;
    seg[k] += x;
    while (k >>= 1) {
      seg[k] = f(seg[2 * k], seg[2 * k + 1]);
    }
  }

  // query to [a, b)
  T query(int a, int b) {
    T L = I, R = I;
    for (a += size, b += size; a < b; a >>= 1, b >>= 1) {
      if (a & 1) L = f(L, seg[a++]);
      if (b & 1) R = f(seg[--b], R);
    }
    return f(L, R);
  }

  T &operator[](const int &k) { return seg[k + size]; }

  // check(a[l] * ...  * a[r-1])  true  r
  // ( true  N )
  template <class C>
  int max_right(int l, C check) {
    assert(0 <= l && l <= N);
    assert(check(I) == true);
    if (l == N) return N;
    l += size;
    T sm = I;
    do {
      while (l % 2 == 0) l >>= 1;
      if (!check(f(sm, seg[l]))) {
        while (l < size) {
          l = (2 * l);
          if (check(f(sm, seg[l]))) {
            sm = f(sm, seg[l]);
            l++;
          }
        }
        return l - size;
      }
      sm = f(sm, seg[l]);
      l++;
    } while ((l & -l) != l);
    return N;
  }

  // check(a[l] * ... * a[r-1])  true  l
  // ( true  0 )
  template <typename C>
  int min_left(int r, C check) {
    assert(0 <= r && r <= N);
    assert(check(I) == true);
    if (r == 0) return 0;
    r += size;
    T sm = I;
    do {
      r--;
      while (r > 1 && (r % 2)) r >>= 1;
      if (!check(f(seg[r], sm))) {
        while (r < size) {
          r = (2 * r + 1);
          if (check(f(seg[r], sm))) {
            sm = f(seg[r], sm);
            r--;
          }
        }
        return r + 1 - size;
      }
      sm = f(seg[r], sm);
    } while ((r & -r) != r);
    return 0;
  }
};


template <typename G>
struct HeavyLightDecomposition {
 private:
  void dfs_sz(int cur) {
    size[cur] = 1;
    for (auto& dst : g[cur]) {
      if (dst == par[cur]) {
        if (g[cur].size() >= 2 && int(dst) == int(g[cur][0]))
          swap(g[cur][0], g[cur][1]);
        else
          continue;
      }
      depth[dst] = depth[cur] + 1;
      par[dst] = cur;
      dfs_sz(dst);
      size[cur] += size[dst];
      if (size[dst] > size[g[cur][0]]) {
        swap(dst, g[cur][0]);
      }
    }
  }

  void dfs_hld(int cur) {
    down[cur] = id++;
    for (auto dst : g[cur]) {
      if (dst == par[cur]) continue;
      nxt[dst] = (int(dst) == int(g[cur][0]) ? nxt[cur] : int(dst));
      dfs_hld(dst);
    }
    up[cur] = id;
  }

  // [u, v)
  vector<pair<int, int>> ascend(int u, int v) const {
    vector<pair<int, int>> res;
    while (nxt[u] != nxt[v]) {
      res.emplace_back(down[u], down[nxt[u]]);
      u = par[nxt[u]];
    }
    if (u != v) res.emplace_back(down[u], down[v] + 1);
    return res;
  }

  // (u, v]
  vector<pair<int, int>> descend(int u, int v) const {
    if (u == v) return {};
    if (nxt[u] == nxt[v]) return {{down[u] + 1, down[v]}};
    auto res = descend(u, par[nxt[v]]);
    res.emplace_back(down[nxt[v]], down[v]);
    return res;
  }

 public:
  G& g;
  int id;
  vector<int> size, depth, down, up, nxt, par;
  HeavyLightDecomposition(G& _g, int root = 0)
      : g(_g),
        id(0),
        size(g.size(), 0),
        depth(g.size(), 0),
        down(g.size(), -1),
        up(g.size(), -1),
        nxt(g.size(), root),
        par(g.size(), root) {
    dfs_sz(root);
    dfs_hld(root);
  }

  void build(int root) {
    dfs_sz(root);
    dfs_hld(root);
  }

  pair<int, int> idx(int i) const { return make_pair(down[i], up[i]); }

  template <typename F>
  void path_query(int u, int v, bool vertex, const F& f) {
    int l = lca(u, v);
    for (auto&& [a, b] : ascend(u, l)) {
      int s = a + 1, t = b;
      s > t ? f(t, s) : f(s, t);
    }
    if (vertex) f(down[l], down[l] + 1);
    for (auto&& [a, b] : descend(l, v)) {
      int s = a, t = b + 1;
      s > t ? f(t, s) : f(s, t);
    }
  }

  template <typename F>
  void path_noncommutative_query(int u, int v, bool vertex, const F& f) {
    int l = lca(u, v);
    for (auto&& [a, b] : ascend(u, l)) f(a + 1, b);
    if (vertex) f(down[l], down[l] + 1);
    for (auto&& [a, b] : descend(l, v)) f(a, b + 1);
  }

  template <typename F>
  void subtree_query(int u, bool vertex, const F& f) {
    f(down[u] + int(!vertex), up[u]);
  }

  int lca(int a, int b) {
    while (nxt[a] != nxt[b]) {
      if (down[a] < down[b]) swap(a, b);
      a = par[nxt[a]];
    }
    return depth[a] < depth[b] ? a : b;
  }

  int dist(int a, int b) { return depth[a] + depth[b] - depth[lca(a, b)] * 2; }
};

/**
 * @brief Heavy Light Decomposition()
 * @docs docs/tree/heavy-light-decomposition.md
 */


// 
// es (es )
//
//  : (graph, , root)
template <typename T>
tuple<WeightedGraph<T>, vector<T>, int> process_of_merging_tree(
    const Edges<T>& es) {
  int n = 1;
  for (auto& e : es) n = max(n, max(e.src, e.to) + 1);
 
  WeightedGraph<T> g(n * 2 - 1);
  vector<T> nodes(n - 1);
 
  UnionFind uf(n);
  vector<int> roots(n);
  iota(begin(roots), end(roots), 0);
  int aux = n;
 
  for (auto& e : es) {
    int u = e.src, v = e.to;
    if (uf.same(u, v)) continue;
    T w = e.cost;
    auto f = [&](int x, int y) {
      g[aux].emplace_back(aux, roots[x], w);
      g[aux].emplace_back(aux, roots[y], w);
      roots[x] = roots[y] = aux;
    };
    uf.unite(u, v, f);
    nodes[aux - n] = w;
    aux++;
  }
  assert(aux == 2 * n - 1);
 
  return {g, nodes, 2 * n - 2};
}


#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define each(x, v) for (auto& x : v)
#define all(v) begin(v), end(v)
ll inf = 1001001001;

template <typename T, typename U>
bool amax(T& t, const U& u) {
  return t < u ? (t = u, true) : false;
}
template <typename T, typename U>
bool amin(T& t, const U& u) {
  return t > u ? (t = u, true) : false;
}

int main() {
  ll N, M;
  sc.read(N, M);
  WeightedGraph<ll> g(N);
  rep(_, N - 1) {
    int u, v, w;
    sc.read(u, v, w);
    --u, --v;
    g[u].emplace_back(u, v, w);
    g[v].emplace_back(v, u, w);
  }

  Edges<ll> es;
  rep(i, N) each(e, g[i]) if (e.src < e.to) es.emplace_back(e);
  sort(all(es), [](edge<ll> s, edge<ll> t) { return s.cost < t.cost; });
  WeightedGraph<ll> aux;
  vector<ll> nodes;
  int root;
  tie(aux, nodes, root) = process_of_merging_tree(es);
  HeavyLightDecomposition hld(aux, root);

  vector<ll> initseg(2 * N - 1, -1);
  rep(i, N - 1) {
    int j = hld.down[i + N];
    ll w = nodes[i];
    initseg[j] = w;
  }
  SegmentTree segmax(
      initseg, [](ll s, ll t) { return max(s, t); }, -1LL);

  struct Data {
    int ma, mi, f, allma, allmi;
    Data() : ma(-inf), mi(inf), f(0), allma(-inf), allmi(inf) {}
    Data(int a, int b, int c, int d, int e)
        : ma(a), mi(b), f(c), allma(d), allmi(e) {}
    Data(int a) : ma(-inf), mi(inf), f(0), allma(a), allmi(a) {}
  };

  auto f1 = [](Data x, Data y) {
    Data z;
    z.f = x.f | y.f;
    if (x.f) amax(z.ma, x.ma), amin(z.mi, x.mi);
    if (y.f) amax(z.ma, y.ma), amin(z.mi, y.mi);
    z.allma = max(x.allma, y.allma);
    z.allmi = min(x.allmi, y.allmi);
    return z;
  };
  auto f2 = [](Data x, int y) {
    if (y == 0) return x;
    if (y == 1) {
      x.f = 1, x.ma = x.allma, x.mi = x.allmi;
      return x;
    }
    x.f = 0, x.ma = -inf, x.mi = inf;
    return x;
  };
  auto f3 = [](int, int z) { return z; };
  Data ti{};
  int ei = 0;

  V<Data> init(N);
  rep(i, N) init[i] = Data{hld.down[i]};
  LazySegmentTree seg(init, f1, f2, f3, ti, ei);

  vector<int> downinv(hld.down.size(), -1);
  rep(i, hld.down.size()) downinv[hld.down[i]] = i;

  while (M--) {
    int cmd;
    sc.read(cmd);
    if (cmd == 1) {
      int L, R;
      sc.read(L, R);
      --L;
      seg.update(L, R, 1);
    } else if (cmd == 2) {
      int L, R;
      sc.read(L, R);
      --L;
      seg.update(L, R, -1);
    } else {
      int x;
      sc.read(x);
      --x;
      auto q = seg.query(0, N);
      int ma = q.ma, mi = q.mi;
      int cur = hld.down[x];
      amax(ma, cur), amin(mi, cur);
      int n1 = downinv[ma];
      int n2 = downinv[mi];
      ll ans = -1;
      hld.path_query(n1, n2, true,
                     [&](int u, int v) { amax(ans, segmax.query(u, v)); });
      pr.writeln(ans);
    }
  }
}