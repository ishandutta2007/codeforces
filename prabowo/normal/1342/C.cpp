#include <bits/stdc++.h>
using namespace std;

int a, b, q;

int solve() {
  scanf("%d %d %d", &a, &b, &q);

  vector<int> v;
  int lcm = 1;
  for (; lcm % a > 0 || lcm % b > 0; ++lcm) {
    if (lcm % a % b != lcm % b % a) v.push_back(lcm);
  }

  while (q--) {
    long long l, r;
    scanf("%lld %lld", &l, &r);

    if (v.size() == 0) {
      printf("0 ");
      continue;
    }

    long long ans = 0;
    ans += r / lcm * (lcm - v[0]) + max(0LL, r % lcm - v[0] + 1);
    ans -= (l-1) / lcm * (lcm - v[0]) + max(0LL, (l-1) % lcm - v[0] + 1);

    printf("%lld ", ans);
  }
  printf("\n");
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