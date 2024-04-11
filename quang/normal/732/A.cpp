#include <bits/stdc++.h>

using namespace std;

int main() {
  int k, r;
  cin >> k >> r;
  int val = k;
  for (int i = 1; i <= 10; i++) {
    if (val % 10 == r || val % 10 == 0) {
      cout << i << endl;
      return 0;
    }
    val += k;
  }
  return 0;
}