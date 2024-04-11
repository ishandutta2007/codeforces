#include <bits/stdc++.h>

using namespace std;

const int N = 110;
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

int n;
int a[N];
int b[N];
int sum_b[N];
int sum_ib[N];

int q;
int x[N];

int f[N][N * N];

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i < n; i++) {
    cin >> b[i];
  }
  for (int i = 1; i < n; i++) {
    sum_b[i] = sum_b[i - 1] + b[i];
    sum_ib[i] = sum_ib[i - 1] + i * b[i];
  }
  cin >> q;
  for (int i = 1; i <= q; i++) {
    cin >> x[i];
  }
  f[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int prev_sum = 0; prev_sum < N * N; prev_sum++) {
      if (f[i - 1][prev_sum]) {
        for (int j = 0; j <= a[i]; j++) {
          int sum = prev_sum + j;
          int now = sum - sum_b[i - 1] * i + sum_ib[i - 1];
          if (now >= x[1] * i) {
            add_to(f[i][sum], f[i - 1][prev_sum]);
          }
        }
      }
    }
  }
  int res = 0;
  for (int i = 0; i < N * N; i++) {
    add_to(res, f[n][i]);
  }
  cout << res << '\n';
  return 0;
}