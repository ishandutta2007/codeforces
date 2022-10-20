#include <bits/stdc++.h>

using namespace std;

int main() {
  int a, b;
  scanf("%d %d", &a, &b);
  int c = 0;
  while (b) {
    c = c * 10 + b % 10;
    b /= 10;
  }
  cout << a + c;
  return 0;
}