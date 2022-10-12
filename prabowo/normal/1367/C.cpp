#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int n, k;
char s[N];

int solve() {
  scanf("%d %d", &n, &k);
  scanf("%s", s);

  int ans = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '1') continue;
    int j = i;
    while (j < n && s[j] == '0') ++j;

    if (i == 0 && j == n) {
      ans += (j - i - 1) / (k + 1) + 1;
    } else if (i == 0 || j == n) {
      ans += (j - i) / (k + 1);
    } else {
      ans += (j - i - k) / (k + 1);
    }

    i = j;
  }

  printf("%d\n", ans);
  return 0;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}