#include <bits/stdc++.h>
using namespace std;

const int N = 1000005;

int n, m;

int solve() {
  scanf("%d %d", &n, &m);
  if (n == 1) printf("0\n");
  else if (n == 2) printf("%d\n", m);
  else printf("%d\n", m*2);

  return 0;
}

int main() {
  int t = 1;
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}