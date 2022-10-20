#include <bits/stdc++.h>

using namespace std;

// debugger, source: tourist
template <typename A, typename B>
string to_string(pair<A, B> p);
string to_string(const string& s) { return '"' + s + '"'; }
string to_string(const char* s) { return to_string((string) s); }
string to_string(bool b) { return (b ? "true" : "false"); }
template <size_t N> string to_string(bitset<N> v) {
  string res = "";
  for (size_t i = 0; i < N; i++) res += static_cast<char>('0' + v[i]);
  return res; }
template <typename A> string to_string(A v) {
  bool first = true; string res = "{";
  for (const auto &x : v)
    {if (!first) res += ", "; first = false; res += to_string(x);}
  res += "}"; return res; }
template <typename A, typename B> string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; }
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T){cerr << " " << to_string(H);debug_out(T...);}
#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

template <typename T>
inline bool max_to(T &u, const T &v) { return u < v ? (u = v, true) : false; }
template <typename T>
inline bool min_to(T &u, const T &v) { return u > v ? (u = v, true) : false; }

const int N = 50010;

// 1-indexed
// Can't add when x = 0
template<typename T = int>
struct BIT {
  int n;
  vector<T> t;
  vector<int> changed;

  BIT(int n = 0) : n(n), t(n + 1, n + 1) {}

  void Add(int x, T v) {
    for (; x <= n; x += x & -x) {
      min_to(t[x], v);
      changed.push_back(x);
    }
  }

  T Get(int x) {
    T res = n + 1;
    for (; x; x -= x & -x) min_to(res, t[x]);
    return res;
  }

  void Reset() {
    while (!changed.empty()) {
      t[changed.back()] = n + 1;
      changed.pop_back();
    }
  }
};

BIT<int> t(N);

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(int test) {
  int n;
  cin >> n;

  struct Data {
    int a[5];
    int id;
  };

  vector<Data> a(n);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 5; j++) {
      cin >> a[i].a[j];
    }
    a[i].id = i;
  }
  shuffle(a.begin(), a.end(), rng);

  auto Cmp = [&](int u, int v) {
    int lose = 0;
    for (int i = 0; i < 5; i++) {
      lose += a[u].a[i] > a[v].a[i];
    }
    return lose >= 3;
  };

  int res = -1;
  for (int i = 0; i < n; i++) {
    if (res != -1 && Cmp(res, i)) {
      res = -1;
    }
    // debug(i, res);
    if (res == -1) {
      bool f = 0;
      for (int j = i - 1; j >= 0; j--) {
        if (Cmp(i, j)) {
          f = 1;
          break;
        }
      }
      if (!f) res = i;
    }
  }
  if (res == -1) cout << res << '\n';
  else cout << a[res].id + 1 << '\n';
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int tc;
  cin >> tc;
  for (int test = 1; test <= tc; ++test) solve(test);
  return 0;
}