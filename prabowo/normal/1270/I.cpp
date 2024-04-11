#include <bits/stdc++.h>
using namespace std;

const int K = 9;

int k;
long long a[1 << K][1 << K];
int t;
pair<int, int> figure[99];

long long na[1 << K][1 << K];

int main() {
  scanf("%d", &k);
  int n = 1 << k;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      scanf("%lld", &a[i][j]);
    }
  }
  scanf("%d", &t);
  for (int i = 0; i < t; ++i) {
    scanf("%d %d", &figure[i].first, &figure[i].second);
  }

  for (int i = t-1; i >= 0; --i) {
    figure[i].first = (figure[i].first - figure[0].first) & (n-1);
    figure[i].second = (figure[i].second - figure[0].second) & (n-1);
  }

  for (int it = 0; it < k; ++it) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        na[i][j] = 0;
        for (int ii = 0; ii < t; ++ii) {
          na[i][j] ^= a[(i - figure[ii].first) & (n-1)][(j - figure[ii].second) & (n-1)];
        }
      }
    }

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        a[i][j] = na[i][j];
      }
    }

    for (int i = 1; i < t; ++i) {
      figure[i].first = (figure[i].first << 1) & (n-1);
      figure[i].second = (figure[i].second << 1) & (n-1);
    }
  }

  int ans = 0;
  for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) {
    ans += (a[i][j] > 0);
  }
  printf("%d\n", ans);
  return 0;
}