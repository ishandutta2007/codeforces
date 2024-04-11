#include <bits/stdc++.h>

using namespace std;

bool check(int u) {
  for (int i = 2; 1ll * i * i <= u; i++) {
    if (u % i == 0) {
      return 0;
    }
  }
  return 1;
}

int main() {
  int n;
  cin >> n;
  if (check(n)) {
    cout << 1 << endl;
    return 0;
  }
  if (n % 2 == 0) {
    cout << 2 << endl;
    return 0;
  }
  if (check(n - 2)) {
    cout << 2 << endl;
    return 0;
  }
  cout << 3 << endl;
  return 0;
}