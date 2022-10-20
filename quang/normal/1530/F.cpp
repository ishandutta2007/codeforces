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

const int MOD = 31607;
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
inline int add_to(int &u, int v, int mod = MOD) { return u = add(u, v, mod); }
inline int sub_to(int &u, int v, int mod = MOD) { return u = sub(u, v, mod); }
inline int mul_to(int &u, int v, int mod = MOD) { return u = mul(u, v, mod); }

const int N = 21;
const int DENOM = 10000;
const int INV_DENOM = inv(DENOM);

int n;
int a[N][N];
int b[N][N];
int row[N]; // prob row #i win
int col[N];
int p[N][1 << N];
int win[1 << N];
int num_bit[1 << N];
int first_bit[1 << N];
int all;

int Solve(int type) {
  int res = 0;
  if (type == 2) {
    int all_lose = 1;
    for (int i = 0; i < n; i++) {
      row[i] = 1;
      for (int j = 0; j < n; j++) {
        mul_to(row[i], a[i][j]);
      }
      mul_to(all_lose, sub(1, row[i]));
    }
    add_to(res, sub(1, all_lose));

    all_lose = 1;
    for (int j = 0; j < n; j++) {
      col[j] = 1;
      for (int i = 0; i < n; i++) {
        mul_to(col[j], a[i][j]);
      }
      mul_to(all_lose, sub(1, col[j]));
    }
    add_to(res, sub(1, all_lose));

    for (int mask = 1; mask < (1 << n); mask++) {
      win[mask] = mul(win[mask ^ (1 << first_bit[mask])], col[first_bit[mask]]);
      for (int i = 0; i < n; i++) {
        p[i][mask] = mul(p[i][mask ^ (1 << first_bit[mask])], a[i][first_bit[mask]]);
      }
    } 

    int now = 0;
    for (int mask = 1; mask < (1 << n); mask++) {
      int all_lose_mask = 1;
      for (int i = 0; i < n; i++) {
        mul_to(all_lose_mask, sub(1, p[i][all ^ mask]));
      }
      auto foo = mul(win[mask], sub(1, all_lose_mask));
      if (num_bit[mask] % 2) add_to(now, foo);
      else sub_to(now, foo);
    }

    sub_to(res, now);
    return res;
  }
  if (type == 3) {
    add_to(res, Solve(2));
    int dia = 1;
    for (int i = 0; i < n; i++) {
      mul_to(dia, a[i][i]);
    }
    add_to(res, dia);
    
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) b[i][j] = a[i][j];

    int now = 1;
    for (int i = 0; i < n; i++) {
      mul_to(now, a[i][i]);
      a[i][i] = 1;
    }

    mul_to(now, Solve(2));

    sub_to(res, now);

    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) a[i][j] = b[i][j];

    return res;
  }
  if (type == 4) {
    add_to(res, Solve(3));
    int anti = 1;
    for (int i = 0; i < n; i++) {
      mul_to(anti, a[i][n - i - 1]);
    }
    add_to(res, anti);

    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) b[i][j] = a[i][j];

    int now = 1;
    for (int i = 0; i < n; i++) {
      mul_to(now, a[i][n - i - 1]);
      a[i][n - i - 1] = 1;
    }

    sub_to(res, mul(now, Solve(3)));

    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) a[i][j] = b[i][j];
    
    return res; 
  }
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  cin >> n;

  all = (1 << n) - 1;

  num_bit[0] = 0;
  first_bit[0] = -1;
  for (int mask = 1; mask < (1 << n); mask++) {
    num_bit[mask] = num_bit[mask >> 1] + (mask & 1);
    if (mask & 1) first_bit[mask] = 0;
    else first_bit[mask] = first_bit[mask >> 1] + 1;
  }

  win[0] = 1;
  for (int i = 0; i < n; i++) {
    p[i][0] = 1;
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
      mul_to(a[i][j], INV_DENOM);
    }
  }
  cout << Solve(4) << '\n';
  return 0;
}