#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  for (int i = 20; i >= 0; i--) {
    if (n & (1 << i)) {
      cout << i + 1 << " ";
    }
  }
  return 0;
}