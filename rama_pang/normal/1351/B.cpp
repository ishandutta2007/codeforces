#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int a1, b1, a2, b2;
    cin >> a1 >> b1 >> a2 >> b2;
    int yes = 0;

    if (a1 == a2 && b1 + b2 == a1) yes = 1;
    if (a1 == b2 && b1 + a2 == a1) yes = 1;
    if (b1 == a2 && a1 + b2 == b1) yes = 1;
    if (b1 == b2 && a1 + a2 == b1) yes = 1;
    
    if (yes) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}