#include <bits/stdc++.h>

using namespace std;

const int N = 1000010, MOD = 1000000007, magic = 500000004;

int n;
int a[N], f[N], dp[N];

inline int mul(int u, int v) {
  return (long long) u * v % MOD;
}

inline int add(int u, int v) {
  u += v;
  if (u >= MOD) {
    u -= MOD;
  }
  return u;
}

struct bit {
  int t[N];

  void add(int x, int v) {
    while (x < N) {
      t[x] += v;
      x += (x & -x);
    }
  }

  int get(int x) {
    int res= 0 ;
    while (x) {
      res += t[x];
      x -= (x & -x);
    }
    return res;
  }
} t;

int main() {
  cin >> n;
  f[0] = 1;
  dp[0] = 0;
  for (int i = 1; i <= n; i++) {
    int foo = mul(i - 1, i);
    foo = mul(foo, magic);
    foo = mul(foo, f[i - 1]);
    dp[i] = add(mul(dp[i - 1], i), foo);
    f[i] = mul(f[i - 1], i);
  }
  int res = 0, cur = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
    int pos = a[i] - t.get(a[i]) - 1;
    res = add(res, mul(mul(pos, f[n - i]), cur));
    cur = add(cur, pos);
    res = add(res, mul(dp[n - i], pos));
    res = add(res, mul(mul(magic, mul(pos - 1, pos)), f[n - i]));
    t.add(a[i], 1);
  }
  res = add(res, cur);
  cout << res << endl;
  return 0;
}