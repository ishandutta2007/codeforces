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

int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, q;
  cin >> n >> q;
  string s;
  cin >> s;
  int res = 0;

  auto IsBad = [&](int u) {
    return s[u] == 'a' && s[u + 1] == 'b' && s[u + 2] == 'c';
  };

  for (int i = 0; i + 2 < n; i++) {
    res += IsBad(i);
  }

  debug(res);

  while (q--) {
    int pos;
    char c;
    cin >> pos >> c;
    pos--;
    for (int i = max(0, pos - 2); i <= min(pos, n - 3); i++) {
      res -= IsBad(i);
    }
    debug("before", res);
    s[pos] = c;
    debug(s);
    for (int i = max(0, pos - 2); i <= min(pos, n - 3); i++) {
      res += IsBad(i);
    }
    debug("after", res);
    cout << res << '\n';
  }
  return 0;
}