#include <bits/stdc++.h>
using namespace std;

void Main() {
  int x, y;
  cin >> x >> y;
  if (x == 0 && y == 0) {
    cout << "0\n";
  } else {
    int s = sqrt(x * x + y * y);
    if (s * s == x * x + y * y || (s - 1) * (s - 1) == x * x + y * y || (s + 1) * (s + 1) == x * x + y * y) {
      cout << "1\n";
    } else {
      cout << "2\n";
    }
  }
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