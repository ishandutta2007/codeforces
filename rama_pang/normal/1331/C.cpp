#include <bits/stdc++.h>
using namespace std;

int main() {
  int a;
  cin >> a;

  int pos[6] = {0, 5, 3, 2, 4, 1}; // and they lived happily ever after
  int rev[6];
  for (int i = 0; i < 6; i++) {
    rev[pos[i]] = i;
  }

  int ans = 0;
  for (int j = 0; j < 6; j++) {
    if (a & (1 << j)) {
      ans |= (1 << (5 - rev[5 - j]));
    }
  }

  cout << ans << "\n";
  return 0;
}