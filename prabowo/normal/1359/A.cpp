#include <bits/stdc++.h>
using namespace std;

const int N = 33;

int n, m, k;

int solve() {
  scanf("%d %d %d", &n, &m, &k);
  int hand = n/k;
  if (m < hand) return 0 * printf("%d\n", m);

  m -= hand;
  printf("%d\n", hand - (m + k-2) / (k-1));
  return 0;
}

int main() {
  int t = 1;
  scanf("%d", &t);
  for (int tc = 0; tc < t; ++tc) {
    // printf("Case #%d: ", tc+1);
    solve();
  }
  return 0;
}