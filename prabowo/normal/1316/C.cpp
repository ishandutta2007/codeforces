#include <bits/stdc++.h>
using namespace std;

int solve() {
  int n, m, p;
  scanf("%d %d %d", &n, &m, &p);
  
  int idxA = n;
  for (int i = 0; i < n; ++i) {
    int a;
    scanf("%d", &a);
    if (a % p != 0) {
      idxA = min(idxA, i);
    }
  }
  
  int idxB = m;
  for (int i = 0; i < m; ++i) {
    int a;
    scanf("%d", &a);
    if (a % p != 0) {
      idxB = min(idxB, i);
    }
  }
  
  printf("%d\n", idxA + idxB);
  return 0;
}

int main() {
  int t = 1;
  // scanf("%d", &t);
  while (t--) solve();
  return 0;
}