#include <bits/stdc++.h>
using namespace std;

void Main() {
  int w, h, n;
  cin >> w >> h >> n;
  int cnt = 1;
  while (w % 2 == 0 || h % 2 == 0) {
    if (w % 2 == 0) {
      w /= 2;
      cnt *= 2;
      if (cnt >= n) {
        break;
      }
    }
    if (h % 2 == 0) {
      h /= 2;
      cnt *= 2;
      if (cnt >= n) {
        break;
      }
    }
  }
  cout << (cnt >= n ? "YES\n" : "NO\n");
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