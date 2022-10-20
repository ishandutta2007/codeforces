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
  vector<vector<int>> prev(n, vector<int>());
  vector<vector<int>> nxt(n, vector<int>());
  vector<int> deg(n);
  for (int i = 0; i < n; i++) {
    int sz;
    cin >> sz;
    deg[i] = sz;
    prev[i].resize(sz);
    for (auto &u : prev[i]) {
      cin >> u;
      u--;
      nxt[u].push_back(i);
    }
  }
  vector<int> dp(n, -1);
  queue<int> q;
  for (int i = 0; i < n; i++) {
    if (prev[i].empty()) {
      q.push(i);
      dp[i] = 0;
    }
  }
  int res = 0;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int v : prev[u]) {
      if (u > v) dp[u] = max(dp[u], dp[v]);
      else dp[u] = max(dp[u], dp[v] + 1);
    }
    for (int v : nxt[u]) {
      deg[v]--;
      if (!deg[v]) q.push(v);
    }
    debug(u, dp[u]);
    res = max(res, dp[u]);
  }
  for (int i = 0; i < n; i++) {
    if (dp[i] == -1) {
      cout << -1 << '\n';
      return;
    }
  }
  cout << res + 1 << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int tc;
  cin >> tc;
  for (int test = 1; test <= tc; ++test) Solve(test);
  return 0;
}