#include <bits/stdc++.h>
using namespace std;

const double PI = acos(-1);

int n;

int solve() {
  scanf("%d", &n);
  double len = 0;

  double ang = 0;
  for (int i = 1; i < n/2; ++i) {
    ang += PI / n;
    len += cos(ang);
  }

  len = len*2 + 1;
  printf("%.9lf\n", len);
  return 0;
}

int main() {
  int t = 1;
  scanf("%d", &t);
  while (t--) solve();  
  return 0;
}