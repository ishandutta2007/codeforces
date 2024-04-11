#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  scanf("%d", &n);

  int cur = 1;
  for (int i = 1; i < 20; i++) {
    if (cur == n || cur + 1 == n) return 0 * printf("1\n");
    cur = cur*2 + 1 + (i & 1);
  }

  printf("0\n");
  return 0;
}