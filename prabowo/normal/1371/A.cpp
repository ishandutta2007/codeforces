#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int n;
int a[N];

int solve() {
  scanf("%d", &n);
  printf("%d\n", (n+1)/2);
  return 0;
}

int main() {
  int t = 1;
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}