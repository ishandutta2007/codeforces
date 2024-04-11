#include <bits/stdc++.h>

using namespace std;

int main() {
  int  n;
  cin >> n;
  if (n & 1) {
    cout << 0;
    return 0;
  }
  n /= 2;
  cout << (n - 1) / 2;
    return 0;
}