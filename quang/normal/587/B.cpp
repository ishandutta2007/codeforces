#include <bits/stdc++.h>

using namespace std;

const int N = 1000010, MOD = 1000000007;

int n, k;
long long l;
int a[N];
long long dp[2][N];
vector <int> val;

long long qplus(long long u, long long v) {
  u += v;
  if (u >= MOD) {
    u -= MOD;
  }
  return u;
}

struct bit {
  long long t[N];

  void init() {
    for (int i = 0; i <= n; i++) {
      t[i] = 0;
    }
  }

  void add(int x, long long u) {
    while (x <= n) {
      t[x] = qplus(t[x], u);
      x += (x & -x);
    }
  }

  long long get(int x) {
    long long res = 0;
    while (x) {
      res = qplus(res, t[x]);
      x -= (x & -x);
    }
    return res;
  }
} t;

int main() {
  cin >> n >> l >> k;
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
    val.push_back(a[i]);
  }
  sort(val.begin(), val.end());
  long long x = l / n;
  long long y = l % n;
  long long res = l % MOD;
  for (int i = 1; i <= n; i++) {
    dp[0][i] = 1;
  }
  int cur = 0, next;
  for (int i = 2; i <= k; i++) {
    next = cur ^ 1;
    t.init();
    for (int j = 1; j <= n; j++) {
      int pos = lower_bound(val.begin(), val.end(), a[j]) - val.begin() + 1;
      t.add(pos, dp[cur][j]);
    }
    for (int j = 1; j <= n; j++) {
      int pos = lower_bound(val.begin(), val.end(), a[j]) - val.begin() + 1;
      long long foo = t.get(pos);
      dp[next][j] = foo;
      long long pool = x + (j <= y);
      pool = (pool - i + 1) % MOD;
      if (pool < 0) {
        continue;
      }
      res = (res + pool * foo) % MOD;
    }
    cur ^= 1;
  }
  cout << res << endl;
  return 0;
}