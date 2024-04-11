#include <iostream>
#include <cstdio>
#include <string.h>

using namespace std;

int sum[16][128][128];
int a[16][128][128];

int main() {
  cin.sync_with_stdio(false);
  cin.tie(nullptr);
  int n, q, c;
  cin >> n >> q >> c;
  memset(a, 0, sizeof(a));
  for (int i = 0; i < n; ++i) {
    int x, y, s;
    cin >> x >> y >> s;
    ++a[s][x][y];
  }
  memset(sum, 0, sizeof(sum));
  for (int time = 0; time <= c; ++time) {
    for (int s = 0; s <= c; ++s) {
      for (int x = 0; x < 128; ++x) {
        for (int y = 0; y < 128; ++y) {
          sum[time][x][y] += a[s][x][y] * s;
        }
      }
    }
    for (int x = 1; x < 128; ++x) {
      for (int y = 1; y < 128; ++y) {
        sum[time][x][y] += sum[time][x - 1][y] + sum[time][x][y - 1] - sum[time][x - 1][y - 1];
      }
    }
    for (int x = 0; x < 128; ++x) {
      for (int y = 0; y < 128; ++y) {
        int last = a[c][x][y];
        for (int s = c - 1; s >= 0; --s) {
          a[s + 1][x][y] = a[s][x][y];
        }
        a[0][x][y] = last;
      }
    }
  }
  for (int i = 0; i < q; ++i) {
    int t, x1, y1, x2, y2;
    cin >> t >> x1 >> y1 >> x2 >> y2;
    t %= (c + 1);
    --x1;
    --y1;
    printf("%d\n", sum[t][x2][y2] - sum[t][x2][y1] - sum[t][x1][y2] + sum[t][x1][y1]);
  }
  return 0;
}