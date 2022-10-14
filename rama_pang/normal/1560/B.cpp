#include <bits/stdc++.h>
using namespace std;

void Main() {
  int a, b, c;
  cin >> a >> b >> c;
  if (a > b) swap(a, b);
  int n = 2 * (b - a);
  if (a < 1 || a > n || b < 1 || b > n || c < 1 || c > n) {
    cout << -1 << '\n';
    return;
  }
  int d = c + n / 2;
  if (d > n) d -= n;
  cout << d << '\n';
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