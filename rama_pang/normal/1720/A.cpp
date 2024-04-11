#include <bits/stdc++.h>
using namespace std;

void Main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  if (1ll * a * d == 1ll * b * c) {
    cout << "0\n";
    return;
  }
  if (a == 0 || c == 0) {
    cout << "1\n";
    return;
  }
  // a/c * x = b/d
  // x = b/d * c/a
  // x = bc/ad
  if (1ll * b * c % (1ll * a * d) == 0) {
    cout << "1\n";
    return;
  }
  if (1ll * a * d % (1ll * b * c) == 0) {
    cout << "1\n";
    return;
  }
  cout << "2\n";
  
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T = 1;
  cin >> T;
  while (T--) {
    Main();
  }
}