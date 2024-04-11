#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e18;

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

const int CHAR = 26;

template <typename T>
class BIT {
 public:
  explicit BIT(int n) : n_(n), t_(n, T(0)) {}

  void Add(int x, T v) {
    assert(x >= 0);
    for (; x < n_; x += (x + 1) & -(x + 1)) t_[x] += v;
  }

  // [l, r] INCLUSIVELY
  void Add(int l, int r, T v) {
    assert(l <= r && l >= 0 && r < n_);
    Add(l, v);
    Add(r + 1, -v);
  }

  T Get(int x) const {
    assert(x >= 0 && x < n_);
    T res(0);
    for (; x >= 0; x -= (x + 1) & -(x + 1)) res += t_[x];
    return res;
  }

  // [l, r] INCLUSIVELY
  T Get(int l, int r) const {
    assert(l <= r && r < n_ && l >= 0);
    return Get(r) - (l ? Get(l - 1) : T(0));
  }

 private:
  int n_;
  vector<T> t_;
};

void Solve(int test) {
  int n;
  cin >> n;
  string s, t;
  cin >> s >> t;
  vector<queue<int>> pos(CHAR);
  for (int i = 0; i < n; i++) {
    pos[s[i] - 'a'].push(i);
  }

  BIT<int> bit(n);

  auto Get = [&](int u) {
    return u - bit.Get(u);
  };

  long long cur = 0;
  long long res = INF;
  for (int i = 0; i < n; i++) {
    long long delta = INF;
    for (int j = 0; j < t[i] - 'a'; j++) {
      if (!pos[j].empty()) {
        delta = min(delta, 1ll * Get(pos[j].front()));
      }
    }
    res = min(res, cur + delta);
    debug(i, res, delta);
    if (!pos[t[i] - 'a'].empty()) {
      cur += Get(pos[t[i] - 'a'].front());
      bit.Add(pos[t[i] - 'a'].front(), 1);
      pos[t[i] - 'a'].pop();
    } else {
      break;
    }
  }
  if (res >= INF) cout << -1 << '\n';
  else cout << res << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int tc;
  cin >> tc;
  for (int test = 1; test <= tc; ++test) Solve(test);
  return 0;
}