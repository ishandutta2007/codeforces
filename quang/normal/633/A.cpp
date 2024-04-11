#include <bits/stdc++.h>

using namespace std;

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  for (int i = 0; i * a <= c; i++) {
    int rest = c - i * a;
    if (rest % b == 0) {
      puts("Yes");
      return 0;
    }
  }
  puts("No");
  return 0;
}