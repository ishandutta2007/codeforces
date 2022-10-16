#include <bits/stdc++.h>
using namespace std;

signed main() {
      ios::sync_with_stdio(0); cin.tie(0);

      int x, y, z, t1, t2, t3;
      cin >> x >> y >> z >> t1 >> t2 >> t3;
      
      int w = abs(x - y)*t1;
      int e = abs(x - z)*t2 + abs(x - y)*t2 + t3*3;
      
      //cout << w << " " << e << endl;
      
      if (w < e) cout << "NO";
      else cout << "YES";

      return 0;
}