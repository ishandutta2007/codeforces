#include <bits/stdc++.h>

using namespace std;

int main() {
  int s;
  cin >> s;
  int a, b, c;
  cin >> a >> b >> c;
  if (a + b + c == 0) {
    cout << 0 << " " << 0 << " " << 0 << endl;
    return 0;
  }
  double res = (double)s / (a + b + c);
  printf("%0.17f %0.17f %0.17f", res * a, res * b, res * c);
  return 0;
}