#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int n, q, c;
tuple<int, int, int> stars[N];

long long pre[11][105][105];

int solve() {
  scanf("%d %d %d", &n, &q, &c);

  for (int i = 0; i < n; ++i) {
    int x, y, s;
    scanf("%d %d %d", &x, &y, &s);

    for (int k = 0; k <= c; ++k) {
      pre[k][x][y] += (s + k) % (c + 1);
    }
  }
  
  for (int k = 0; k <= 10; ++k) {
    for (int i = 1; i <= 100; ++i) {
      for (int j = 1; j <= 100; ++j) {
        pre[k][i][j] += pre[k][i-1][j] + pre[k][i][j-1] - pre[k][i-1][j-1];
      }
    }
  }

  while (q--) {
    int t, x, y, xx, yy;
    scanf("%d %d %d %d %d", &t, &x, &y, &xx, &yy);
    t %= c + 1;
    printf("%lld\n", pre[t][xx][yy] - pre[t][x-1][yy] - pre[t][xx][y-1] + pre[t][x-1][y-1]);
  }

  return 0;
}


int main() {
  int t = 1;
  // scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}