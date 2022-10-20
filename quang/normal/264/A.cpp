#include <bits/stdc++.h>

using namespace std;

char s[1000010];
int a[1000010], b[1000010];
int topa, topb;

int main() {
  scanf("%s", s + 1);
  int n = strlen(s + 1);
  for (int i = 1; i <= n; i++) {
    if (s[i] == 'r') {
      a[topa++] = i;
    } else {
      b[topb++] = i;
    }
  }
  for (int i = 0; i < topa; i++) {
    printf("%d\n", a[i]);
  }
  for (int i = topb - 1; i >= 0; i--) {
    printf("%d\n", b[i]);
  }
  return 0;
}