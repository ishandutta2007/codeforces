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

void Solve(int test) {
  int n, m;
  cin >> n >> m;
  vector<int> a(m * n);
  for (auto &u : a) {
    cin >> u;
  }
  vector<int> order(m * n);
  iota(order.begin(), order.end(), 0);
  sort(order.begin(), order.end(), [&](int u, int v) {
    if (a[u] != a[v]) return a[u] < a[v];
    return u < v;
  });
  for (int l = 0, r = 0; l < order.size(); l = r) {
    while (r < order.size() && a[order[l]] == a[order[r]]) {
      r++;
    }
    int last = l;
    for (int i = l; i <= r; i++) {
      if (i % m == 0) {
        reverse(order.begin() + last, order.begin() + i);
        last = i;
      }
    }
    reverse(order.begin() + last, order.begin() + r);
  }
  vector<int> pos(m * n);
  for (int i = 0; i < m * n; i++) {
    pos[order[i]] = i;
  }
  vector<int> has(m * n, 0);
  debug(order);
  debug(pos);
  int res = 0;
  for (int i = 0; i < m * n; i++) {
    int first_pos = (pos[i] / m) * m;
    for (int j = first_pos; j < pos[i]; j++) {
      res += has[j];
    }
    has[pos[i]]++;
  }
  cout << res << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int tc;
  cin >> tc;
  for (int test = 1; test <= tc; ++test) Solve(test);
  return 0;
}