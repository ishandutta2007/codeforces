#include <bits/stdc++.h>

using namespace std;

const int MOD = 998244353;

inline int add(int u, int v, int mod = MOD) {return (u += v) >= mod ? u - mod : u;}
inline int sub(int u, int v, int mod = MOD) {return (u -= v) < 0 ? u + mod : u;}
inline int mul(int u, int v, int mod = MOD) {return (long long)u * v % mod;}
inline int power(int u, int v, int mod = MOD) {int res = 1;for (; v; v >>= 1, u = mul(u, u, mod)) if (v & 1) res = mul(res, u, mod); return res;}
inline int inv(int u, int mod = MOD) {return power(u, mod - 2, mod);}
inline void add_to(int &u, int v, int mod = MOD) {u = add(u, v, mod);}
inline void sub_to(int &u, int v, int mod = MOD) {u = sub(u, v, mod);}
inline void mul_to(int &u, int v, int mod = MOD) {u = mul(u, v, mod);}

const int N = 1000010;
const int INV2 = inv(2);

int n;
int dp[2][N];
int sum[2][N];

int cn2(int n) {
  return mul(mul(n, sub(n, 1)), INV2);
}

int cn3(int n) {
  return mul(mul(n, sub(n, 1)), mul(sub(n, 2), inv(6)));
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  cin >> n;
  dp[0][0] = dp[1][0] = 1;
  sum[0][0] = sum[1][0] = 1;
  for (int i = 1; i <= n; i++) {
    dp[0][i] = mul(dp[1][i - 1], sum[1][i - 1]);
    sub_to(dp[0][i], cn2(dp[1][i - 1]));
    dp[1][i] = add(dp[1][i - 1], dp[0][i]);

    sum[0][i] = add(sum[0][i - 1], dp[0][i]);
    sum[1][i] = add(sum[1][i - 1], dp[1][i]);
  }

  int res = mul(2, dp[0][n]);
  for (int i = 0; i < n; i++) {
    int need = n - i - 1;
    add_to(res, mul(dp[0][i], sum[0][need]));
  }
  int foo = cn3(add(sum[1][n - 1], 2));
  if (n > 1) sub_to(foo, cn3(add(sum[1][n - 2], 2)));
  add_to(res, mul(foo, 2));
  cout << res << endl;
  return 0;
}