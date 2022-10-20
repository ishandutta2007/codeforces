#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  if (n < 1200) {
    cout << 1200 << endl;
  } else if (n < 1400) {
    cout << 1400 << endl;
  } else if (n < 1600) {
    cout << 1600 << endl;
  } else if (n < 1900) {
    cout << 1900 << endl;
  } else if (n < 2100) {
    cout << 2100 << endl;
  } else if (n < 2300) {
    cout << 2300 << endl;
  } else if (n < 2400) {
    cout << 2400 << endl;
  } else if (n < 2600) {
    cout << 2600 << endl;
  } else cout << 3000 << endl;
  return 0;
}