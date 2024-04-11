#include <bits/stdc++.h>
using namespace std;

const int N = 1000005;

int n, k;
char s[N];

int cc[N];

int solve() {
  scanf("%d", &k);
  scanf("%s", s);

  int n = strlen(s);

  int cnt = 0;
  long long ans = 0;
  ++cc[0];
  for (int i = 0; i < n; ++i) {
    if (s[i] == '1') {
      ++cnt;
    }

    if (cnt >= k) {
      ans += cc[cnt - k];
    }

    ++cc[cnt];
  }

  printf("%lld\n", ans);
  return 0;
}

int main() {
  int t = 1;
  // scanf("%d", &t);
  while (t--) solve();
  return 0;
}