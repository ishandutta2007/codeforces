#include <bits/stdc++.h>
using namespace std;

const int N = 55;

char s[N];

int solve() {
  scanf("%s", s);
  int n = strlen(s);
  for (int i = 0; i < n; ++i) {
    if (i & 1) {
      if (s[i] == 'z') printf("y");
      else printf("z");
    } else {
      if (s[i] == 'a') printf("b");
      else printf("a");
    }
  }
  printf("\n");
  return 0;
}

int main() {
  int t = 1;
  scanf("%d", &t);
  for (int tc = 0; tc < t; ++tc) {
    solve();
  }
  return 0;
}