#include <bits/stdc++.h>

using namespace std;

const int MOD = (int)1e9 + 7;
inline int add(int u, int v, int mod = MOD) {return (u += v) >= mod ? u - mod : u;}
inline int sub(int u, int v, int mod = MOD) {return (u -= v) < 0 ? u + mod : u;}
inline int mul(int u, int v, int mod = MOD) {return (long long)u * v % mod;}
inline int power(int u, int v, int mod = MOD) {int res = 1;for (; v; v >>= 1, u = mul(u, u, mod)) if (v & 1) res = mul(res, u, mod); return res;}
inline int inv(int u, int mod = MOD) {return power(u, mod - 2, mod);}
inline void add_to(int &u, int v, int mod = MOD) {u = add(u, v, mod);}
inline void sub_to(int &u, int v, int mod = MOD) {u = sub(u, v, mod);}
inline void mul_to(int &u, int v, int mod = MOD) {u = mul(u, v, mod);}

const int N = 200010;

int fac[N];
int inv_fac[N];

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

  auto nAk = [&](int n, int k) {
    if (k < 0 || k > n) return 0;
    return mul(fac[n], inv_fac[n - k]);
  };

  int tc;
  cin >> tc;
  while (tc--) {
    int n, k;
    cin >> n >> k;
    vector<int> dp(n + 2, 0);
    for (int i = 1; i <= n && n >= (k - 1) * (i - 1); i++) {
      dp[i] = nAk(n - (k - 1) * (i - 1), i);
    }
    int res = 0;
    int cur_prob = 1;
    for (int i = 1; i < n; i++) {
      int cur = mul(dp[i], n - i);
      int nxt = dp[i + 1];
      int now = sub(cur, nxt);
      add_to(res, mul(i + 1, mul(cur_prob, mul(now, inv(cur)))));
      mul_to(cur_prob, mul(nxt, inv(cur)));
    }
    // cout << mul(sum_w, inv(sum)) << '\n';
    cout << res << '\n';
  }
  return 0;
}