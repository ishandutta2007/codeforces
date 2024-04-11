#include <bits/stdc++.h>
using namespace std;

long long n, s;

int sum(long long n) {
  int ret = 0;
  while (n > 0) {
    ret += n % 10;
    n /= 10;
  }
  return ret;
}

int solve() {
  scanf("%lld %lld", &n, &s);

  long long l = 0, r = n, ans = -1;
  while (l <= r) {
    long long mid = (l + r) >> 1;

    if (mid - sum(mid) < s) {
      l = mid + 1;
      ans = mid;
    } else {
      r = mid - 1;
    }
  }

  printf("%lld\n", n - ans);
  return 0;
}


int main() {
  int t = 1;
  // scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}