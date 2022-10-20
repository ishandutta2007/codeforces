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
  vector<int> x(n);
  for (auto &u : x) {
    cin >> u;
  }
  auto y = x;
  sort(y.begin(), y.end());
  y.resize(unique(y.begin(), y.end()) - y.begin());
  for (auto &u : x) {
    u = lower_bound(y.begin(), y.end(), u) - y.begin();
  }
  map<int, int> a;
  for (int i = 0; i < n; i++) {
    a[x[i]]++;
  }
  map<int, vector<int>> list_size;
  for (auto [u, v] : a) {
    list_size[v].push_back(u);
  }
  vector<vector<int>> ls;
  vector<int> lens;
  for (auto &[len, l] : list_size) {
    lens.push_back(len);
    ls.push_back(l);
    sort(ls.back().rbegin(), ls.back().rend());
  }
  long long res = 0;
  vector<vector<int>> banned(y.size());
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u = lower_bound(y.begin(), y.end(), u) - y.begin();
    v = lower_bound(y.begin(), y.end(), v) - y.begin();
    banned[u].push_back(v);
    banned[v].push_back(u);
  }

  debug(lens);
  debug(ls);
  debug(banned);
  vector<bool> is_banned(y.size());

  auto Get = [&](int u, int len) {
    for (auto v : banned[u]) {
      is_banned[v] = 1;
    }
    long long res = 0;
    for (int i = 0; i < ls.size(); i++) {
      for (int v : ls[i]) {
        if (is_banned[v] || u == v) continue;
        debug(u, v, len, lens[i]);
        res = max(res, 1ll * (y[u] + y[v]) * (len + lens[i]));
        break;
      }
    }
    for (auto v : banned[u]) {
      is_banned[v] = 0;
    }
    debug("get", u, len, res);
    return res;
  };

  for (int i = 0; i < ls.size(); i++) {
    for (auto u : ls[i]) {
      res = max(res, Get(u, lens[i]));
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