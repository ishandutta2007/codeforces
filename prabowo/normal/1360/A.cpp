#include <bits/stdc++.h>
using namespace std;

int a, b;

int solve() {
  scanf("%d %d", &a, &b);
  int side = min(max(a*2, b), max(a, b*2));
  printf("%d\n", side*side);
  return 0;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}