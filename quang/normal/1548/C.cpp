#include <bits/stdc++.h>

using namespace std;

const int N = 5000010;
const int MOD = (int)1e9 + 7;
inline int add(int u, int v, int m = MOD) { return (u += v) >= m ? u - m : u; }
inline int sub(int u, int v, int m = MOD) { return (u -= v) < 0 ? u + m : u; }
inline int mul(int u, int v, int m = MOD) { return (long long)u * v % m; }
inline int power(int u, int v, int m = MOD) {
  int res = 1;
  for (; v; v >>= 1, u = mul(u, u, m)) if (v & 1) res = mul(res, u, m);
  return res;
}
inline int neg(int u, int m = MOD) { return sub(0, u, m); }
inline int inv(int u, int m = MOD) { return power(u, m - 2, m); }
inline int add_to(int &u, int v, int m = MOD) { return u = add(u, v, m); }
inline int sub_to(int &u, int v, int m = MOD) { return u = sub(u, v, m); }
inline int mul_to(int &u, int v, int m = MOD) { return u = mul(u, v, m); }

int n, q;
int fac[N], inv_fac[N];

int Binom(int n, int k) {
  if (k < 0 || k > n) return 0;
  return mul(fac[n], mul(inv_fac[k], inv_fac[n - k]));
}

struct Polynomial {
  vector<int> a;

  Polynomial(int sz) {
    a.assign(sz, 0);
  }

  friend Polynomial operator/(const Polynomial &x_, const Polynomial &y) {
    auto x = x_;
    int n = (int)x.a.size();
    int m = (int)y.a.size();
    Polynomial res(n);
    int b = inv(y.a.back());
    for (int i = n - 1; i >= m - 1; i--) {
      int val = mul(x.a[i], b);
      res.a[i - m + 1] = val;
      for (int j = 0; j < m; j++) {
        sub_to(x.a[i - j], mul(val, y.a[m - j - 1]));
      }
    }
    return res;
  }
};

int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0);

  fac[0] = 1;
  for (int i = 1; i < N; i++) fac[i] = mul(fac[i - 1], i);
  inv_fac[N - 1] = inv(fac[N - 1]);
  for (int i = N - 2; i >= 0; i--) inv_fac[i] = mul(inv_fac[i + 1], i + 1);

  cin >> n >> q;
  Polynomial x(3 * n + 3 + 1);
  Polynomial y(4);
  for (int i = 1; i <= 3 * n + 3; i++) {
    x.a[i] = Binom(3 * n + 3, i);
  }
  for (int i = 1; i <= 3; i++) {
    y.a[i] = Binom(3, i);
  }
  Polynomial z = x / y;
  while (q--) {
    int u;
    cin >> u;
    cout << z.a[u] << '\n';
  }
  return 0;
}