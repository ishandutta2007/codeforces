#include <bits/stdc++.h>
using namespace std;
 
const int N = 600005;

int n, m, k;
int a[N];
char s[N];

int par[N], L[N], R[N], val[N];

int solve() {
  scanf("%d", &n);
  scanf("%s", s);

  reverse(s, s + (1 << n) - 1);
  for (int i = 0; i < 2 << n; ++i) val[i] = 1;
  for (int i = (1 << n) - 2; i >= 0; --i) {
    if (s[i] == '0') {
      val[i] = val[i * 2 + 2];
    } else if (s[i] == '1') {
      val[i] = val[i * 2 + 1];
    } else if (s[i] == '?') {
      val[i] = val[i * 2 + 1] + val[i * 2 + 2];
    }
  }

  int q;
  scanf("%d", &q);
  while (q--) {
    int x; char c;
    scanf("%d %c", &x, &c);
    x = (1 << n) - x - 1;
    s[x] = c;

    for (int i = x; i >= 0; i = (i - 1) / 2) {
      if (s[i] == '0') {
        val[i] = val[i * 2 + 2];
      } else if (s[i] == '1') {
        val[i] = val[i * 2 + 1];
      } else if (s[i] == '?') {
        val[i] = val[i * 2 + 1] + val[i * 2 + 2];
      }
      if (i == 0) break;
    }

    printf("%d\n", val[0]);
  }
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