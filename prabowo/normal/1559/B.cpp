#include <bits/stdc++.h>
using namespace std;
 
const int N = 200005;

int n, m, k;
int a[N];
char s[N];

int col(int x) {
  if (x < 0 || x >= n) return -1;
  if (s[x] == 'R') return 0;
  return 1;
}

int solve() {
  scanf("%d", &n);
  scanf("%s", s);

  for (int i = 0; i < n; ) {
    if (s[i] != '?') {
      ++i;
      continue;
    }

    int j = i;
    while (j < n && s[j] == '?') ++j;

    int l = col(i - 1), r = col(j);
    // cerr << l << " " << r << endl;

    int st = 0;
    if (j - i & 1) {
      if ((l == 1) + (r == 1) < (l == 0) + (r == 0)) {
        st = 1;
      } else {
        st = 0;
      }
    } else {
      if ((l == 1) + (r == 0) < (l == 0) + (r == 1)) {
        st = 1;
      } else {
        st = 0;
      }
    }

    for (int k = i; k < j; ++k) {
      if (st) s[k] = 'B';
      else s[k] = 'R';
      st ^= 1;
    }

    i = j;
  }

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