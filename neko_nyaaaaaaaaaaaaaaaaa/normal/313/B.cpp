
 #include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
      
      string s;
      cin >> s;
      int n = s.size();
      vector<int> q(n);
      for (int i = 1; i < n; i++) {
            q[i] = q[i-1] + (s[i] == s[i-1]);
      }
      int m, x, y;
      cin >> m;
      while (m--) {
            cin >> x >> y;
            cout << (q[y-1] - q[x-1]) << endl;
      }
      
}