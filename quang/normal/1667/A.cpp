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
  vector<int> a(n);
  for (auto &u : a) {
    cin >> u;
  } 

debug(a);
  auto Get = [&](int u) {
    long long res = 0;
    long long last = 0;
    for (int i = u + 1; i < n; i++) {
      long long need = last / a[i] + 1;
      res += need;
      last = a[i] * need;
      debug(i, need, last);
    }
    last = 0;
    for (int i = u - 1; i >= 0; i--) {
     long long need = last / a[i] + 1;
      res += need;
      last = a[i] * need; 
    }
    return res;
  };

  long long res = 1e18;
  for (int i = 0; i < n; i++) {
    res = min(res, Get(i));
  }
  cout << res << '\n';
}
 
int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int tc = 1;
  // cin >> tc;
  for (int test = 1; test <= tc; ++test) Solve(test);
  return 0;
}