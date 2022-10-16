#include <bits/stdc++.h>
using namespace std;

int main() {
      
      int m; cin >> m;
      vector<int> s(m);
      if (m == 1) {cin >> m; cout << 1 << endl << m; return 0;}
      for (int i = 0; i < m; i++) {
            cin >> s[i];
      }
      int k = s[0];
      for (int i = 1; i < m; i++) {
            k = __gcd(k, s[i]);
      }
      if (k != s[0]) {cout << -1; return 0;}
      cout << 2*m << endl;
      for (int i = 0; i < m; i++) {
            cout << s[0] << " " << s[i] << " ";
      }
      
      return 0;
}