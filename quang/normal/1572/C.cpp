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
  vector<vector<int>> ls(n, vector<int>());
  vector<int> pos(n);
  for (int i = 0; i < n; i++) {
    int u;
    cin >> u;
    u--;
    a[i] = u;
    pos[i] = ls[u].size();
    ls[u].push_back(i);
  }
  vector<vector<int>> dp(n, vector<int>(n, 0));
  for (int r = 0; r < n; r++) {
    for (int l = r - 1; l >= 0; l--) {
      dp[l][r] = max(dp[l + 1][r], dp[l][r - 1]);
      int id = pos[r];
      for (int i = id - 1; i >= 0; i--) {
        int p = ls[a[r]][i];
        if (p < l) break;
        if (l == 0 && r + 1 == n) {
          debug(l, r, p);
          debug(dp[l][p], dp[p][r]);
        }
        dp[l][r] = max(dp[l][r], dp[l][p] + dp[p][r]);
      }
      id = pos[l];
      for (int i = id + 1; i < ls[a[l]].size(); i++) {
        int p = ls[a[l]][i];
        if (p > r) break;
        dp[l][r] = max(dp[l][r], dp[l][p] + dp[p][r]);
      }
      if (a[l] == a[r]) {
        dp[l][r] = max(dp[l][r], 1 + (l + 1 < r ? dp[l + 1][r - 1] : 0));
      }
    }
  }
  cout << n - 1 - dp[0][n - 1] << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int tc;
  cin >> tc;
  for (int test = 1; test <= tc; ++test) Solve(test);
  return 0;
}