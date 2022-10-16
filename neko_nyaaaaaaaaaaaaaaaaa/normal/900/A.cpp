#include <bits/stdc++.h>
using namespace std;

int main() {
      long long n, x, y, mi = 0, pl = 0;
      cin >> n;
      while (cin >> x >> y) {
            if (x > 0) {
                  pl++;
            } else {mi++;}
            if (pl > 1 && mi > 1) {cout << "no"; return 0;}
      }
      cout << "yes";
}