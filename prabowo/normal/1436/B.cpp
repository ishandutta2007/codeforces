#include <bits/stdc++.h>
using namespace std;

int n, m;

bool isPrime(int n) {
  for (int i = 2; i*i <= n; ++i) {
    if (n % i == 0) return false;
  }
  return true;
}

int solve() {
  scanf("%d", &n);

  int sum = 101;
  while (isPrime(sum - n + 1) || !isPrime(sum)) ++sum;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (i == j) printf("%d ", sum - n + 1);
      else printf("1 ");
    }
    printf("\n");
  }
  // printf("-1\n");
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