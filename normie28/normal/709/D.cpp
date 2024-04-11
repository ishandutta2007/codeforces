#include <bits/stdc++.h>
using namespace std;
int a, b, c, d, z, o;
long long com = 1;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
  cin >> a >> b >> c >> d;
  bool f = true;
  z = 2;
  while (com < a) {
    ++z;
    com = com * z / (z - 2);
  }
  if (a == 0) z = 1;
  else if (com != a) f = false;
  com = 1;
  o = 2;
  while (com < d) {
    ++o;
    com = com * o / (o - 2);
  }
  if (d == 0) o = 1;
  else if (com != d) f = false;
  if (f && z * o != c + b) {
    if (d == 0) --o;
    f = z * o == c + b;
    if (!f && a == 0) {
      --z;
      f = z * o == c + b;
    }
  }
  if (f && a + b + c + d != 0) {
    if (z > 0) {
      int k = (z * o - b);
      int pref = k / z;
      for (int i = 0; i < pref; ++i) cout << '1';
      o -= pref;
      b -= z * (o - 1);
      for (int i = 0; i < z; ++i) {
        if (b > 0 && i == b) {
          cout << '1';
          --o;
        }
        cout << '0';
      }
    }
    while (o--) cout << '1';
  } else if (a + b + c + d == 0) cout << '1';
  else cout << "Impossible";
}