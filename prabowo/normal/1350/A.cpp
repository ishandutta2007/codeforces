#include <bits/stdc++.h>
using namespace std;
 
int n, k;
 
int smallestD(int n) {
  for (int i = 2; i*i <= n; ++i) {
    if (n % i == 0) return i;
  }
  return n;
}

int solve() {
  scanf("%d %d", &n, &k);
  printf("%d\n", n + smallestD(n) + (k-1)*2);
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