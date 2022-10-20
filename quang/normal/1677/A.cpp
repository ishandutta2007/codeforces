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
  vector<int> p(n), pos(n);
  for (auto &u : p) {
    cin >> u;
    u--;
  }
  for (int i = 0; i < n; i++) {
    pos[p[i]] = i;
  }

  debug(pos);
  long long res = 0;
  for (int i = 0; i < n; i++) {
    vector<int> pref(n + 1, 0);
    for (int j = 0; j < i; j++) {
      pref[pos[j] + 1]++;
    }
    for (int j = 1; j <= n; j++) {
      pref[j] += pref[j - 1];
    } 
    debug(i, pref);
    int less = 0;
    for (int j = 0; j < n; j++) {
      if (i == j) continue;
      if (pos[i] > pos[j]) {
        less++;
      } else {
        int num = pref[n] - pref[pos[j] + 1];
        debug(i, j, less, num);
        res += 1ll * num * less;
      }
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