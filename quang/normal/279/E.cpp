#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  int a[2] = {0, 1};
  char b;
  while (cin >> b) {
    a[b < '1'] = min(a[0], a[1]) + 1;
  }
  cout << a[0];
  return 0;
}