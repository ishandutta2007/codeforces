#include <bits/stdc++.h>
using namespace std;

int n, k;

long long construct(int sum, bool ex) {
  if (sum == 0) return 0LL;

  vector<int> digs;

  if (ex) {
    int d = min(sum, 8);
    sum -= d;
    digs.push_back(d);
  }

  while (sum > 0) {
    if (sum >= 9) {
      digs.push_back(9);
      sum -= 9;
    } else {
      digs.push_back(sum);
      sum = 0;
    }
  }

  reverse(digs.begin(), digs.end());
  long long ret = 0;
  for (int u: digs) {
    ret = ret * 10 + u;
  }
  return ret;
}

int solve() {
  scanf("%d %d", &n, &k);

  long long ans = -1;
  for (int st = 0; st <= 9; ++st) {
    int extra = 0;
    int ones = 0;
    for (int j = 0; j <= k; ++j) {
      ones += (st + j) % 10;
      if (st + j >= 10) ++extra;
    }

    // X * (k+1) + extra + ones = n
    if (extra + ones > n) continue;
    if ((n - ones - extra) % (k+1) == 0) {
      long long tmp = construct((n - ones - extra) / (k+1), extra > 0);
      // cerr << (n - ones - extra) / (k+1) << " " << tmp << endl;
      tmp = tmp * 10 + st;
      if (ans == -1 || tmp < ans) ans = tmp;
    }
  }

  printf("%lld\n", ans);
  return 0;
}

int main() {
  int t = 1;
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}