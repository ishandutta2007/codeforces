#include <bits/stdc++.h>

using namespace std;

// debugger, source: tourist
template <typename A, typename B>
string to_string(pair<A, B> p);
string to_string(const string &s) { return '"' + s + '"'; }
string to_string(const char *s) { return to_string((string)s); }
string to_string(bool b) { return (b ? "true" : "false"); }
template <size_t N>
string to_string(bitset<N> v) {
  string res = "";
  for (size_t i = 0; i < N; i++) res += static_cast<char>('0' + v[i]);
  return res;
}
template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) res += ", ";
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

struct Node {
  Node() { sum = min_pref = 0; }

  static Node worst() {
    Node res;
    return res;
  }

  template <typename S>
  void Apply(int l, int r, const S &val) {
    sum += val;
    min_pref += val;
  }

  void Pull(int l, int r, const Node &u, const Node &v) {
    sum = u.sum + v.sum;
    min_pref = min(u.min_pref, u.sum + v.min_pref);
  }

  void Push(int l, int r, Node &u, Node &v) {

  }

  long long sum;
  long long min_pref;
};

template <typename T>
class SegmentTree {
 public:
  explicit SegmentTree(int n) : n_(n) { t_.assign(n_ << 2 | 1, T()); }

  template <typename S>
  SegmentTree(int n, const vector<S> &val) : n_(n) {
    t_.assign(n_ << 2 | 1, T());
    Init(1, 0, n_ - 1, val);
  }

  // apply `val` to all position in range [x, y]
  template <typename S>
  void Update(int x, int y, const S &val) {
    Update(1, 0, n_ - 1, x, y, val);
  }

  T Get(int x, int y) { return Get(1, 0, n_ - 1, x, y); }

  // LeftMostHas/RightMostHas returns the left/right most position v
  // such that:
  //   - v is in the segment [x, y]
  //   - and f(u) = true if node u contains position v
  // Returns -1 if we can't find such position v
  template <typename S>
  int LeftMostHas(int x, int y, const function<bool(const T &, const S &)> &f,
                  const S &val) {
    return LeftMostHas(1, 0, n_ - 1, x, y, f, val);
  }
  template <typename S>
  int RightMostHas(int x, int y, const function<bool(const T &, const S &)> &f,
                   const S &val) {
    return RightMostHas(1, 0, n_ - 1, x, y, f, val);
  }

 private:
  template <typename S>
  void Init(int node, int l, int r, const vector<S> &val) {
    if (l == r) {
      t_[node].Apply(l, r, val[l]);
      return;
    }
    auto m = l + r >> 1;
    Init(node << 1, l, m, val);
    Init(node << 1 | 1, m + 1, r, val);
    t_[node].Pull(l, r, t_[node << 1], t_[node << 1 | 1]);
  }

  template <typename S>
  void Update(int node, int l, int r, int x, int y, const S &val) {
    if (x > r || y < l) return;
    if (x <= l && r <= y) {
      t_[node].Apply(l, r, val);
      return;
    }
    auto m = l + r >> 1;
    t_[node].Push(l, r, t_[node << 1], t_[node << 1 | 1]);
    Update(node << 1, l, m, x, y, val);
    Update(node << 1 | 1, m + 1, r, x, y, val);
    t_[node].Pull(l, r, t_[node << 1], t_[node << 1 | 1]);
  }

  T Get(int node, int l, int r, int x, int y) {
    if (x > r || y < l) return T::worst();
    if (x <= l && r <= y) return t_[node];
    auto m = l + r >> 1;
    t_[node].Push(l, r, t_[node << 1], t_[node << 1 | 1]);
    T p1 = Get(node << 1, l, m, x, y);
    T p2 = Get(node << 1 | 1, m + 1, r, x, y);
    T res;
    res.Pull(l, r, p1, p2);
    return res;
  }

  template <typename S>
  int LeftMostHas(int node, int l, int r, int x, int y,
                  const function<bool(const T &, const S &)> &f, const S &val) {
    if (x > r || y < l) return -1;
    if (!f(t_[node], val)) return -1;
    if (l == r) return l;
    int m = l + r >> 1;
    t_[node].Push(l, r, t_[node << 1], t_[node << 1 | 1]);
    if (int res = LeftMostHas(node << 1, l, m, x, y, f, val); res != -1) {
      return res;
    }
    return LeftMostHas(node << 1 | 1, m + 1, r, x, y, f, val);
  }

  template <typename S>
  int RightMostHas(int node, int l, int r, int x, int y,
                   const function<bool(const T &, const S &)> &f,
                   const S &val) {
    if (x > r || y < l) return -1;
    if (!f(t_[node], val)) return -1;
    if (l == r) return l;
    int m = l + r >> 1;
    t_[node].Push(l, r, t_[node << 1], t_[node << 1 | 1]);
    if (int res = RightMostHas(node << 1 | 1, m + 1, r, x, y, f, val);
        res != -1) {
      return res;
    }
    return RightMostHas(node << 1, l, m, x, y, f, val);
  }

  int n_;
  vector<T> t_;
};

struct Fraction {
  long long u, v;

  bool operator < (const Fraction &o) const {
    return u * o.v > o.u * v;
  }
  bool operator == (const Fraction &o) const {
    return u * o.v == o.u * v;
  }
};

string to_string(const Fraction &u) {
  return '{' + to_string(u.u) + ',' + to_string(u.v) + '}';
}

void Solve(int test) {
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (auto &u : a) {
    cin >> u;
  }
  vector<Fraction> vals;
  for (int i = 0; i < n; i++) {
    vals.push_back({a[i], 1});
  }

  vector<pair<Fraction, Fraction>> queries;

  vector<Fraction> tot;

  for (int i = 0; i < m; i++) {
    int k;
    cin >> k;
    vector<int> b(k);
    long long sum = 0;
    for (auto &u : b) {
      cin >> u;
      sum += u;
    }
    vals.push_back({sum, k});
    tot.push_back({sum, k});
    for (auto &u : b) {
      vals.push_back({sum - u, k - 1});
      queries.push_back({{sum, k}, {sum - u, k - 1}});
    }
  }
  sort(vals.begin(), vals.end());
  vals.resize(unique(vals.begin(), vals.end()) - vals.begin());
  debug(vals);

  SegmentTree<Node> st(vals.size());
  for (int i = 0; i < n; i++) {
    auto id = lower_bound(vals.begin(), vals.end(), Fraction({a[i], 1})) - vals.begin();
    debug(id, 1);
    st.Update(id, id, +1);
  }
  for (auto u : tot) {
    auto id = lower_bound(vals.begin(), vals.end(), u) - vals.begin();
    debug(id, -1);
    st.Update(id, id, -1);
  }
  debug(st.Get(0, vals.size() - 1).min_pref);
  for (auto [x, y] : queries) {
    auto id = lower_bound(vals.begin(), vals.end(), x) - vals.begin();
    st.Update(id, id, +1);
    id = lower_bound(vals.begin(), vals.end(), y) - vals.begin();
    st.Update(id, id, -1);

    auto cur_node = st.Get(0, vals.size() - 1);
    cout << (cur_node.min_pref >= 0);

    id = lower_bound(vals.begin(), vals.end(), x) - vals.begin();
    st.Update(id, id, -1);
    id = lower_bound(vals.begin(), vals.end(), y) - vals.begin();
    st.Update(id, id, +1);
  }
  cout << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int tc;
  cin >> tc;
  for (int test = 1; test <= tc; ++test) Solve(test);
  return 0;
}