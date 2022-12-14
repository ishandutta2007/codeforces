#include <bits/stdc++.h>

using namespace std;

int MOD;
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

const int N = 4000010;

int dp[N];
int sum_dp[N];

int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n >> MOD;
  dp[n] = 1;
  for (int i = n; i; i--) {
    add_to(dp[i], sum_dp[i + 1]);
    for (int j = 2; i * j <= n; j++) {
      int r = (i + 1) * j - 1;
      r = min(r, n);
      add_to(dp[i], sum_dp[i * j]);
      sub_to(dp[i], sum_dp[r + 1]);
    }

    sum_dp[i] = add(sum_dp[i + 1], dp[i]);
  }
  cout << dp[1] << '\n';
  return 0;
}