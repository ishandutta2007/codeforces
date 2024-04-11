#include <bits/stdc++.h>

using namespace std;

int main() {
  long long a;
  cin >> a;
  long long b = (a - 1) * 3 + 1;
  b = b * (b + 1) / 2;
  long long c = a - 1;
  c = c * (c + 1) * 3 / 2;
  cout << b + c << endl;
  return 0;
}