#include <bits/stdc++.h>
using namespace std;

const int N = 105;

int n, k;
int x[N], y[N];

int solve() {
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; ++i) {
    scanf("%d %d", &x[i], &y[i]);
  }

  for (int i = 0; i < n; ++i) {
    bool okay = true;
    for (int j = 0; j < n; ++j) {
      if (abs(x[i] - x[j]) + abs(y[i] - y[j]) > k) {
        okay = false;
        break;
      }
    }

    if (okay) return 0 * printf("1\n");
  }
  printf("-1\n");
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