#include <bits/stdc++.h>
using namespace std;

int main() {
      int n;
      cin >> n;
      
      if (n % 7 == 0) {
            cout << n/7 * 2 << " " << n/7 * 2;
      } else if (n % 7 == 1) {
            cout << n/7 * 2 << " " << n/7 * 2 + 1;
      } else if (n % 7 == 2) {
            cout << n/7 * 2 << " " << n/7 * 2 + 2;
      } else if (n % 7 == 6) {
            cout << n/7 * 2 + 1 << " " << n/7 * 2 + 2;
      } else {
            cout << n/7 * 2 << " " << n/7 * 2 + 2;
      }
      
      return 0;
}