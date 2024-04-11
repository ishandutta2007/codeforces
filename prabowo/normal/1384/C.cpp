#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int n;
char s[N], t[N];

int solve() {
  scanf("%d", &n);
  scanf("%s", s);
  scanf("%s", t);

  for (int i = 0; i < n; ++i) {
    if (s[i] > t[i]) return 0 * printf("-1\n");
  }

  int ans = 0;
  for (int k = 0; k < 20; ++k) {
    int idx = -1;
    for (int i = 0; i < n; ++i) {
      if (s[i] == t[i]) continue;
      if (idx == -1 || s[i] < s[idx] || (s[i] == s[idx] && t[i] < t[idx])) {
        idx = i;
      }
    }

    if (idx == -1) break;
    ++ans;

    char c = s[idx], d = t[idx];
    for (int i = 0; i < n; ++i) {
      if (s[i] != t[i] && s[i] == c) s[i] = d;
    }
  }

  printf("%d\n", ans);
  return 0;
}

int main() {
  int t = 1;
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}