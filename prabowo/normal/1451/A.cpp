#include <bits/stdc++.h>
using namespace std;

const int N = 105;

int n;

int solve() {
  scanf("%d", &n);

  if (n == 1) printf("0\n");
  else if (n == 2) printf("1\n");
  else if (n == 3) printf("2\n");
  else if (n % 2 == 0) printf("2\n");
  else printf("3\n");
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