#include <bits/stdc++.h>
using namespace std;

const double PI = acos(-1);

int n;

int solve() {
  scanf("%d", &n);
  double len = 0;

  double ang = PI / 4;
  for (int i = 0; i < n; ++i) {
    len += abs(cos(ang));
    ang += PI / n;
  }

  printf("%.9lf\n", len);
  return 0;
}

int main() {
  int t = 1;
  scanf("%d", &t);
  while (t--) solve();  
  return 0;
}