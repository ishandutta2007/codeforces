#include <bits/stdc++.h>

using namespace std;

int n;
int sum;
int a[5];

int check(int u, int v) {
  int b[5];
  for (int i = 0; i < 5; i++) {
    b[i] = a[i];
  }
  int foo = sum;
  for (int i = 4; i >= 0; i--) {
    if (u <= b[i]) {
      foo -= u * i;
      b[i] -= u;
      u = 0;
      break;
    } else {
      u -= b[i];
      foo -= b[i] * i;
      b[i] = 0;
    }
  }
  for (int i = 4; i >= 0; i--) {
    if (v <= b[i]) {
      foo -= v * min(3, i);
      b[i] -= v;
      v = 0;
      break;
    } else {
      v -= b[i];
      foo -= b[i] * min(3, i);
      b[i] = 0;
    }
  }
  return foo;
}

int main() {
  //ios_base::sync_with_stdio(0);
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    int u;
    scanf("%d", &u);
    a[u]++;
    sum += u;
  }
  int res = 1e9;
  for (int i = 0; i * 4 <= sum; i++) {
    int ex = sum - i * 4;
    if (ex % 3) {
      continue;
    }
    ex /= 3;
    res = min(res, check(i, ex));
  }
  if (res >= 1e9) {
    printf("-1");
  } else {
    printf("%d", res);
  }
  return 0;
}