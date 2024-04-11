#include <cstdio>
#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int x, y;
    cin >> x >> y;
    if (x > y)
      cout << x + y << '\n';
    else {
      x = y / x * x;
      cout << (x + y) / 2 << '\n';
    }
  }
}