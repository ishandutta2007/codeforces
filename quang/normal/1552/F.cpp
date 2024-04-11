#include <bits/stdc++.h>

using namespace std;

const int MOD = 998244353;
inline int add(int u, int v, int m = MOD) { return (u += v) >= m ? u - m : u; }
inline int sub(int u, int v, int m = MOD) { return (u -= v) < 0 ? u + m : u; }
inline int mul(int u, int v, int m = MOD) { return (long long)u * v % m; }
inline int power(int u, int v, int m = MOD) {
  int res = 1;
  for (; v; v >>= 1, u = mul(u, u, m)) if (v & 1) res = mul(res, u, m);
  return res;
}
inline int neg(int u, int m = MOD) { return sub(0, u); }
inline int inv(int u, int m = MOD) { return power(u, m - 2, m); }
inline int add_to(int &u, int v, int m = MOD) { return u = add(u, v, m); }
inline int sub_to(int &u, int v, int m = MOD) { return u = sub(u, v, m); }
inline int mul_to(int &u, int v, int m = MOD) { return u = mul(u, v, m); }

const int N = 200010;

int n;
int x[N], y[N], s[N];
int dp[N];
int sum_dp[N];

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> x[i] >> y[i] >> s[i];
  }
  int res = add(x[n] % MOD, 1);
  for (int i = 1; i <= n; i++) {
    dp[i] = sub(x[i] % MOD, y[i] % MOD);
    int id = upper_bound(x + 1, x + n + 1, y[i]) - x;
    add_to(dp[i], sub(sum_dp[i - 1], sum_dp[id - 1]));
    sum_dp[i] = add(sum_dp[i - 1], dp[i]);
    if (s[i]) add_to(res, dp[i]);
  }
  cout << res << '\n';
  return 0;
}