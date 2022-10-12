#include <bits/stdc++.h>
using namespace std;

const int N = 55;

int n;
char s[N];

char match[10] = "abacaba";

int ok(int i, bool wild=false) {
  if (i < 0) return 0;
  for (int j = 0; j < 7; ++j) {
    if (i + j >= n) return 0;
    if (wild && s[i + j] == '?') continue;
    if (s[i + j] != match[j]) return 0;
  }
  return 1;
}

int solve() {
  scanf("%d", &n);
  scanf("%s", s);

  int cnt = 0;
  for (int i = 0; i <= n - 7; ++i) {
    if (ok(i)) ++cnt;
  }

  if (cnt > 1) return 0 * printf("No\n");

  if (cnt == 1) {
    for (int i = 0; i < n; ++i) if (s[i] == '?') s[i] = 'z';
    printf("Yes\n%s\n", s);
    return 0;
  }

  for (int i = 0; i <= n - 7; ++i) {
    if (ok(i, true)) {
      char tmp[7];
      for (int j = 0; j < 7; ++j) {
        tmp[j] = s[i + j];
        if (s[i + j] == '?') {
          s[i + j] = match[j];
        }
      }

      if (!ok(i+1) && !ok(i+2) && !ok(i+3) && !ok(i+4) && !ok(i+5) && !ok(i+6) &&
          !ok(i-1) && !ok(i-2) && !ok(i-3) && !ok(i-4) && !ok(i-5) && !ok(i-6)) {
        for (int j = 0; j < n; ++j) {
          if (s[j] == '?') s[j] = 'z';
        }

        printf("Yes\n%s\n", s);
        return 0;
      }

      for (int j = 0; j < 7; ++j) s[i + j] = tmp[j];
    }
  }

  printf("No\n");
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