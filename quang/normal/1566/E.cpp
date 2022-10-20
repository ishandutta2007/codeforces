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
  vector<vector<int>> adj(n, vector<int>());
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  vector<int> h(n);

  vector<int> par(n);
  function<void(int, int)> Dfs = [&](int u, int p) {
    par[u] = p;
    for (auto v : adj[u]) {
      if (v == p) continue;
      h[v] = h[u] + 1;
      Dfs(v, u);
    }
  };

  h[0] = 0;
  Dfs(0, -1);
  vector<int> order(n, 0);
  iota(order.begin(), order.end(), 0);
  sort(order.begin(), order.end(), [&](int u, int v) {
    return h[u] > h[v];
  });
  debug(h);
  vector<bool> used(n, false);
  int res = 1;
  for (auto u : order) {
    int num_chilren = 0;
    for (auto v : adj[u]) {
      if (v == par[u]) continue;
      num_chilren += !used[v];
    }
    if (num_chilren == 0) continue;
    used[u] = true;
    debug(u, num_chilren);
    res += num_chilren - 1;
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