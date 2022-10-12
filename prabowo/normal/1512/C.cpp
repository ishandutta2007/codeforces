#include <bits/stdc++.h>
using namespace std;
 
const int N = 200005;

int a, b;
char s[N];

int solve() {
  scanf("%d %d", &a, &b);
  scanf("%s", s);
  int n = strlen(s);

  for (int i = 0; i < n; ++i) {
    if (s[i] == '0') --a;
    else if (s[i] == '1') --b;
  }

  for (int i = 0, j = n - 1; i < j; ++i, --j) {
    if (s[i] == '?' && s[j] == '?') continue;
    if (s[i] == '?' || s[j] == '?') {
      if (s[i] == '?') swap(s[i], s[j]);

      if (s[i] == '0') --a;
      else --b;

      s[j] = s[i];
    } else if (s[i] != s[j]) {
      return 0 * printf("-1\n");
    }
  }

  if (a < 0 || b < 0) return 0 * printf("-1\n");

  for (int i = 0, j = n - 1; i < j; ++i, --j) {
    if (s[i] == '?' && s[j] == '?') {
      if (a >= 2) {
        a -= 2;
        s[i] = s[j] = '0';
      } else if (b >= 2) {
        b -= 2;
        s[i] = s[j] = '1';
      } else {
        return 0 * printf("-1\n");
      }
    }
  }

  if ((n & 1) && s[n / 2] == '?') {
    if (a + b != 1) return 0 * printf("-1\n");
    if (a == 1) {
      s[n / 2] = '0';
      --a;
    } else {
      s[n / 2] = '1';
      --b;
    }
  }

  if (a != 0 || b != 0) return 0 * printf("-1\n");

  printf("%s\n", s);
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