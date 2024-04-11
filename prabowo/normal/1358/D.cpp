#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int n;
long long x;
int d[N*2];

// x + (x-1) + (x-2) + ...
long long arith(int x, int y) {
  return 1LL * (x + (x-y+1)) * y / 2;
}

int solve() {
  scanf("%d %lld", &n, &x);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &d[i]);
    d[i+n] = d[i];
  }

  long long sum = 0;
  long long cnt = 0;
  long long ans = 0;
  int j = n;
  while (j > 0 && cnt + d[j-1] <= x) {
    --j;
    sum += arith(d[j], d[j]);
    cnt += d[j];
  }
  for (int i = n; i < n*2; ++i) {
    cnt += d[i];
    sum += arith(d[i], d[i]);
    while (cnt > x) {
      sum -= arith(d[j], d[j]);
      cnt -= d[j];
      ++j;
    }

    // cerr << i << " " << j << " " << d[j-1] << " " << x-cnt << " " << arith(d[j-1], x-cnt) << " " << sum << endl;
    ans = max(ans, sum + arith(d[j-1], x - cnt));
    // cerr << ans << endl;
  }

  printf("%lld\n", ans);
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