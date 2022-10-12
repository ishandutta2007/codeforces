#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int n;

int solve() {
  scanf("%d", &n);

  for (int i = 0; i < n; ++i) {
    printf("%d ", i+1);
  }

  printf("\n");
  return 0;
}

int main() {
  int t = 1;
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}