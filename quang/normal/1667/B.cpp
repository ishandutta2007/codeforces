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

// Node example for range adding and range max getting
template <typename T>
struct NodeMax {
  NodeMax() { max_val = -1e18; }

  static NodeMax worst() {
    NodeMax res;
    res.max_val = -1e18;
    return res;
  }

  template <typename S>
  void Apply(int l, int r, const S &val) {
    max_val = max(max_val, val);
  }

  void Pull(int l, int r, const NodeMax &u, const NodeMax &v) {
    max_val = max(u.max_val, v.max_val);
  }

  void Push(int l, int r, NodeMax &u, NodeMax &v) {}

  T max_val;
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

void Solve(int test) {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &u : a) {
    cin >> u;
  }
  vector<long long> sum(n + 1);
  for (int i = 0; i < n; i++) {
    sum[i + 1] = sum[i] + a[i];
  }
  auto vals = sum;
  sort(vals.begin(), vals.end());
  vals.resize(unique(vals.begin(), vals.end()) - vals.begin());
  auto m = vals.size();
  SegmentTree<NodeMax<long long>> t_sub(m), t(m), t_add(m);
  vector<long long> dp(n + 1, -1e18);
  for (int i = 0; i <= n; i++) {
    auto pos = lower_bound(vals.begin(), vals.end(), sum[i]) - vals.begin();
    debug(i, pos);
    if (i > 0) {
      debug(dp[i]);
      dp[i] = max(dp[i], t_sub.Get(0, pos - 1).max_val + i);
      dp[i] = max(dp[i], t.Get(pos, pos).max_val);
      dp[i] = max(dp[i], t_add.Get(pos + 1, m - 1).max_val - i);
    } else {
      dp[i] = 0;
    }
    debug(i, dp[i]);
    t_sub.Update(pos, pos, dp[i] - i);
    t.Update(pos, pos, dp[i]);
    t_add.Update(pos, pos, dp[i] + i);
  }
  cout << dp[n] << '\n';
}
 
int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int tc;
  cin >> tc;
  for (int test = 1; test <= tc; ++test) Solve(test);
  return 0;
}