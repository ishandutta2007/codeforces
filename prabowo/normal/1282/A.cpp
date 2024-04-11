#include <bits/stdc++.h>
using namespace std;


int n;

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    int a, b, c, r;
    scanf("%d %d %d %d", &a, &b, &c, &r);
    if (a > b) swap(a, b);

    int ll = max(c - r, a);
    int rr = min(c + r, b);

    if (ll > rr) printf("%d\n", b - a);
    else printf("%d\n", b - a - (rr - ll));
  }
  return 0;
}