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
  vector<vector<int>> a(n, vector<int>(n));
  for (auto &row : a) {
    for (auto &u : row) {
      cin >> u;
    }
  }
  int res = 0;

  auto IsInside = [&](int u, int v) {
    return u >= 0 && u < n && v >= 0 && v < n;
  };

  auto Get = [&](vector<vector<int>> &A, int u, int v) {
    if (!IsInside(u, v)) return 0;
    return A[u][v];
  };

  for (int it = 0; it < 2; it++) {
    vector<vector<int>> val(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
      int cur = 0;
      for (int j = 0; j <= i; j++) {
        if (j == 0) {
          cur = Get(a, i, i);
        } else {
          cur ^= Get(a, i - j, i + j) ^ Get(a, i + j, i - j);
        }
        if (IsInside(i - j, i + j + 1)) {
          val[i - j][i + j + 1] = cur ^ Get(val, i - j - 1, i + j);
        }
      }
    }

    for (auto & row : val) {
      debug(row);
    }

    for (auto &row : val) {
      for (auto &u : row) {
        res ^= u;
      }
    }

    for (auto &row : a) {
      reverse(row.begin(), row.end());
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