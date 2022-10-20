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
  for (auto &u : a) {
    cin >> u;
  }
  int x;
  cin >> x;
  vector<long long> sum(n + 1, 0);
  for (int i = 0; i < n; i++) {
    sum[i + 1] = sum[i] + a[i];
  }
  vector<long long> val(n + 1, 0);
  for (int i = 0; i <= n; i++) {
    val[i] = sum[i] - 1ll * x * i;
  }
  debug(val);

  vector<pair<int, int>> f(n + 1, {0, 0});
  for (int i = 1; i <= n; i++) {
    f[i].first = max(f[i - 1].first, f[i - 1].second);
    if (i == 1) {
      f[i].second = 1;
    } else {
      f[i].second = max(f[i - 2].first, f[i - 2].second) + 1;
    }
    if (i >= 2 && val[i] >= val[i - 2]) {
      f[i].second = max(f[i].second, f[i - 2].first + 2);
      if (i >= 3 && val[i] >= val[i - 3] && val[i - 1] >= val[i - 3]) {
        f[i].second = max(f[i].second, f[i - 3].first + 3);
        if (i >= 4 && val[i - 1] >= val[i - 4]) {
          f[i].second = max(f[i].second, f[i - 2].second + 2);
        }
      }
    }
  }
  debug(f);
  cout << max(f.back().first, f.back().second) << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int tc;
  cin >> tc;
  for (int test = 1; test <= tc; ++test) Solve(test);
  return 0;
}