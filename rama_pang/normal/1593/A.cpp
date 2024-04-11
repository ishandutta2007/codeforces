#include <bits/stdc++.h>
using namespace std;

void Main() {
  int a, b, c;
  cin >> a >> b >> c;
  cout << max(0, max(b, c) + 1 - a) << ' ' << max(0, max(a, c) + 1 - b) << ' ' << max(0, max(a, b) + 1 - c) << '\n';
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