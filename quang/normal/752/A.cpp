#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, m, k;
  scanf("%d %d %d", &n, &m, &k);
  int l = (k - 1) / (m * 2) + 1;
  k -= (l - 1) * (m * 2) + 1;
  int x = k / 2 + 1;
  k %= 2;
  cout << l << " "  << x << " " << (k ? "R" : "L");
  return 0;
}