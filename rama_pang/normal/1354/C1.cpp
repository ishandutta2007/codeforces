#include <bits/stdc++.h>
using namespace std;
using lint = long long;


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  cout << fixed << setprecision(12);
  
  int T;
  cin >> T;
  while (T--) {
    const double pi = acos(-1);
    int n;
    cin >> n;
    if (n % 2 == 0) {
      n *= 2;
      double alpha = pi / n;
      double r = 1.00 / (2.00 * sin(alpha));
      double s = r * cos(alpha);
      cout << 2 * s << "\n";
    } else {
      n *= 2;
    }
  }
}