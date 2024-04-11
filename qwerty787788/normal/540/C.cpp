#include <bits/stdc++.h>

const int M = 555;
std::string field[M];
bool was[M][M];
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

int n, m, r1, c1, r2, c2;

bool start_or_end(int x, int y) {
  if (x == r1 && y == c1) return true;
  if (x == r2 && y == c2) return true;
  return false;
}

void go(int x, int y) {
  if (x < 0 || x >= n || y < 0 || y >= m) return;
  if (field[x][y] == 'X' && !start_or_end(x, y)) return;
  if (was[x][y]) return;
  was[x][y] = true;
  for (int ii = 0; ii < 4; ii++) go(x + dx[ii], y + dy[ii]);
}

bool ok(int x, int y) {
  if (x < 0 || x >= n || y < 0 || y >= m) return false;
  if (field[x][y] == '.') return true;
  if (x == r1 && y == c1) return true;
  if (x == r2 && y == c2) return true;
  return false;
}

int cnt_ok_neighbours(int x, int y) {
  int res = 0;
  for (int ii = 0; ii < 4; ii++) res += ok(x + dx[ii], y + dy[ii]) ? 1 : 0;
  return res;
}

int main() {
  std::cin >> n >> m;
  for (int i = 0; i < n; i++) {
    std::cin >> field[i];
  }
  std::cin >> r1 >> c1 >> r2 >> c2;
  r1--; c1--; r2--; c2--;
  go(r1, c1);
  if (!was[r2][c2]) {
    std::cout << "NO" << std::endl;
    return 0;
  }
  if (r1 == r2 && c1 == c2) {
    std::cout << (cnt_ok_neighbours(r1, c1) > 0 ? "YES" : "NO") << std::endl;
    return 0;
  }
  if (field[r2][c2] == 'X' || cnt_ok_neighbours(r2, c2) > 1) {
    std::cout << "YES" << std::endl;
  } else  {
    std::cout << "NO" << std::endl;
  }
}