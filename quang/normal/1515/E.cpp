#include <bits/stdc++.h>

using namespace std;

int MOD;

inline int add(int u, int v, int mod = MOD) {return (u += v) >= mod ? u - mod : u;}
inline int sub(int u, int v, int mod = MOD) {return (u -= v) < 0 ? u + mod : u;}
inline int mul(int u, int v, int mod = MOD) {return (long long)u * v % mod;}
inline int power(int u, int v, int mod = MOD) {int res = 1;for (; v; v >>= 1, u = mul(u, u, mod)) if (v & 1) res = mul(res, u, mod); return res;}
inline int inv(int u, int mod = MOD) {return power(u, mod - 2, mod);}
inline void add_to(int &u, int v, int mod = MOD) {u = add(u, v, mod);}
inline void sub_to(int &u, int v, int mod = MOD) {u = sub(u, v, mod);}
inline void mul_to(int &u, int v, int mod = MOD) {u = mul(u, v, mod);}

const int N = 410;

int n;
int c[N][N];
int dp[N][N];
int ways[N];

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  cin >> n >> MOD;
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= i; j++) {
      if (j == 0 || j == i) c[i][j] = 1;
      else {
        c[i][j] = add(c[i - 1][j], c[i - 1][j - 1]);
      }
    }
  }

  ways[0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= i; j++) {
      add_to(ways[i], c[i - 1][j - 1]);
    }
  }

  // for (int i = 1; i <= n; i++) {
  //   cout << ways[i] << endl;
  // }

  dp[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    dp[i][0] = ways[i];
    for (int j = 1; j <= i; j++) {
      for (int k = 2; k <= i - 1; k++) {
        int mult = 1;
        mul_to(mult, c[i - j][i - k]);
        mul_to(mult, ways[i - k]);
        add_to(dp[i][j], mul(dp[k - 1][j - 1], mult));
      }
      // cout << "# " << i << ' ' << j << ' ' << dp[i][j] << endl;
    }
  }
  int res = 0;
  for (int i = 0; i <= n; i++) {
    add_to(res, dp[n][i]);
  }
  cout << res << '\n';
  return 0;
}