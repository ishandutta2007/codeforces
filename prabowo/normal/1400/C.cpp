#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int n, x;
char s[N];
char w[N];

int solve() {
  scanf("%s", s);
  scanf("%d", &x);

  n = strlen(s);

  for (int i = 0; i < n; ++i) {
    int zero = 0;
    if (i + x < n && s[i+x] == '0') zero = 1;
    if (i - x >= 0 && s[i-x] == '0') zero = 1;

    if (zero) w[i] = '0';
    else w[i] = '1';
  }

  for (int i = 0; i < n; ++i) {
    int one = 0;
    if (i + x < n && w[i+x] == '1') one = 1;
    if (i - x >= 0 && w[i-x] == '1') one = 1;
    if (one != (s[i] == '1')) return 0 * printf("-1\n");
  }

  w[n] = 0;
  printf("%s\n", w);
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