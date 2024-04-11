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

const int N = 210;
const int MOD = (int)1e9 + 7;

inline int add(int u, int v, int mod = MOD) {
  return (u += v) >= mod ? u - mod : u;
}
inline int sub(int u, int v, int mod = MOD) {
  return (u -= v) < 0 ? u + mod : u;
}
inline int mul(int u, int v, int mod = MOD) { return (long long)u * v % mod; }
inline int power(int u, int v, int mod = MOD) {
  int res = 1;
  for (; v; v >>= 1, u = mul(u, u, mod))
    if (v & 1) res = mul(res, u, mod);
  return res;
}
inline int inv(int u, int mod = MOD) { return power(u, mod - 2, mod); }
inline void add_to(int &u, int v, int mod = MOD) { u = add(u, v, mod); }
inline void sub_to(int &u, int v, int mod = MOD) { u = sub(u, v, mod); }
inline void mul_to(int &u, int v, int mod = MOD) { u = mul(u, v, mod); }

const int INV2 = inv(2);

int n;
vector<int> adj[N];
int dp[N][N];
int d[N];
vector<int> ls[N];

void Unite(vector<int> &x, vector<int> &y, int &res, int w) {
  for (int u : x) {
    for (int v : y) {
      int du = d[u] - d[w];
      int dv = d[v] - d[w];
      // debug(u, v, du, dv);
      if (u > v) {
        add_to(res, dp[dv][du]);
      } else {
        add_to(res, dp[du][dv]);
      }
      // debug(res);
    } 
  }
  for (int v : y) x.push_back(v);
  y.clear();
}

int Dfs(int u, int p, int cur) {
  ls[u].push_back(u);
  d[u] = cur;
  int res = 0;
  for (int v : adj[u]) {
    if (v == p) continue;
    add_to(res, Dfs(v, u, cur + 1));
    Unite(ls[u], ls[v], res, u);
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  cin >> n;
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  for (int i = 1; i <= n; i++) {
    dp[i][0] = 1;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      dp[i][j] = mul(INV2, add(dp[i][j - 1], dp[i - 1][j]));
    }
  }
  int res = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      ls[j].clear();
    }
    // debug(i);
    add_to(res, Dfs(i, 0, 0));
  }
  cout << mul(res, inv(n)) << '\n';
  return 0;
}