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
  int n, k;
  cin >> n >> k;
  vector<vector<int>> adj(n);
  for (int i = 0; i + 1 < n; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  vector<int> ls;

  function<int(int, int)> Dfs = [&](int u, int p) {
    vector<int> chains;
    for (auto v : adj[u]) {
      if (v == p) {
        continue;
      }
      chains.push_back(Dfs(v, u));
    }
    sort(chains.begin(), chains.end());
    if (chains.empty()) {
      return 1;
    }
    for (int i = 0; i + 1 < chains.size(); i++) {
      ls.push_back(chains[i]);
    }
    return chains.back() + 1;
  };

  ls.push_back(Dfs(0, -1));
  sort(ls.begin(), ls.end());
  reverse(ls.begin(), ls.end());
  while (ls.size() <= n) ls.push_back(0);
  long long res = -1ll * (n - n / 2) * (n / 2);
  int tot = n;
  for (int i = 0; i < k; i++) {
    tot -= ls[i];
    int b = min(tot, n / 2);
    res = max(res, 1ll * (n - b - (i + 1)) * (i + 1 - b));
    debug(i, tot, 1ll * (n - b - (i + 1)) * (i + 1 - b));
  }
  cout << res << '\n';
  return 0;
}