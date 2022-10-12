#include <bits/stdc++.h>
using namespace std;

int h, c, t;


// hk + h + ck = 2tk + t
// k(h + c - 2t) = t - h
// k = (h - t) / (2t - h - c)

// abs([h(k+1) + ck)] / 2k - t)

int solve() {
  scanf("%d %d %d", &h, &c, &t);
  
  if (t >= h) {
    return 0 * printf("1\n");
  } else if (t*2 <= (h+c)) {
    return 0 * printf("2\n");
  } else {
    int k = (h - t) / (t*2 - h - c);
    // 1LL*(k+1)*h + 1LL*k*c / (k*2 + 1) - t

    long long p = abs(1LL*(k+1)*h + 1LL*k*c - (2LL*k + 1) * t);
    long long q = abs(1LL*(k+2)*h + 1LL*(k+1)*c - (2LL*(k+1) + 1) * t);

    if (p * (2LL*k + 3) <= q * (2LL*k + 1)) {
      printf("%d\n", k*2+1);
    } else {
      printf("%d\n", k*2+3);
    }
  }

  return 0;
}

int main() {
  int t = 1;
  scanf("%d", &t);
  for (int tc = 0; tc < t; ++tc) {
    // printf("Case #%d: ", tc+1);
    solve();
  }
  return 0;
}