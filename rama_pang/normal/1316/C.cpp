#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int n, m, p;
  cin >> n >> m >> p;

  int x = -1, y = -1;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    if (x == -1 && a % p != 0) {
      x = i;
    }
  }

  for (int i = 0; i < m; i++) {
    int b;
    cin >> b;
    if (y == -1 && b % p != 0) {
      y = i;
    }
  }
  

  cout << (x + y) << "\n";
  return 0;
}