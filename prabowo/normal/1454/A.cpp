#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int solve() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i < n; ++i) {
    printf("%d ", i + 1);
  }
  printf("1\n");
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