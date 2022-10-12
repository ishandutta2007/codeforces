#include <bits/stdc++.h>
using namespace std;
 
const int N = 55;
const int M = 100005;
const int MOD = 998244353;

int n, m;
int l[N], r[N];

bool prime[M];
int mobius[M];
void sieve() {
  for (int i = 1; i < M; ++i) mobius[i] = 1;
  for (int i = 2; i < M; ++i) prime[i] = true;
  for (int i = 2; i < M; ++i) {
    if (!prime[i]) {
      continue;
    }
    for (int j = i; j < M; j += i) {
      int e = 0;
      int t = j;
      do {
        t /= i;
        ++e;
      } while (t % i == 0);

      if (e > 1) mobius[j] = 0;
      else mobius[j] *= -1;
      prime[j] = false;
    }
  }
}

int dp(int d) {
  int sz = m/d + 1;
  vector<int> res(sz, 0);
  res[0] = 1;

  for (int i = 0; i < n; ++i) {
    int ll = (l[i] + d - 1) / d;
    int rr = r[i] / d;
    // cerr << d << " " << i << " " << ll << " " << rr << endl;
    vector<int> nres(sz, 0);
    
    for (int j = 1; j < sz; ++j) {
      res[j] = (res[j - 1] + res[j]) % MOD;
    }

    for (int j = 0; j < sz; ++j) {
      nres[j] = (j - ll < 0 ? 0 : res[j - ll]) - (j - rr - 1 < 0 ? 0 : res[j - rr - 1]);
      if (nres[j] < 0) nres[j] += MOD;
    }

    res = nres;
  }

  int ret = 0;
  for (int r : res) ret = (ret + r) % MOD;
  return ret;
}

int solve() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; ++i) {
    scanf("%d %d", &l[i], &r[i]);
  }

  sieve();

  int ans = 0;
  for (int d = 1; d <= m; ++d) {
    // cerr << d << " " << mobius[d] << endl;
    if (mobius[d] == 0) continue;
    if (mobius[d] == 1) ans = (ans + dp(d)) % MOD;
    else ans = (ans - dp(d) + MOD) % MOD;
  }

  printf("%d\n", ans);
  return 0;
}

int main() {
  int t = 1;
  // scanf("%d", &t);
  for (int tc = 0; tc < t; ++tc) {
    // printf("Case #%d: ", tc+1);
    solve();
  }
  return 0;
}