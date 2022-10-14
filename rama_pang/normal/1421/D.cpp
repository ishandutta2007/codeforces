#include <bits/stdc++.h>
using namespace std;
using lint = long long;

void Main() {
  lint x, y;
  vector<vector<lint>> c(7, vector<lint>(7, 1e18));
  cin >> x >> y;
  for (int i = 1; i <= 6; i++) {
    cin >> c[0][i];
  }
  // Clockwise
  c[1][2] = c[0][3];
  c[2][3] = c[0][4];
  c[3][4] = c[0][5];
  c[4][5] = c[0][6];
  c[5][6] = c[0][1];
  c[6][1] = c[0][2];

  // Counter Clockwise
  c[2][1] = c[0][6];
  c[3][2] = c[0][1];
  c[4][3] = c[0][2];
  c[5][4] = c[0][3];
  c[6][5] = c[0][4];
  c[1][6] = c[0][5];

  // Inside
  c[1][0] = c[0][4];
  c[2][0] = c[0][5];
  c[3][0] = c[0][6];
  c[4][0] = c[0][1];
  c[5][0] = c[0][2];
  c[6][0] = c[0][3];

  for (int i = 0; i < 7; i++) {
    for (int j = 0; j < 7; j++) {
      for (int k = 0; k < 7; k++) {
        c[i][j] = min(c[i][j], c[i][k] + c[k][j]);
      }
    }
  }

  lint ans = 0;
  if (x >= 0 && y >= 0) {
    lint d = min(x, y);
    x -= d;
    y -= d;
    ans += d * c[0][1];
  } else if (x <= 0 && y <= 0) {
    lint d = max(x, y);
    x -= d;
    y -= d;
    ans += -d * c[0][4];
  }
  swap(x, y);
  if (x < 0) {
    ans += abs(x) * c[0][5];
  }
  if (x > 0) {
    ans += abs(x) * c[0][2];
  }
  if (y < 0) {
    ans += abs(y) * c[0][3];
  }
  if (y > 0) {
    ans += abs(y) * c[0][6];
  }

  cout << ans << "\n";
  return;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T = 1;
  cin >> T;
  while (T--) {
    Main();
  }
  return 0;
}