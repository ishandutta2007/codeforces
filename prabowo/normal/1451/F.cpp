#include <bits/stdc++.h>
using namespace std;

const int N = 105;

int n, m;
int d[N << 1];

int solve() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n + m; ++i) d[i] = 0;
  for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
    int a; scanf("%d", &a);
    d[i + j] ^= a;
  }

  for (int i = 0; i < n + m - 1; ++i) if (d[i] != 0) return 0 * printf("Ashish\n");
  printf("Jeel\n");
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