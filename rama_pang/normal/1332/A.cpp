#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int x[3], y[3];
    for (int i = 0; i < 3; i++) {
      cin >> x[i] >> y[i];
    }
    if (x[1] == x[2]) {
      if (a != 0 || b != 0) {
        cout << "NO\n";
        continue;
      }
    }
    if (y[1] == y[2]) {
      if (c != 0 || d != 0) {
        cout << "NO\n";
        continue;
      }
    }
    int xx = b - a;
    int yy = d - c;
    if (x[1] <= x[0] + xx && x[0] + xx <= x[2] && y[1] <= y[0] + yy && y[0] + yy <= y[2]) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
    
  }    

}