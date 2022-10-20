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
  int n;
  cin >> n;
  if (n == 1) {
    cout << "1\n1 1\n";
    return;
  }
  int m = (n * 2 + 1) / 3;
  int delta = n - m;
  vector<pair<int, int>> res;
  for (int i = 1; i <= delta; i++) {
    res.push_back({i, delta - i + 1});
  }
  int need = m - delta;
  if (need % 2 == delta % 2) {
    need--;
  }
  for (int i = 1; i <= need; i++) {
    res.push_back({delta + i, delta + need - i + 1});
  }
  if (delta + need < m) {
    res.push_back({m, m});
  }
  cout << res.size() << '\n';
  for (auto [u, v] : res) {
    cout << u << ' ' << v << '\n';
  }
}
 
int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int tc = 1;
  for (int test = 1; test <= tc; ++test) Solve(test);
  return 0;
}