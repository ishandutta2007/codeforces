#include <bits/stdc++.h>

using namespace std;

vector <pair<int, int> > a[10];
long long res[6];

bool go(long long u, long long v) {
  if (u == 0) {
    return 1;
  }
  if (u < 0) {
    return 0;
  }
  int last = u % 10;
  for (auto it : a[last]) {
    int x = it.first, y = it.second;
    if (go(((u - x * 4 - y * 7) / 10), v * 10)) {
      for (int i = 0; i < x; i++) {
        res[i] += v * 4;
      }
      for (int i = x; i < x + y; i++) {
        res[i] += v * 7;
      }
      return 1;
    }
  }
  return 0;
}

int main() {
  for (int i = 0; i <= 6; i++) {
    for (int j = 0; i + j <= 6; j++) {
      a[(i * 4 + 7 * j) % 10].push_back(make_pair(i, j));
    }
  }
  int t;
  scanf("%d", &t);
  while (t-- ){
    for (int i = 0; i < 6; i++) {
      res[i] = 0;
    }
    long long n;
    scanf("%I64d", &n);
    if (go(n, 1)) {
      for (int i = 0; i < 6; i++) {
        printf("%I64d ", res[i]);
      }
      printf("\n");
    } else {
      printf("-1\n");
    }
  }
  return 0;
}