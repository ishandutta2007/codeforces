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

const int INF = 1e5;

vector<vector<int>> states;
vector<vector<int>> g;
int s;
int one_char[3];

struct Node {
  Node() {
    min_val.resize(s, INF);
  }

  static Node worst() {
    Node res;
    return res;
  }

  template <typename S>
  void Apply(int l, int r, const S &val) {
    min_val.assign(s, INF);
    for (int i = 0; i < 3; i++) {
      if (val - 'a' != i) {
        min_val[one_char[i]] = 1;
      } else {
        min_val[one_char[i]] = 0;
      }
    }
  }

  void Pull(int l, int r, const Node &u, const Node &v) {
    min_val.assign(s, INF);
    for (int i = 0; i < s; i++) {
      for (int j = 0; j < s; j++) {
        if (g[i][j] != -1) {
          min_val[g[i][j]] = min(min_val[g[i][j]], u.min_val[i] + v.min_val[j]);
        }
      }
    }
  }

  void Push(int l, int r, Node &u, Node &v) {
  }

  vector<int> min_val;
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


int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  for (int i = -1; i <= 1; i++) {
    for (int j = 0; j <= 2; j++) {
      if (j < i) continue;
      for (int k = 1; k <= 2; k++) {
        if (k < j) continue;
        vector<int> now = {i, j, k};
        states.push_back(now);
      }
    }
  }
  s = states.size();
  g.resize(s, vector<int>(s));
  for (int i = 0; i < s; i++) {
    for (int j = 0; j < s; j++) {
      vector<int> now(3);
      for (int k = 0; k < 3; k++) {
        auto cur = states[i][k];
        if (cur != 2) now[k] = states[j][cur + 1];
        else now[k] = cur;
      }
      int pos = -1;
      for (int k = 0; k < s; k++) {
        if (now == states[k]) {
          pos = k;
          break;
        }
      }
      g[i][j] = pos;
    }
  }

  for (int i = 0; i < 3; i++) {
    vector<int> val(3);
    iota(val.begin(), val.end(), -1);
    val[i] = i;
    int pos = -1;
    for (int k = 0; k < s; k++) {
      if (val == states[k]) {
        pos = k;
        break;
      }
    }
    one_char[i] = pos;
  }

  int n, q;
  cin >> n >> q;
  string s;
  cin >> s;
  vector<char> vec_s(n);
  for (int i = 0; i < n; i++) {
    vec_s[i] = s[i];
  }

  SegmentTree<Node> st(n, vec_s);
  while (q--) {
    int pos;
    char c;
    cin >> pos >> c;
    pos--;
    st.Update(pos, pos, c);
    auto res = st.Get(0, n - 1);
    cout << *min_element(res.min_val.begin(), res.min_val.end()) << '\n';
  }
  return 0;
}