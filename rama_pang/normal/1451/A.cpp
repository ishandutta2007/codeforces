#include <bits/stdc++.h>
using namespace std;

void Main() {
  int n;
  cin >> n;
  if (n <= 3) {
    cout << n - 1 << "\n";
  } else if (n % 2 == 0) {
    cout << 2 << "\n";
  } else {
    cout << 3 << "\n";
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