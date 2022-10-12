#include <bits/stdc++.h>
using namespace std;

const int N = 1005;

int n, m;
int a[N];


int solve() {
  scanf("%d %d", &n, &m);
  
  int sum = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    sum += a[i];
  }
  
  printf("%d\n", min(sum, m));
  return 0;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}