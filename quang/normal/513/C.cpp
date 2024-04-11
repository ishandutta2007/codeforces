#include <bits/stdc++.h>

#define Task "C"
#define fi freopen(Task".inp", "r", stdin)
#define fo freopen(Task".out", "w", stdout)

using namespace std;

const int N = 10;

int n;
int l[N], r[N];

int main() {
  //fi, fo;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> l[i] >> r[i];
  }
  double res = 0.0;
  for (int val = 1; val <= 10010; val++) {
    for (int mask = 3; mask < (1 << n); mask++) {
      int cnt = 0;
      for (int i = 0; i < n; i++) {
        if ((mask >> i) & 1) {
          cnt++;
        }
      }
      if (cnt < 2) {
        continue;
      }
      double prob = 1.0;
      for (int i = 0; i < n; i++) {
        int a = l[i], b = r[i];
        if ((mask >> i) & 1) {
          if (a < val) {
            a = val;
          }
        }
        else {
          if (b > val - 1) {
            b = val - 1;
          }
        }
        if (a > b) {
          prob = 0.0;
          break;
        }
        prob *= (1.0 * b - a + 1) / (1.0 * r[i] - l[i] + 1);
      }
      res += prob;
    }
  }
  printf("%0.10f", res);
  return 0;
}