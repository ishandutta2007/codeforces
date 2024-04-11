#include <bits/stdc++.h>
using namespace std;

long long n,m;

int main() {
  scanf("%I64d %I64d", &n, &m);
  int l, r;
  l = 0;
  r = n - 1;
  m--;
  int tmp[55];
  for (int i = 0; i < n - 1; i++) {
    int num = n - 2 - i;
    if ((m & ( 1LL << num)) == 0) {
      tmp[l] = i+1;
      l++;
    } else {
      tmp[r] = i+1;
      r--;
    }
  }
  tmp[r] = n;
  for (int i = 0; i < n; i++) {
    printf("%d ", tmp[i]);
  }
  printf("\n");
}