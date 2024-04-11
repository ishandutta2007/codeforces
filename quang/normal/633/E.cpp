#include <bits/stdc++.h>

using namespace std;

const int N = 1000010;

int n, k;
int v[N], c[N];
int maxVal[21][N], minVal[21][N];
int a[N];

int getMax(int l, int r) {
  int h = log2(r - l + 1);
  int res = maxVal[h][l];
  res = max(res, maxVal[h][r - (1 << h) + 1]);
  return res;
}

int getMin(int l, int r) {
  int h = log2(r - l + 1);
  int res = minVal[h][l];
  res = min(res, minVal[h][r - (1 << h) + 1]);
  return res;
}

int main() {
  scanf("%d %d", &n, &k);
  for (int i = 1; i <= n; i++) {
    scanf("%d", v + i);
    v[i] *= 100;
  }
  for (int i = 1; i <= n; i++) {
    scanf("%d", c + i);
  }
  for (int i = 1; i <= n; i++) {
    maxVal[0][i] = v[i];
    minVal[0][i] = c[i];
  }
  for (int i = 1; i <= 20; i++) {
    for (int j = 1; j + (1 << i) - 1 <= n; j++) {
      maxVal[i][j] = max(maxVal[i - 1][j], maxVal[i - 1][j + (1 << (i - 1))]);
      minVal[i][j] = min(minVal[i - 1][j], minVal[i - 1][j + (1 << (i - 1))]);
    }
  }
  for (int i = 1; i <= n; i++) {
    if (v[i] >= c[i]) {
      a[i] = c[i];
      continue;
    }
    int l = i, r = n + 1;
    while (r - l > 1) {
      int m = (l + r) >> 1;
      int p1 = getMax(i, m);
      int p2 = getMin(i, m);
      if (p2 > p1) {
        l = m;
      } else {
        r = m;
      }
    }
    int &x = a[i];
    x = min(getMax(i, l), getMin(i, l));
    if (l < n) {
      x = max(x, min(getMax(i, l + 1), getMin(i, l + 1)));
    }
  }
  sort(a + 1, a + n + 1);
  long double res = 0;
  long double mul = (double) k / (double) n;
  int cur1 = n - k;
  int cur2 = n - 1;
  for (int i = 1; i <= n; i++) {
    if (k - 1 > n - i) {
      break;
    }
    if (i == 1) {
      res += mul * a[i];
    } else {
      mul *= (double)cur1 / (double)cur2;
      cur1--;
      cur2--;
      res += mul * a[i];
    }
  }
  printf("%0.17f", (double)res);
  return 0;
}