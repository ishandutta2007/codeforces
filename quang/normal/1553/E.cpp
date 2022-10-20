#include <bits/stdc++.h>

using namespace std;

// source: tourist
template <typename A, typename B>
string to_string(pair<A, B> p);
 
string to_string(const string& s) {
  return '"' + s + '"';
}
 
string to_string(const char* s) {
  return to_string((string) s);
}
 
string to_string(bool b) {
  return (b ? "true" : "false");
}
 
string to_string(vector<bool> v) {
  bool first = true;
  string res = "{";
  for (int i = 0; i < static_cast<int>(v.size()); i++) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(v[i]);
  }
  res += "}";
  return res;
}
 
template <size_t N>
string to_string(bitset<N> v) {
  string res = "";
  for (size_t i = 0; i < N; i++) {
    res += static_cast<char>('0' + v[i]);
  }
  return res;
}
 
template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
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

void solve(int test) {
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  vector<int> cnt(n, 0);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    a[i]--;
    cnt[(i + n - a[i]) % n]++;
  }
  // debug(cnt);
  vector<int> res;
  for (int i = 0; i < n; i++) {
    if (m * 2 + cnt[i] < n) continue;
    auto b = a;
    rotate(b.begin(), b.begin() + i, b.end());
    vector<bool> used(n, 0);
    int need = 0;
    for (int j = 0; j < n; j++) {
      if (used[j]) continue;
      int now = 0;
      int u = j;
      while (!used[u]) {
        now++;
        used[u] = 1;
        u = b[u];
      }
      need += now - 1;
    }
    // debug(i, need);
    if (need <= m) res.push_back(i);
  }
  cout << res.size();
  for (auto u : res) {
    cout << ' ' << u;
  }
  cout << '\n';
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int tc;
  cin >> tc;
  for (int test = 1; test <= tc; ++test) solve(test);
  return 0;
}