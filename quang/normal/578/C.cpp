#include <bits/stdc++.h>

using namespace std;

const int N = 200010;

int n;
int a[N];
long double sum[N];

long double get(long double u) {
  sum[0] = 0;
  long double res = 0;
  for (int i = 1; i <= n; i++) {
    sum[i] = sum[i - 1] - u + a[i];
  }
  long double minval = 0;
  long double maxval = 0;
  for (int i = 1; i <= n; i++) {
    res = max(res, abs(sum[i] - minval));
    res = max(res, abs(sum[i] - maxval));
    minval = min(minval, sum[i]);
    maxval = max(maxval, sum[i]);
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(0);
  #ifdef Doflamingo
  //freopen("input.txt", "r", stdin);
  #endif // Doflamingo
  cin >> n;
  for (int i =1 ; i <= n; i++) {
    cin >> a[i];
  }
  long double l, r;
  l = -10000000000ll;
  r = 10000000000ll;
  for (int i = 1; i <= 150; i++) {
    long double m1 = (r - l) / 3 + l;
    long double m2 = (r - l) * 2 / 3 + l;
    long double x1 = get(m1);
    long double x2 = get(m2);
    if (x1 > x2) {
      l = m1;
    } else {
      r = m2;
    }
  }
  printf("%0.17f", (double) get((l + r) / 2));
  return 0;
}