#include <bits/stdc++.h>
using namespace std;

int main() {
      int a, b, c, d;
      cin >> a >> b >> c >> d;
      vector<bool> s(100000, 0);
      for (int i = b; i < 100000; i += a) {
            s[i] = 1;
      }
      for (int i = d; i < 100000; i += c) {
            if (s[i]) {cout << i; return 0;}
      }
      cout << -1; return 0;
      
}