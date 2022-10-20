#include <bits/stdc++.h>

using namespace std;

const int N = 200010;

const int MOD = 998244353;
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

int fac[N], inv_fac[N];

int binom(int n, int k) {
  if (k < 0 || k > n) return 0;
  return mul(fac[n], mul(inv_fac[n - k], inv_fac[k]));
}

void solve(int test) {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int num[2] = {0, 0};
  int last = -1;
  for (int i = 0; i < n; i++) {
    int id = s[i] - '0';
    num[id]++;
    if (!id) {
      if ((i - last) % 2 == 0) {
        num[1]--;
      }
      last = i;
    }
  }
  num[1] /= 2;
  cout << binom(num[0] + num[1], num[0]) << '\n';
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);

  fac[0] = 1;
  for (int i = 1; i < N; i++) {
    fac[i] = mul(fac[i - 1], i);
  }
  inv_fac[N - 1] = inv(fac[N - 1]);
  for (int i = N - 2; i >= 0; i--) {
    inv_fac[i] = mul(inv_fac[i + 1], i + 1);
  }

  int tc;
  cin >> tc;
  for (int test = 1; test <= tc; ++test) {
    solve(test);
  }
  return 0;
}