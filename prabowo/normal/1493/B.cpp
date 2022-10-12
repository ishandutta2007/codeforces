#include <bits/stdc++.h>
using namespace std;
 
const int N = 200005;
const int MOD = 1000000007;
const int INF = 1e9;

int h, m;
int x, y;

bool okay(int x) {
  if (x == 0) return true;
  int d = x % 10;
  if (d == 0 || d == 1 || d == 2 || d == 5 || d == 8) return okay(x / 10);
  return false;
}

int inv(int x) {
  if (x == 0) return 0;
  if (x == 1) return 1;
  if (x == 2) return 5;
  if (x == 5) return 2;
  if (x == 8) return 8;
  return -1000;
}

bool rev(int x, int y) {
  int nx = inv(y % 10) * 10 + inv(y / 10);
  int ny = inv(x % 10) * 10 + inv(x / 10);

  if (nx < 0 || ny < 0) return false;
  if (nx >= h || ny >= m) return false;
  return true;
}

int solve() {
  scanf("%d %d", &h, &m);
  scanf("%d:%d", &x, &y);

  while (!rev(x, y)) {
    ++y;
    if (y >= m) {
      y -= m;
      ++x;

      if (x >= h) {
        x -= h;
      }
    }
  }

  printf("%02d:%02d\n", x, y);
  return 0;
}

int main() {
  int t = 1;
  scanf("%d", &t);
  for (int tc = 0; tc < t; ++tc) {
    // printf("Case #%d: ", tc+1);
    solve();
  }
  return 0;
}