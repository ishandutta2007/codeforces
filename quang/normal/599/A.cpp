#include <bits/stdc++.h>

using namespace std;

int main() {
  int x , y, z;
  cin >> x >> y >> z;
  int res = x + y + z;
  res = min(res, (x + y) * 2);
  res = min(res, (y + z) * 2);
  res = min(res, (x + z) * 2);
  cout << res << endl;
  return 0;
}