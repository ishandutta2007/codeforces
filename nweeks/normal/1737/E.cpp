#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MOD = 1e9 + 7;

int modpow(int a, int b) {
  int ret = 1;
  for (; b; b /= 2, a = a * a % MOD)
    if (b % 2)
      ret = ret * a % MOD;
  return ret;
}

int inv(int x) { return modpow(x, MOD - 2); }

struct Fenwick {
  vector<int> s;
  Fenwick(int n) : s(n) {}

  void update(int pos, int diff) {
    for (; pos < (int)s.size(); pos |= pos + 1) {
      s[pos] += diff;
      if (s[pos] >= MOD)
        s[pos] -= MOD;
    }
  }

  int query(int r) { // < r
    int res = 0;
    for (; r > 0; r &= r - 1) {
      res += s[r - 1];
      if (res >= MOD)
        res -= MOD;
    }
    return res;
  }
};

void solve() {
  int n;
  cin >> n;

  Fenwick f(n + 1), pow2(n);
  int cur = 1;
  for (int i = 0; i < n; ++i) {
    pow2.update(i, cur);
    cur = 2 * cur;
    if (cur >= MOD)
      cur -= MOD;
  }

  f.update(n, 1);
  for (int i = n - 1; i; --i) {
    if (n - i < i)
      f.update(i, 1);
    int lo = i + 1;
    int up = i + min(n - i, i - 1);
    if (lo > up)
      continue;
    int toAdd = f.query(up + 1) - f.query(lo);
    if (toAdd < 0)
      toAdd += MOD;
    f.update(i, toAdd);
  }

  vector<int> nbFacons(n + 1);
  for (int i = 1; i <= n; ++i) {
    int lo2 = (i + 1) / 2 - 1;
    int up2 = i - 1;
    int lo = i - up2 - 2, up = i - lo2 - 2;

    int p2 = 0;
    if (lo < 0) {
      p2 += min(-lo, up + 1 - lo);
      lo = min(0LL, up + 1);
    }
    if (lo <= up) {
      p2 += pow2.query(up + 1) - pow2.query(lo);
      if (p2 < 0)
        p2 += MOD;
    }

    int fi = f.query(i + 1) - f.query(i);
    if (fi < 0)
      fi += MOD;
    nbFacons[i] = fi * p2 % MOD;
  }
  for (int a = 0; a < n; ++a)
    if (n - a - 1 <= a + 1) {
      int x = max(0LL, n - a - 2);
      nbFacons[n] += modpow(2, x);
      if (nbFacons[n] >= MOD)
        nbFacons[n] -= MOD;
    }

  int inv2 = inv(modpow(2, n));
  for (int i = 1; i <= n; ++i)
    cout << nbFacons[i] * inv2 % MOD << '\n';
}

signed main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int nbTests;
  cin >> nbTests;
  for (int iTest(0); iTest < nbTests; ++iTest)
    solve();
}