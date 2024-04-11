#include <bits/stdc++.h>
using namespace std;

const int N = 1000005;

int d, k;

int solve() {
  scanf("%d %d", &d, &k);
  int x = 0;
  while (2LL * (x+k) * (x+k) <= 1LL * d * d) x += k;

  if (1LL * (x+k) * (x+k) + 1LL * x * x <= 1LL * d * d) printf("Ashish\n");
  else printf("Utkarsh\n");
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