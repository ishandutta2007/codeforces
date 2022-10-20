#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n, p;
int l[N], r[N];

int get(int u) {
  return u / p;
}

int main() {
  scanf("%d %d", &n, &p);
  for (int i = 1; i <= n; i++) {
    scanf("%d %d", l + i, r + i);
  }
  l[n + 1] = l[1];
  r[n + 1] = r[1];
  double res = 0;
  for (int i = 1; i <= n; i++) {
    long long tot = 1ll * (r[i] - l[i] + 1) * (r[i + 1] - l[i + 1] + 1);
    int x1 = get(r[i]) - get(l[i] - 1);
    x1 = (r[i] - l[i] + 1) - x1;
    int x2 = get(r[i + 1]) - get(l[i + 1] - 1);
    x2 = (r[i + 1] - l[i + 1] + 1) - x2;
    long long tot2 = 1ll * x1 * x2;
    double pro = (double)tot2 / (double)tot;
    pro = 1.0 - pro;
    res += pro;
  }
  res *= 2000.0;
  printf("%0.17f", res);
  return 0;
}