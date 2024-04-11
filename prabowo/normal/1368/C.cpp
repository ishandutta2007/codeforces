#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int n;

int solve() {
  scanf("%d", &n);
  ++n;

  printf("%d\n", n*3 + 1);

  printf("0 0\n");
  for (int i = 0; i < n; ++i) {
    printf("%d %d\n", i+1, i+1);
    printf("%d %d\n", i+1, i);
    printf("%d %d\n", i, i+1);
  }
  printf("\n");
  return 0;
}

int main() {
  int t = 1;
  // scanf("%d", &t);
  while (t--) solve();
  return 0;
}