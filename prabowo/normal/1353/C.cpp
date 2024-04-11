#include <bits/stdc++.h>
using namespace std;

const int N = 33;

int n;

int solve() {
  scanf("%d", &n);
  // sum_{1..n/2} 8*i*i
  n /= 2;
  printf("%lld\n", 8LL * n * (n+1) * (n*2 + 1) / 6);
  return 0;
}

int main() {
  int t = 1;
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}