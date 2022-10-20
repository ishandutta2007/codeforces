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
  int n;
  cin >> n;
  vector<int> h(n);
  for (auto &u : h) {
    cin >> u;
  }
  vector<vector<int>> adj(n);
  for (int i = 0; i + 1 < n; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  int root = max_element(h.begin(), h.end()) - h.begin();

  set<int> base_list;

  function<bool(int, int, int)> DfsFindBase = [&](int u, int p, int val) {
    bool res = h[u] == val;
    for (auto v : adj[u]) {
      if (v == p) continue;
      res |= DfsFindBase(v, u, val);
    }
    if (res) base_list.insert(u);
    return res;
  };

  DfsFindBase(root, -1, h[root]);

  debug(base_list);
  
  long long res = 0;

  function<int(int, int)> Dfs = [&](int u, int p) {
    int cur = 0;
    for (auto v : adj[u]) {
      if (base_list.count(v)) {
        continue;
      }
      if (v == p) continue;
      auto val = Dfs(v, u);
      cur = max(cur, val);
      res += val; 
    }
    res -= cur;
    cur = max(cur, h[u]);
    return cur;
  };

  set<int> need;
  for (auto u : base_list) {
    int d = 0;
    for (auto v : adj[u]) {
      if (!base_list.count(v)) {
        continue;
      }
      d++;
    }
    if (d <= 1) {
      need.insert(u);
    }
  }

  if (need.size() == 1) {
    auto u = *need.begin();
    vector<int> ls;
    for (auto v : adj[u]) {
      if (!base_list.count(v)) {
        ls.push_back(Dfs(v, u));
      }
    }
    sort(ls.rbegin(), ls.rend());
    if (ls.size() < 2) {
      res += h[u] * 2;
    } else {
      res += accumulate(ls.begin(), ls.end(), 0ll);
      res += h[u] * 2 - ls[0] - ls[1];
    }
  } else {
    for (auto u : base_list) {
      int max_val = 0;
      long long sum = 0;
      int cnt = 0;
      for (auto v : adj[u]) {
        if (!base_list.count(v)) {
          auto val = Dfs(v, u);
          sum += val;
          max_val = max(max_val, val);
          cnt++;
        }
      }

      debug(u, h[u], max_val, sum, cnt);

      if (need.count(u)) {
        if (cnt == 0) {
          res += h[u];
        } else {
          res += sum;
          res += h[u] - max_val;
        }
      } else {
        res += sum;
      }
    }
  }
  cout << res << '\n';
  return 0;
}