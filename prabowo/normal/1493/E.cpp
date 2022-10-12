#include <bits/stdc++.h>
using namespace std;
 
const int N = 1000005;

int n;
char l[N], r[N];

void inc(char s[]) {
  for (int i = n - 1; i >= 0; --i) {
    if (s[i] == '0') {
      s[i] = '1';
      break;
    } else {
      s[i] = '0';
    }
  }
}

int solve() {
  scanf("%d", &n);
  scanf("%s", l);
  scanf("%s", r);

  if (l[0] != r[0]) {
    for (int i = 0; i < n; ++i) printf("1"); printf("\n");
    return 0;
  }

  if (r[n - 1] == '1') return 0 * printf("%s\n", r);

  inc(l);
  if (strcmp(l, r) >= 0) return 0 * printf("%s\n", r);

  inc(r);
  printf("%s\n", r);
  return 0;
}

int main() {
  int t = 1;
  // scanf("%d", &t);
  for (int tc = 0; tc < t; ++tc) {
    // printf("Case #%d: ", tc+1);
    solve();
  }
  return 0;
}