#include <bits/stdc++.h>
using namespace std;

const int N = 1000005;
const int MOD = 998244353;

int n;
char s[N];

int solve() {
  scanf("%s", s);
  n = strlen(s);

  int cur = 0;
  int mini = 0;
  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '-') {
      --cur;
    } else {
      ++cur;
    }

    if (cur < mini) {
      mini = cur;
      ans += i + 1;
    }
  }

  printf("%lld\n", ans + n);

  return 0;
}

int main() {
  int t = 1;
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}