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

void solve(int test) {
  int n;
  cin >> n;
  vector<long long> a(n);
  for (auto &u : a) cin >> u;
  vector<long long> b(n - 1);
  for (int i = 0; i + 1 < n; i++) {
    b[i] = abs(a[i + 1] - a[i]);
  }
  int res = 1;
  // debug(b);
  vector<pair<long long, int>> st;
  for (int i = 0; i < n - 1; i++) {
    vector<pair<long long, int>> new_st;
    for (auto [u, s] : st) {
      auto val = __gcd(u, b[i]);
      if (new_st.empty() || new_st.back().first != val) {
        new_st.push_back({val, s});
      }
    }
    if (new_st.empty() || new_st.back().first != b[i]) {
      new_st.push_back({b[i], i});
    }
    st.swap(new_st);
    int cur = 0;
    while (cur < st.size() && st[cur].first == 1) cur++;
    if (cur < st.size()) {
      res = max(res, i - st[cur].second + 2);
    }
  }
  cout << res << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int tc;
  cin >> tc;
  for (int test = 1; test <= tc; ++test) solve(test);
  return 0;
}