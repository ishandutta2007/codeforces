#include <bits/stdc++.h>
using namespace std;

long long a[3];

int add(long long y) {
  printf("%lld\n", y);
  fflush(stdout);

  int pile;
  scanf("%d", &pile);
  a[--pile] += y;
  return pile;
}

int main() {
  scanf("%lld %lld %lld", &a[0], &a[1], &a[2]);
  printf("First\n");
  int pile = add(1e9);
  pile = add(a[pile]*3 - a[0] - a[1] - a[2]);
  add((a[pile] - min({a[0], a[1], a[2]})) / 2);
  return 0;
}