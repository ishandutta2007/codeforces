#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int n, k;
char s[N];

int solve() {
  scanf("%d %d", &n, &k);
  scanf("%s", s);

  vector<bool> down(26, false);
  for (int i = 0; i < n; ++i) {
    int c = s[i] - 'a';
    while (c > 0 && k > 0) {
      if (!down[c]) {
        down[c] = true;
        --k;
      }
      --c;
    }
  }

  for (int i = 0; i < n; ++i) {
    int c = s[i] - 'a';
    while (down[c]) --c;
    printf("%c", c + 'a');
  }
  printf("\n");
  return 0;
}

int main() {
  int t = 1;
  scanf("%d", &t);
  for (int tc = 0; tc < t; ++tc) {
    // printf("Case #%d: ", tc + 1);
    solve();
  }
}