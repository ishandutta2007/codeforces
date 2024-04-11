#include <cstdio>
#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int n, s = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
      int x;
      cin >> x;
      s += x;
    }
    if (s % n)
      cout << 1 << '\n';
    else
      cout << 0 << '\n';
  }
}