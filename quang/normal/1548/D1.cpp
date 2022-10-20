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

int n;
int cnt[4];

long long c3(int n) {
  return 1ll * n * (n - 1) * (n - 2) / 6;
}

long long c2(int n) {
  return 1ll * n * (n - 1) / 2;
}

bool Get(int u1, int u2, int v1, int v2) {
  return (u1 | v2) ^ (u2 | v1) ^ ((u1 == v1) != (u2 == v2));
}

bool Check(int u, int v, int t) {
  // if (u == 0 && v == 0 && t == 2) {
    
  auto [u1, u2] = make_pair(u >> 1 & 1, u & 1);
  auto [v1, v2] = make_pair(v >> 1 & 1, v & 1);
  auto [t1, t2] = make_pair(t >> 1 & 1, t & 1);
  // debug(u1, u2);
  // debug(v1, v2);
  // debug(t1, t2);
  int res = 0;
  res ^= Get(u1, u2, v1, v2);
  // debug(Get(u1, u2, v1, v2));
  res ^= Get(v1, v2, t1, t2);
  // debug(Get(t1, t2, v1, v2));
  res ^= Get(t1, t2, u1, u2);
  // debug(Get(u1, u2, t1, t2));
  return res == 0;
  // }
}

int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    x /= 2;
    y /= 2;
    int id = (x % 2) << 1 | (y % 2);
    cnt[id]++;
  }
  long long res = 0;
  for (int i = 0; i < 4; i++) {
    for (int j = i; j < 4; j++) {
      for (int k = j; k < 4; k++) {
        if (Check(i, j, k)) {
          if (i == j && j == k) {
            res += c3(cnt[i]);
          } else if (i == j) {
            res += c2(cnt[i]) * cnt[k];
          } else if (j == k) {
            res += c2(cnt[j]) * cnt[i];
          } else {
            res += 1ll * cnt[i] * cnt[j] * cnt[k];
          }
        }
      }
    }
  }
  cout << res << endl;
  return 0;
}