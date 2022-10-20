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

const int N = 1000010;

bool p[N];

void Solve(int test) {
  int n, e;
  cin >> n >> e;
  vector<int> a(n);
  for (auto &u : a) {
    cin >> u;
  }
  long long res = 0;
  for (int i = 0; i < n; i++) {
    if (p[a[i]]) continue;
    int r = 1;
    int cur = i;
    while (cur + e < n && a[cur + e] == 1) {
      r++;
      cur += e;
    }
    int l = 1;
    cur = i;
    while (cur - e >= 0 && a[cur - e] == 1) {
      l++;
      cur -= e;
    }
    res += 1ll * l * r - 1;
  }
  cout << res << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0);

  p[1] = 1;
  for (int i = 2; i < N; i++) {
    if (!p[i]) {
      for (int j = i + i; j < N; j += i) {
        p[j] = 1;
      }
    }
  }

  int tc;
  cin >> tc;
  for (int test = 1; test <= tc; ++test) Solve(test);
  return 0;
}