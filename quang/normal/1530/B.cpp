#include <bits/stdc++.h>

using namespace std;

void solve(int test) {
  int h, w;
  cin >> h >> w;
  for (int i = 1; i <= h; i++) {
    if (i == 1 || i == h) {
      for (int j = 1; j <= w; j++) {
        if (j == 1 || j == w) {
          cout << 1;
        } else if (j % 2 == 1 && j + 1 != w) {
          cout << 1;
        } else cout << 0;
      }
    } else {
      for (int j = 1; j <= w; j++) {
        if ((j == 1 || j == w) && i % 2 == 1 && i + 1 != h) {
          cout << 1;
        } else cout << 0;
      }
    }
    cout << '\n';
  }
  cout << '\n';
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int tc;
  cin >> tc;
  for (int test = 1; test <= tc; ++test) solve(test);
  return 0;
}