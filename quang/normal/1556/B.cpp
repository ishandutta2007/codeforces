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
  int num[2] = {0, 0};
  for (auto &u : a) {
    cin >> u;
    u %= 2;
    num[u]++; 
  }
  debug(num[0], num[1]);
  if (abs(num[0] - num[1]) > 1) {
    cout << -1 << '\n';
    return;
  }
  long long res = 1e18;

  debug(a);

  auto Solve = [&]() -> long long{
    if (num[0] < num[1]) return 1e18;
    int pos = 0;
    long long res = 0;
    for (int i = 0; i < n; i++) {
      if (a[i]) continue;
      res += abs(i - pos);
      pos += 2;
    }
    return res;
  };

  for (int it = 0; it < 2; it++) {
    res = min(res, Solve());
    swap(num[0], num[1]);
    for (auto &u : a) {
      u ^= 1;
    }
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